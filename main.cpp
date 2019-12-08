#include "includes.h"
#include "CodeReplace.h"
#include "constants.h"
#include "funConsole.h"
#include "dibujos.h"

#include "ClassExp.h"
#include "ClassBullet.h"
#include "ClassShip.h"
#include "ClassPlayerCorrupt.h"
#include "ClassAbispa.h"
#include "ClassMariposa.h"
#include "ClassJefe.h"

#include "Globals.h"

#include "menu.h"
#include "instructions.h"
#include "game.h"

//INITCODE

int main(){
	system("mode con: cols=84 lines=34");
	hidecursor();
	srand(time(NULL));
	int c;
	while(1){
		switch(menu()){
			case 1:
				
				do{
					SCORE = 0;
					LVL = 1;
					c = game();
				}while(c == 2);
				if(c == 0) break;
				AC_SCORE+=SCORE;
				
				
				do{
					SCORE = 0;
					LVL = 2;
					c = game();
				}while(c == 2);
				if(c == 0) break;
				AC_SCORE+=SCORE;
				

				do{
					SCORE = 0;
					LVL = 3;
					c = game();
				}while(c == 2);
				if(c == 0) break;
				AC_SCORE+=SCORE;
				
				do{
					SCORE = 0;
					LVL = 4;
					c = game();
				}while(c == 2);
				if(c == 0) break;
				AC_SCORE+=SCORE;
				
				
				break;
			case 2:
				instruc();
				break;
			case 3:
				credits_();
				break;
				
			case 4:	
				exit(0);
				break;
				
			default:
				printf("ERROR");
				break;
		}		
	}

}

