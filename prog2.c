/*in order to run you must provide command line arguments otherwise you will receive a segmentation fault error!  For example, to run from bash the command would be "./prg2 12 14" which would print out 12 lines that are 14 characters long.*/

//Name:  Robert Parson

#include <stdio.h> 
#include <stdlib.h>

char** RandCharGen(int width, int height);

int main(int argc, char *argv[])
{
	int i = 0;
	int width;
	int height;
	

	height = atoi(argv[1]);
	width = atoi(argv[2]);

	/*receiving the buffer,which contains randomly generated characters*/
	char **RandomText = RandCharGen(height,width);
	//printing contents of buffer
	printf("\n Randomly generated contents:\n");

	for(i;i<height;i++)
	{
		printf("\n%s",*(RandomText + i));
      		free(*(RandomText+i));
	}
	printf("\n\n");
	free(RandomText);
	return 0;
}

char** RandCharGen(int height, int width)
{
	int i,j;
	char **buff = malloc((height+1)*sizeof(char*));  //buffer for the size of characters
	
	for(i=0;i<height;i++)
	{
		buff[i] = malloc(width+1);

		for(j=0;j<width;j++)
		{
			//generating random charcters
			char randomChar = 'A' + (rand() % 26);
			//storing random chars in a buffer
			buff[i][j]=randomChar;
		}
		buff[i][width]='\0';
	}
	buff[height]=NULL;
	//returning buffer to main function
	return buff;
}