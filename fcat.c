/******************************************************
* Daniel Bachler
* 1-27-16
* CS120
* fcat.c
* 	Takes mulitple files from command line and prints them
*	at once 
******************************************************/
#include <stdio.h> /*File input and output*/
#include <stdlib.h> /*File input and output*/

int main(int argc, char *argv[]) {
	/*Declares file pointer, and the amount of files to print*/
	FILE *fp1 = NULL;
	int length = 0;
	/*exits if no files are given*/
	if(argc == 1) {
		exit(EXIT_FAILURE);
	}
	/*counts the amount of files, then subtracts one to account for the last value always being null*/
	while(argv[length] != NULL) {
		length++;
	}
	length--;
	/*For all files prints all chars within them*/
	while(length >= 1) {
		fp1 = fopen(argv[length], "r");
		while(!feof(fp1)) {
			int input = getc(fp1);
			unsigned char input1 = input;
			if(input != -1) {
				printf("%c", input1);
			}
		}
		length--;
	}
	
	fclose(fp1); /*Closes fp1*/
	return 0;
}