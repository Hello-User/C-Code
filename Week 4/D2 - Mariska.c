/*
* Naam-Student1: Mariska van Beek
* Nummer-Student1: 19175337
* Naam-Student2: Tom van Renssen
* Nummer-Student2: 20118910
* Opdracht: D
* Bronnen: voor srand() en rand(): https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

char array[10][10] = {
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'}
	};
	
int x = 0, y = 0;
int next_x, next_y;
bool einde = false;
char letter = 65;		//65 is A in ascii

bool check_al_geprobeerd(int richting, int al_geprobeerd[4]);
bool is_geldig(int next_x, int next_y);
void print_array(void);



int main(void){
	srand(time(NULL)); 		//initialiseert de rand() functie
	array[x][y] = letter; 	//zet de letter A in het meest linksboven vak
	letter++;				//gaat naar de volgende letter in het alfabet
	
	while (!einde){
		bool geplaatst = false;
		int al_geprobeerd[4];
		int al_geprobeerd_index = 0;
		
		while (!geplaatst) {
			int richting = rand() % 5; //maakt een random getal tussen 0 en 5 dat aangeeft in welke richting er gekeken wordt vanaf de huidige locatie (x, y)
			if (check_al_geprobeerd(richting, al_geprobeerd) == false) { 	//controleert of de richting al uitgeprobeerd is
				switch (richting) {
					case 1:		//noord
						next_x = x;
						next_y = y-1;
						break;
					case 2:		//oost
						next_x = x + 1;
						next_y = y;
						break;
					case 3:		//zuid
						next_x = x;
						next_y = y+1;
						break;
					case 4:		//west
						next_x = x - 1;
						next_y = y;
						break;
				}
				if (is_geldig(next_x, next_y)) {	//controleert of de index van next_x en next_y niet buiten de array valt of een plek is waar al een letter staat
					x = next_x;
					y = next_y;
					array[x][y] = letter;		//plaatst de letter op index x,y
					letter++;					//gaat naar de volgende letter in het alfabet
					geplaatst = true;
					if (letter > 90) {			//90 is Z, dus als Z geweest is stopt de loop
						einde = true;
					}
				}
				else {
					al_geprobeerd[al_geprobeerd_index] = richting;		//zet de richting in een array met al geprobeerde richtingen
					al_geprobeerd_index++;								//doet de index 1 omhoog zodat het volgende element op die index in de array gezet kan worden
					if (al_geprobeerd_index == 4) {		//als dit 4 is, zijn alle 4 de richtingen geprobeerd zonder succes en moet het programma dus stoppen
						einde = true;
						geplaatst = true;
					}
				}
			}
		}
	}	
	print_array();
	return 0;
}

bool check_al_geprobeerd(int richting, int al_geprobeerd[4]) {		//kijkt of richting in een array met al geprobeerde richtingen staat
	for (int i=0; i<4; i++) {
		if (al_geprobeerd[i] ==  richting) {
			return true;
		}
	}
	return false;
}

bool is_geldig(int next_x, int next_y) {		//controleert of er op index next_x, next_y een letter neergezet kan worden
	if (next_x<0 || next_x>9 || next_y<0 || next_y>9) {		//kijkt of de index niet buiten de array valt
		return false;
	}
	if (array[next_x][next_y] != '.') {			//controleert of er niet al een letter staat
		return false;
	}
	return true;
}

void print_array(void) {		//gaat de array af en print ieder element
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			printf("%c ", array[j][i]);
		}
		printf("\n");
	}
}
