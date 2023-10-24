
// Lab 9 DS4Talker Skeleton Code
// ./ds4rd.exe -d 054c:09c -D DS4_BT -t -b -j -bt | ./lab9-1 wordslist.txt 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output
#define ARROW '<'
#define SPACE ' '




// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

void draw_character(int x, int y, char use);

void generate_list(char* wordlist[], int wordCount);



int main(int argc, char* argv[]) {
	char* wordslist[MAXWORDS];
	int wordCount;
	int i = 0;
	int row = 0;
	int column = 1;
	int time = 0;
	int moveTime = 0;
	int j1, j2, j3, j4;
	int rightClick, leftClick;
	int rOne, lOne, rTwo, lTwo;
	int option, share;
	int triangle, circle, x, square;
	int sentance[100000000];
	int length;
	int line = 20;
	wordCount = readWords(wordslist, argv[1]);
	int index = 0;
	
	//wordCount = trimws(wordlist);

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		// add code to print the words to the screen here for part 1
		for(i = 0; i < wordCount; ++i) {
			trimws(wordslist[i]);
			printf("%s\n", wordslist[i]);

		}
		
	
	}
	int rowCount = wordCount / 5;
	int oldTime = 0;
	
	if(wordCount % rowCount != 0) {
		rowCount ++;
	}
	
	initscr();
	refresh();
	noecho();
	
	generate_list(wordslist, wordCount);
	
	while(1) {
		
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,", &time, &triangle, &circle, &x, &square, &rightClick, &leftClick, &option, &share, &rTwo, &lTwo, &rOne, &lOne, &j1, &j2, &j3, &j4);
		
		if (time > moveTime + 200) { 
			 
			 //Down
			if (row > 0 && j2 < -100) { 
			draw_character(column * 15, row, SPACE);
			row --;
			draw_character(column * 15, row, ARROW);
			
			}
			
			//up
			if (row < rowCount && j2 > 100) {
			draw_character(column * 15, row, SPACE);
			row ++;
			draw_character(column * 15, row, ARROW);
			
			}
			
			//right
			if (column < 5 && j1 > 100) {
			draw_character(column * 15, row, SPACE);
			column ++;
			draw_character(column * 15, row, ARROW);
			
			}
			
			//left
			if (column > 1 && j1 < -100) {
			draw_character(column * 15, row, SPACE);
			column --;
			draw_character(column * 15, row, ARROW);
			
			}
			
			//space 
			if (triangle == 1) {
				index = ((column -1) * 16) + row;
				sentance[i] = (strlen(wordslist[index]) + 1);
				mvprintw(line, length, " %s", wordslist[index]);
				length += sentance[i];
				i++;
				
			}
			//remove last item
			if (x == 1) {
				int y;
				int z;
				int sentance_sum;
		
				sentance_sum = length - sentance[i-1];
				for (z = length; z >= sentance_sum; z--) {
					mvprintw(line, z, " ");
					
					
				}
				length = sentance_sum;
				i--;
			}
			
			//no space
			if (square == 1) {
				index = ((column -1) * 16) + row;
				sentance[i] = (strlen(wordslist[index]) + 1);
				mvprintw(line, length, "%s", wordslist[index]);
				length += sentance[i];
				i++;
			}
			
			//next line
			if (leftClick == 1) {
				line = line + 1;
			}
			
			//clear line
			if (rightClick == 1) {
				int x;
				for (x = 0; x < MAXWORDS; x ++) { 
				mvprintw(line, x, " ");
				}
				
				length = 0;
				
			}
			
			oldTime = time;
			refresh();
			moveTime = time;
			
		}
	}
	endwin();
	
	return 0;
}
			
			
			
			
	

// most of your code for part 2 goes here. Don't forget to include the ncurses library 

   
	


int readWords(char* wl[MAXWORDS], char* filename) {
	int numread = 0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");


	
while(!feof(fp)) {
	p = fgets(line, WORDLEN, fp);
	if (!feof(fp) && p != NULL) {
	trimws(line);
	wl[numread] = (char *) malloc(strlen(line)+1);
	strcpy(wl[numread], line);
	numread++;
}
}
fclose(fp);
return numread;
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

void draw_character(int x, int y, char use) { 
mvaddch(y,x,use);
refresh();
}

void generate_list(char* wordslist[], int wordCount) { 
int row;
int column;
int i = 0;

for (column = 0; column < 5; column++) {
		for (row = 0; row < 15; row++) {
				mvprintw(row, column * 15, "%15s", wordslist[i]);
				refresh();
				i++;
			if (i > wordCount -1) {
				break;
			}
		}
}
}
	


