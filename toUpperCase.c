/******************************************************
* Daniel Bachler
* 1-27-16
* CS120
* toUpperCase.c
* 	Takes a file and prints its contents in uppercase
******************************************************/
#include <stdio.h> /*For file io and printing*/
#include <stdlib.h> /*For file io and printing*/
#include <ctype.h> /*Toupper*/

int main(int argc, char *argv[]) {
	FILE *fp1; /*Pointer to a file*/
	
	/*Checking if only 1 file was entered*/
	if(argc != 2) {
		printf("No filename supplied/to many files supplied");
		exit(EXIT_FAILURE);
	}
	/*Makes sure that file exists, and assigns it to fp1*/
	if((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("Specified file cannot be opened");
		exit(EXIT_FAILURE);
	}
	/*While file has chars, print that char in uppercase*/
	while(!feof(fp1)) {
		unsigned char input = getc(fp1);
		if(input != -1) {
			printf("%c", toupper(input));
		}
	}
	
	fclose(fp1); /*Closes file*/
	return 0;
}