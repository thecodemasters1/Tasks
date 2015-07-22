#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SUCCESS 0
#define INVALID_ARGUMENTS -1
#define CANT_OPEN_DICTIONARY_FILE -2
#define CANT_OPEN_TEXT_FILE -3
#define CANT_CLOSE_DICTIONARY_FILE -4
#define CANT_CLOSE_TEXT_FILE -5

void * stringMalloc(unsigned int size);
unsigned int getFileSize(FILE * f);
char * getFileContent(FILE * f, unsigned int * fsize_p);
char * getWord(char * content, unsigned int start_index, unsigned int contentSize, unsigned int * wordSize_p);
char * findSynonym(char * word, char * dictionary, unsigned int dictSize, unsigned int * synonymdSize_p);
unsigned int getLineStart(char * content, unsigned int currIndex);
int insensitiveStrCmp(char * str1, char * str2);
char * stoLower(char * string);

/*Summary: Get 2 files via the command line, first is dictionary and second is a file with text, replace 
words in the text that have a synonym in the dictionary file and save the new edited text file*/
int main(int argc, char * argv[])
{
	FILE * dictionary = NULL;
	FILE * text = NULL;

	unsigned int dictFileSize;
	unsigned int textFileSize;
	int returnValue = SUCCESS;

	char * fileText;
	char * dictText;

	unsigned int textFile_index = 0;

	if (argc != 3)
	{
		printf("Error %d: Invalid arguments. arguments' template: Dictionary : TEXT\n", INVALID_ARGUMENTS);
		return INVALID_ARGUMENTS;
	}

	/* Open dictionary file in order to get content */
	if (0 != fopen_s(&dictionary, argv[1], "r"))
	{
		printf("Error %d: Can't open dictionary file. Check file's location\n", CANT_OPEN_DICTIONARY_FILE);
		return CANT_OPEN_DICTIONARY_FILE;
	}

	/* Open text file in order to get content */
	if (0 != fopen_s(&text, argv[2], "r"))
	{
		printf("Error %d: Can't open text file. Check file's location\n", CANT_OPEN_TEXT_FILE);
		return CANT_OPEN_DICTIONARY_FILE;
	}
	
	/* Copy dictionaary content to memory */
	dictText = getFileContent(dictionary, &dictFileSize);

	/* Copy text content to memory */
	fileText = getFileContent(text, &textFileSize);

	/* Open text file again, this time in order to rewrite content */
	if (0 != freopen_s(&text, argv[2], "w", text))
	{
		printf("Error %d: Can't open text file. Check file's location\n", CANT_OPEN_TEXT_FILE);
		return CANT_OPEN_DICTIONARY_FILE;
	}
	while (textFile_index < textFileSize && fileText[textFile_index] != '\0')
	{
		printf("Working... %d%% completed.\n", (int)(((double)textFile_index / textFileSize) * 100));
		unsigned int Number_Of_Bytes = 0;
		unsigned int Size_Of_Synonym = 0;
		char * curr_word = getWord(fileText, textFile_index, textFileSize, &Number_Of_Bytes);
		char * synonym = findSynonym(curr_word, dictText, dictFileSize, &Size_Of_Synonym);
		if (synonym == NULL)
		{
			if (Number_Of_Bytes != 0)
			{
				fwrite(curr_word, sizeof(char), Number_Of_Bytes, text);
			}
			else
			{
				fwrite(&fileText[textFile_index], sizeof(char), sizeof(char), text);
			}
		}
		else
		{
			fwrite(synonym, sizeof(char), Size_Of_Synonym, text);
		}

		free(curr_word);
		textFile_index += max(Number_Of_Bytes, 1);
	}
	printf("Working... %d%% completed.\n", (int)(((double)textFile_index / textFileSize) * 100));

	printf("\nOld text file content: \n");
	printf("%s\n", fileText);
	printf("================================\n");

	/* Begin: Free Memory */
	free(dictText);
	free(fileText);
	/* End: Free memmory */

	if (0 != fclose(dictionary))
	{
		printf("Error %d: Can't close dictionary file.\n", CANT_CLOSE_DICTIONARY_FILE);
		returnValue = CANT_CLOSE_DICTIONARY_FILE;
	}

	if (0 != fclose(text))
	{
		printf("Error %d: Can't close text file.\n", CANT_CLOSE_TEXT_FILE);
		returnValue = CANT_CLOSE_TEXT_FILE;
	}

	if (returnValue == SUCCESS)
	{
		printf("Text was successfully modified.\n");
	}

	return returnValue;
}

/* void * stringMalloc(unsigned int size) summary
* allocating memory for a string, adding the '\0' to the end of the array
* param: unsigned int size | size of string without the '\0' char
*/
char * stringMalloc(unsigned int size)
{
	char * string;
	string = (char *)malloc(size+1);
	string[size] = '\0';
	return string;
}

/* unsigned int getFileSize(FILE * f) summary
* Get the size of file in bytes
* param: FILE * f | file to get size of
*/
unsigned int getFileSize(FILE * f)
{
	unsigned int ret_val;
	fseek(f, 0L, SEEK_END);
	ret_val = ftell(f);
	fseek(f, 0L, SEEK_SET);

	return ret_val;
}

/* char * getFileContent(FILE * f, unsigned int * fsize_p) summary
* Get the content of file and return it as a string
* param: FILE * f | file to get content of
* param: unsigned int * fsize_p | pointer of unsigned int to save file size in
*/
char * getFileContent(FILE * f, unsigned int * fsize_p)
{
	int resize_content = 0;
	char * ret_val;
	*fsize_p = getFileSize(f);
	ret_val = stringMalloc(*fsize_p);
	fread(ret_val, sizeof(char), *fsize_p, f);
	for (unsigned int i = 0; i < *fsize_p; i++)
	{
		if (ret_val[i] == '\n')
		{
			resize_content++;
		}
	}
	*fsize_p -= resize_content;
	ret_val[*fsize_p] = '\0';

	return ret_val;
}

/* char * getWord(char * content, unsigned int start_index, unsigned int contentSize, unsigned int * wordSize_p) summary
* Get a word from a string of content and return it as a string
* param: char * content | content to find a word in
* param: unsigned int start_index | index to start search word from
* param: unsigned int contentSize | content size
* param: unsigned int * wordSize_p | pointer of unsigned int to save word size in
*/
char * getWord(char * content, unsigned int start_index, unsigned int contentSize, unsigned int * wordSize_p)
{
	char * ret_val;
	*wordSize_p = 0;

	while (start_index + *wordSize_p < contentSize && isalpha(content[start_index + *wordSize_p]) != 0)
	{
		++(*wordSize_p);
	}

	ret_val = stringMalloc(*wordSize_p);

	for (unsigned int i = 0; i < *wordSize_p; ++i)
	{
		ret_val[i] = content[start_index + i];
	}

	return ret_val;
}

/* char * findSynonym(char * word, char * dictionary, unsigned int dictSize, unsigned int * synonymdSize_p) summary
* Get a word from a string of content and return it as a string
* param: char * word | word to find synonym of
* param: char * dictionary | string of dictionary to find synonym from
* param: unsigned int dictSize | dictionary size
* param: unsigned int * synonymSize_p | pointer of unsigned int to save synonym size in
*/
char * findSynonym(char * word, char * dictionary, unsigned int dictSize, unsigned int * synonymSize_p)
{
	char * synonym = NULL;
	unsigned int dictFile_index = 0;
	while (dictFile_index < dictSize && dictionary[dictFile_index] != '\0')
	{
		unsigned int Number_Of_Bytes = 0;
		char * curr_word = getWord(dictionary, dictFile_index, dictSize, &Number_Of_Bytes);
		if (strcmp(word, curr_word) == 0)
		{
			dictFile_index = getLineStart(dictionary, dictFile_index);
			synonym = getWord(dictionary, dictFile_index, dictSize, synonymSize_p);
			while (strcmp(curr_word, synonym) == 0)
			{
				dictFile_index += *synonymSize_p+1;
				synonym = getWord(dictionary, dictFile_index, dictSize, synonymSize_p);
			}
			break;
		}
		free(curr_word);
		dictFile_index += Number_Of_Bytes + 1;
	}

	return synonym;
}

/* unsigned int getLineStart(char * content, unsigned int currIndex) summary
* find the begining of a line in a string of file's content from a specific index
* param: char * content | content to find a lines in
* param: unsigned int currIndex | index to start search line start from
*/
unsigned int getLineStart(char * content, unsigned int currIndex)
{
	while (0 < currIndex && content[currIndex] != '\n')
	{
		--currIndex;
	}
	if (currIndex != 0)
		++currIndex;
	return currIndex;
}

/* int insensitiveStrCmp(char * str1, char * str2) summary
* Compare 2 strings without taking the letters state (uppercase/lowercase) in account, return 0 if same, <0 if str1 smaller, otherwise >0
* param: char * str1 | first string to compare
* param: char * str2 | second string to compare
*/
int insensitiveStrCmp(char * str1, char * str2)
{
	int ret_val;
	char * _str1;
	char * _str2;
	_str1 = stringMalloc(strlen(str1));
	_str2 = stringMalloc(strlen(str2));
	strcpy(_str1, str1);
	strcpy(_str2, str2);
	ret_val = strcmp(stoLower(_str1), stoLower(_str2));
	free(_str1);
	free(_str2);
	return ret_val;
}

/* char * stoLower(char * string) summary
* get a string, returns a lowercase version of it.
* param: char * string | string to lowercase.
*/
char * stoLower(char * string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		string[i] = tolower(string[i]);
		i++;
	}
	return string;
}