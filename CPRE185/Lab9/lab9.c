
// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

int main(int argc, char* argv[]) {
	FILE* infile;
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]);
	//wordCount = trimws(wordlist);

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		// add code to print the words to the screen here for part 1
		for(i = 0; i < wordCount; ++i) {
			trimws(wordlist[i]);
			printf("%s\n", wordlist[i]);

		}
	
	}

// most of your code for part 2 goes here. Don't forget to include the ncurses library 

    return 0;
	
}

int readWords(char* wl[MAXWORDS], char* filename) {
	FILE* infile = NULL;
	infile = fopen(filename, "r");
	int i = 0;
	

	
	
	while(!feof(infile)) {
		wl[i] = malloc(WORDLEN * sizeof(char));
		fscanf(infile, "%s", wl[i]);
		i += 1; 
	
	}
	fclose(infile);
	
	return i; 

}

void trimws(char* s){ 
	int num = strlen(s);
	int x;
	if(num == 0) return;
	x = num -1;
	while (isspace(s[x]) && (x>=0)) {
		s[x] = '\0';
		x--;
	}
}
	


