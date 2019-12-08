int matrix_logo[17][18] = {
{32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32},
{32 ,32 ,32 ,219,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,219,32 ,32 ,32 ,32},
{32 ,32 ,219,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,32 ,219,32 ,32 ,32},
{32 ,32 ,219,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,32 ,219,32 ,32 ,32},
{32 ,219,32 ,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,32 ,32 ,219,32 ,32},
{32 ,219,32 ,32 ,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,32 ,219,32 ,32},
{219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,219,219,32},
{219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,219,219,32},
{219,219,219,32 ,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,219,219,219,32},
{219,219,219,32 ,32 ,32 ,32 ,32 ,219,219,32 ,32 ,32 ,32 ,219,219,219,32},
{219,219,219,219,32 ,32 ,32 ,32 ,219,32 ,32 ,32 ,32 ,219,219,219,219,32},
{32 ,219,219,219,219,219,32 ,32 ,32 ,32 ,32 ,219,219,219,219,219,32 ,32},
{32 ,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,32 ,32},
{32 ,32 ,219,219,219,219,219,219,219,219,219,219,219,219,219,32 ,32 ,32},
{32 ,32 ,32 ,219,219,219,219,219,219,219,219,219,219,219,32 ,32 ,32 ,32},
{32 ,32 ,32 ,32 ,32 ,219,219,219,219,219,219,219,32 ,32 ,32 ,32 ,32 ,32},
{32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32}
};

void draw_border(){
	repeat(i,20,60){ gotoxy(i,0);printf("%c",205);}
	repeat(i,20,60){ gotoxy(i,29);printf("%c",205);}
	repeat(i,20,60){ gotoxy(i,2);printf("%c",205);}
	repeat(i,0,29){ gotoxy(20,i);printf("%c",186);}
	repeat(i,0,29){ gotoxy(60,i);printf("%c",186);}

	gotoxy(20,0); printf("%c",201);
	gotoxy(60,0); printf("%c",187);
	gotoxy(20,2); printf("%c",204);
	gotoxy(60,2); printf("%c",185);
	gotoxy(20,29); printf("%c",200);
	gotoxy(60,29); printf("%c",188);
	
}

void drw_Cship(int x, int y){
	
	setcolor(0x0c);
	gotoxy(x,y); printf("\\");
	gotoxy(x+2,y); printf("/");
	setcolor(0xfc);
	gotoxy(x,y+1); printf("\\",188);
	gotoxy(x+2,y+1); printf("/",200);
	setcolor(0x0f);
	gotoxy(x,y+2); printf(" | ");
	gotoxy(x+1,y); printf("%c",177);
	setcolor(C_RESET);
}

void drw_ship(int x, int y){
	setcolor(0x0f);
	gotoxy(x,y); printf(" %c ",202);
	gotoxy(x+1,y+1); printf("%c",177);
	setcolor(0xfc);
	gotoxy(x,y+2); printf("%c",188);
	gotoxy(x+2,y+2); printf("%c",200);
	setcolor(0x0c);
	gotoxy(x,y+1); printf("/");
	gotoxy(x+2,y+1); printf("\\");
	setcolor(C_RESET);
}

void drw_ship_void(int x, int y){
	gotoxy(x,y); printf(" %c ",176);
	gotoxy(x,y+1); printf("%c%c%c",176,176,176);
	gotoxy(x,y+2); printf("%c %c",176,176);
}

void drw_Abispa(int x, int y, int t){
	gotoxy(x,y);
	setcolor(0x0e);
	if(t%2 == 0)printf("\\ /");
	else printf("_ _");
	
	gotoxy(x,y+1); printf("%c %c",175,174);
	
	setcolor(0xe0);
	gotoxy(x+1,y+1); printf("X");
	setcolor(0x09);
	gotoxy(x,y+2); printf("%c^%c",218,191);
	setcolor(C_RESET);
}

void drw_Abispa_down(int x, int y, int t){
	gotoxy(x,y);
	if(t%2)setcolor(0x0e);
	else setcolor(0x0c);
	if(t%2 == 0)printf("\\ /");
	else printf("_ _");
	
	gotoxy(x,y+1); printf("%c %c",175,174);
	
	if(t%2)setcolor(0xe0);
	else setcolor(0xc0);
	gotoxy(x+1,y+1); printf("X");
	setcolor(0x09);
	gotoxy(x,y+2); printf("\\V/",218,191);
	setcolor(C_RESET);
}

void drw_Mariposa(int x, int y, int t,bool down_){

	setcolor(0x09);
	
	gotoxy(x+1,y+1); printf("%c",219);
	gotoxy(x+1,y+2); printf("%c",223);
	
	setcolor(0x0c);
	
	gotoxy(x+1,y); printf("Y");
	
	if(t%2 == 0 || down_){
		gotoxy(x,y); printf("%c",200);
		gotoxy(x+2,y); printf("%c",188);
		
		gotoxy(x,y+1); printf("%c",200);
		gotoxy(x+2,y+1); printf("%c",188);
	}else{
		gotoxy(x,y); printf("%c",201);
		gotoxy(x+2,y); printf("%c",187);
		
		gotoxy(x,y+1); printf("%c",201);
		gotoxy(x+2,y+1); printf("%c",187);
	}
	
	
	setcolor(0x04);
	if(!down_){
		gotoxy(x,y+2); printf("%c",218);
		gotoxy(x+2,y+2); printf("%c",191);	
	}else{
		gotoxy(x,y+2); printf("\\");
		gotoxy(x+2,y+2); printf("/");
	}
	

	setcolor(C_RESET);
}

void drw_Jefe(int x, int y, int t,int sh,bool down_){
	// 229 169
	if(sh == 0) setcolor(0x0b);
	else setcolor(0x0d);
	
	if(sh==1 && int(t*0.5)%2==0) setcolor(0x0f);
	
	if(!down_){
		gotoxy(x,y);printf(" %c %c ",201,187);
		gotoxy(x,y+1); printf("%c%c %c%c",201,188,200,187);
		gotoxy(x,y+2); printf("%c   %c",223,223);
	}else{
		gotoxy(x,y);printf("%c%c %c%c",201,205,205,187);
		gotoxy(x,y+1); printf("%c   %c",223,223);
	}
	
	setcolor(0x0a);
	
	if(!down_){
		gotoxy(x+2,y);printf("%c",229);
		gotoxy(x+2,y+1);printf("%c",169);
	}else{
		gotoxy(x+2,y);printf("%c",229);
		gotoxy(x+2,y+1);printf("%c",186);
		gotoxy(x+2,y+2);printf("%c",223);
	}
	
	setcolor(C_RESET);
}

void drw_abduzcan(int x, int y, int t){
	setcolor(0x0a);
	if(t%4 == 0){
		gotoxy(x,y); printf("%c%c%c%c%c",220,220,220,220,220);
		gotoxy(x,y+1); printf("%c%c%c%c%c",223,223,223,223,223);
		gotoxy(x,y+2); printf("%c%c%c%c%c",220,220,220,220,220);
		gotoxy(x,y+3); printf("%c%c%c%c%c",223,223,223,223,223);	
	}else if(t%4 == 1){
		gotoxy(x,y); printf("%c%c%c%c%c",219,219,219,219,219);
		gotoxy(x,y+2); printf("%c%c%c%c%c",219,219,219,219,219);
	}else if(t%4 == 2){
		gotoxy(x,y); printf("%c%c%c%c%c",223,223,223,223,223);
		gotoxy(x,y+1); printf("%c%c%c%c%c",220,220,220,220,220);
		gotoxy(x,y+2); printf("%c%c%c%c%c",223,223,223,223,223);
		gotoxy(x,y+3); printf("%c%c%c%c%c",220,220,220,220,220);
	}else if(t%4 == 3){
		gotoxy(x,y+1); printf("%c%c%c%c%c",219,219,219,219,219);
		gotoxy(x,y+3); printf("%c%c%c%c%c",219,219,219,219,219);
	}
	if(t%2)setcolor(0x0d);
	else setcolor(0xd0);
	gotoxy(x,y-1); printf("%c",178);
	gotoxy(x+4,y-1); printf("%c",178);
	setcolor(0x07);
}

void drw_Bullet(int x, int y, int t){
	setcolor(0x0f);
	gotoxy(x,y); printf("|");
	gotoxy(x,y+1);
	
	// 223 219 " " 
	
	if(t%3 == 0) setcolor(0x0e);
	if(t%3 == 1) setcolor(0x40);
	if(t%3 == 2) setcolor(0x07);
	
	if(t%4 == 0)printf("%c",176);
	if(t%2 == 1) printf("%c",177);
	if(t%4 == 2) printf("%c",178);

	setcolor(C_RESET);
}

void drw_bullet_abispa(int x, int y, int t){
	
	if(t%2 == 0) setcolor(0x0e);
	else setcolor(0xe0);
	
	gotoxy(x,y); printf("V");
	setcolor(0x0e);
	
	gotoxy(x,y-1);printf("|");
	
	setcolor(C_RESET);
}
void drw_bullet_jefe(int x, int y, int t){
	
	if(t%2 == 0) setcolor(0x0d);
	else setcolor(0x50);
	
	gotoxy(x,y); printf("W");
	gotoxy(x,y-1);printf("%c",186);
	
	setcolor(C_RESET);
}

void drw_bullet_mariposa(int x, int y, int t){
	
	if(t%2 == 0) setcolor(0x4f);
	else setcolor(0x0c);
	
	gotoxy(x,y); printf("V");
	gotoxy(x,y-1);printf("V");
	
	setcolor(C_RESET);
}

void drw_bullet_elvi(int x, int y, int t){
	
	if(t%2 == 0) setcolor(0xf4);
	else setcolor(0x0c);
	
	gotoxy(x,y); printf("|");
	
	if(t%2 == 1) setcolor(0xf4);
	else setcolor(0x0c);
	
	gotoxy(x,y-1);printf("|");
	
	setcolor(C_RESET);
}



void drw_explosion(int x, int y, int f){
	

	switch(f%3){
		case 0:
		setcolor(0x0e);
		gotoxy(x,y); printf("# #");
		gotoxy(x,y+1); printf(" . ");
		gotoxy(x,y+2); printf("# #");
		break;
			
		case 1:
		setcolor(0x04);
		gotoxy(x,y); printf("# #");
		gotoxy(x,y+1); printf(" # ");
		gotoxy(x,y+2); printf("# #");
		break;
			
		case 2:
		setcolor(0x07);
		gotoxy(x,y); printf(" # ");
		gotoxy(x,y+1); printf("# #");
		gotoxy(x,y+2); printf(" # ");
		break;
	}
	
	
	
	
	setcolor(C_RESET);
}

void draw_InitLvl(int x,int y, int t){
	if(t%3 == 0) setcolor(0x0a);
	if(t%3 == 1) setcolor(0x0d);
	if(t%3 == 2) setcolor(0x0f);
		
	gotoxy(x,y-2); printf("%c  ",219);
	gotoxy(x,y-1); printf("%c  ",219);
	gotoxy(x,y);   printf("%c%c%c",219,219,219);
		
	gotoxy(x+4,y-2); printf("%c %c",219,219);
	gotoxy(x+4,y-1); printf("%c %c",219,219);
	gotoxy(x+4,y);   printf(" %c ",219);
		
	gotoxy(x+8,y-2); printf("%c  ",219);
	gotoxy(x+8,y-1); printf("%c  ",219);
	gotoxy(x+8,y);   printf("%c%c%c",219,219,219);
	
	switch(LVL){
	case 1:
		gotoxy(x+12,y-2); printf(" %c ",219);
		gotoxy(x+12,y-1); printf(" %c ",219);
		gotoxy(x+12,y); printf(" %c ",219);
		break;
	case 2:
		gotoxy(x+13,y-2); printf("%c %c",219,219);
		gotoxy(x+13,y-1); printf("%c %c",219,219);
		gotoxy(x+13,y); printf("%c %c",219,219);
		break;
	case 3:
		gotoxy(x+13,y-2); printf("%c %c %c",219,219,219);
		gotoxy(x+13,y-1); printf("%c %c %c",219,219,219);
		gotoxy(x+13,y); printf("%c %c %c",219,219,219);
		break;
	case 4:
		gotoxy(x+13,y-2); printf("%c %c",219,219);
		gotoxy(x+13,y-1); printf("%c%c%c",219,219,219);
		gotoxy(x+13,y); printf("  %c",219);
		break;
	}

		
	gotoxy(x-2,y+2); printf("PRESS C TO CONTINUE");
	setcolor(0x07);


}

void draw_ScoreGetted(int x,int y, int t){
	if(t%3 == 0) setcolor(0x0d);
	if(t%3 == 1) setcolor(0x0c);
	if(t%3 == 2) setcolor(0x0e);
	
	//gotoxy(x-1,y-1); printf("YOU WIN THE LEVEL %d",LVL); 
	gotoxy(x,y);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(x,y+1);printf("%c              %c",219,219),
	gotoxy(x,y+2);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(x-1,y+3); printf("PRESS C TO CONTINUE");
	gotoxy(x+2,y+1);printf("SCORE: %d",SCORE);
	setcolor(0x07);
}

void draw_lost_live(int x, int y,int t,int c){
	setcolor(0x0f);
	gotoxy(x,y); printf(" %c  %c ",219,219);
	gotoxy(x,y+3); printf("%c    %c",219,219);
	gotoxy(x,y+2); printf(" %c%c%c%c ",220,220,220,220);

	setcolor(0x0b);
	gotoxy(x,y+1);
	if(c%3 == 0) printf(" %c  %c ",223,223);
	if(c%3 == 1) printf(" %c  %c ",220,220);
	if(c%3 == 2) printf("        ");

	if(t%2 == 0) setcolor(0x0c);
	if(t%2 == 1) setcolor(0xc0);

	gotoxy(x-2,y+5); printf("GAME OVER!");
	setcolor(0x08);
	gotoxy(x-4,y+6); printf("press c to exit");
	setcolor(0x07);
}

void draw_TimeOut(int x, int y,int t,int c){
	setcolor(0x0f);
	gotoxy(x,y+3); printf("%c     ",219,219);
	gotoxy(x,y+1); printf("      ");
	gotoxy(x,y+2); printf(" %c%c%c%c%c",220,220,220,220,223);

	gotoxy(x,y);
	if(c%5 == 0) printf(" %c  %c ",220,220);
	else printf(" %c  %c ",219,219);

	if(t%2 == 0) setcolor(0x0e);
	if(t%2 == 1) setcolor(0xe0);

	gotoxy(x-1,y+5); printf("TIME OUT");
	setcolor(0x08);
	gotoxy(x-5,y+6); printf("press c to retry");
	setcolor(0x07);
}

void draw_logo(int x, int y){
	for(int i=0;i<17; i++){
		for(int j=0; j<17; j++){
			gotoxy(x+j,y+i);
			printf("%c",matrix_logo[i][j]);
		}
	}
}

void draw_WIN(int x, int y,int t){
	if(t%3 == 0)setcolor(0x0f);
	if(t%3 == 1)setcolor(0x0c);
	if(t%3 == 2)setcolor(0x0d);
	
	gotoxy(x,y); printf("%c   %c",219,219);
	gotoxy(x,y+1); printf(" %c %c ",219,219);
	gotoxy(x,y+2); printf("  %c  ",219);
	gotoxy(x,y+3); printf("  %c  ",219);
	gotoxy(x,y+4); printf("  %c  ",219);
	x+=6;
	gotoxy(x,y); printf(" %c%c%c ",219,219,219);
	gotoxy(x,y+1); printf("%c   %c",219,219);
	gotoxy(x,y+2); printf("%c   %c",219,219);
	gotoxy(x,y+3); printf("%c   %c",219,219);
	gotoxy(x,y+4); printf(" %c%c%c ",219,219,219);
	x+=6;
	gotoxy(x,y); printf("%c   %c",219,219);
	gotoxy(x,y+1); printf("%c   %c",219,219);
	gotoxy(x,y+2); printf("%c   %c",219,219);
	gotoxy(x,y+3); printf("%c   %c",219,219);
	gotoxy(x,y+4); printf(" %c%c%c ",219,219,219);
	x-=10; y+=6;

	gotoxy(x,y); printf("%c   %c",219,219);
	gotoxy(x,y+1); printf("%c %c %c",219,219,219);
	gotoxy(x,y+2); printf("%c %c %c",219,219,219);
	gotoxy(x,y+3); printf("%c %c %c",219,219,219);
	gotoxy(x,y+4); printf(" %c %c ",219,219);
	x+=6;
	gotoxy(x,y); printf("%c",219);
	gotoxy(x,y+1); printf("%c",219);
	gotoxy(x,y+2); printf("%c",219);
	gotoxy(x,y+3); printf("%c",219);
	gotoxy(x,y+4); printf("%c",219);
	x+=2;
	gotoxy(x,y); printf("%c   %c",219,219);
	gotoxy(x,y+1); printf("%c%c  %c",219,219,219);
	gotoxy(x,y+2); printf("%c %c %c",219,219,219);
	gotoxy(x,y+3); printf("%c  %c%c",219,219,219);
	gotoxy(x,y+4); printf("%c   %c",219,219);
	

	x-=8;
	setcolor(0x08);
	gotoxy(x-1,y+6); printf("press c to exit");
	setcolor(0x07);
}
