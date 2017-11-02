#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void Reverse_String();
int captureWhiteSpaces(const char* someString, int len);
void captureBlockinTheString(const char* someString, char** blockarray);
char*  reverseNow(int wordcount, int len, char** blocks);
void sample(void);

int main()
{
	//Reverse_String("THIS IS TEXT");
	sample();

	return 0;
}

void Reverse_String(char* someText)
{

	int len = strlen(someText);
	printf("%s\n", (char*) someText);
	printf("Len=%d\n", len);
	printf("################################\n");
	const int whitespaces = (const int) captureWhiteSpaces( someText, len);
	int wordCount = whitespaces+1;


	printf("Whitespaces=[%d] \n", whitespaces);

	char* blocks[whitespaces+1];

	//memset(blocks, '\0', (sizeof(char)* (whitespaces+1)));

	printf("SIZE=%d\n",  sizeof(blocks));

	captureBlockinTheString(someText, blocks);
/*
	printf("%s\n", blocks[0]);
	printf("%s\n", blocks[1]);
	printf("%s\n", blocks[2]);
*/
	char* theString = reverseNow(wordCount, len, blocks);
	printf("%s\n", theString);
}
char*  reverseNow(int wordcount, int len, char** blocks)
{
	int count = wordcount;
	char* buff = (char*) malloc(len* sizeof(char));
	memset(buff, '\0', len* sizeof(char));

	while(count--)
	{
		strcat(buff,  blocks[count]);
		strcat(buff, " ");
	}
	return buff;
}

int captureWhiteSpaces( const char* someString, int len)
{
	int count = 0;
	int whitespaces = 0;
	const char* current_char = someString;

	while(count++ <= len)
	{
		if((char)*current_char == ' ')
		{
			whitespaces++;
		}
		else
		{
			if((char)*current_char == '\0')
			{
				break;
			}
		}
		current_char++;
	}
	return whitespaces;
}

void captureBlockinTheString(const char* someString, char** blockarray)
{
	int count = 0;
	int wordCount = 0;
	int internWhitespace = 0;
	const char* current_char = someString;

	char* buffer = (char*) malloc(40);
	memset(buffer, '\0', 32);

	while(count++ <= strlen(someString))
	{
		if((char)*current_char == ' ')
		{

			char* newBlock = (char*) malloc(wordCount);
			//strncat((char*)blockarray[internWhitespace], current_char, (size_t)wordCount);
			strncpy(newBlock, buffer, (size_t)wordCount);
			//blockarray[internWhitespace] = (char*) newBlock;
			blockarray[internWhitespace] = (char*) malloc(sizeof(char)*10);
			memset(blockarray[internWhitespace], '\0', sizeof(char)*10);
			strncpy((char*)blockarray[internWhitespace], newBlock, (size_t)wordCount+1);
			wordCount = 0;
			internWhitespace++;
			memset(buffer, '\0', 32);
			free( newBlock);
		}
		else
		{
			if((char)*current_char == '\0')
			{
				char* newBlock = (char*) malloc(wordCount);
				//strncat((char*)blockarray[internWhitespace], current_char, (size_t)wordCount);
				strncpy(newBlock, buffer, (size_t)wordCount);
				//blockarray[internWhitespace] = (char*) newBlock;
				blockarray[internWhitespace] = (char*) malloc(sizeof(char)*10);
				memset(blockarray[internWhitespace], '\0', sizeof(char)*10);
				strncpy((char*)blockarray[internWhitespace], newBlock, (size_t)wordCount+1);
				wordCount = 0;
				internWhitespace++;
				memset(buffer, '\0', 32);
				free( newBlock);
				break;
			}
			else
			{
				strncat(buffer, current_char, (size_t)sizeof(char));
				wordCount++;
			}
		}
		current_char++;
	}
}

void sample()
{
   char str[100], temp;
   int i, j = 0;

   printf("\nEnter the string :");
   gets(str);

   i = 0;
   j = strlen(str) - 1;

   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }

   printf("\nReverse string is :%s", str);
   return (0);
}
