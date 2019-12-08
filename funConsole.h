int SCORE = 0, TIME = 0;
int AC_SCORE = 0;


int LIVE = 0;

int MARPS = 0;
int ABIPS = 0;
int COMDS = 0;
int ENEMYS = 0;

int LVL = 1;

int n_maximo(int n1, int n2){
	if(n1 > n2) return n1;
	else return n2;
}

char KEY = '\0';
void loop_key(){ // CArgar una tecla
	KEY = '\0';
	if(kbhit()) KEY = getch();
}

// ------------------------------------------ Control de consola    --------------------------------------------------------------
char effect_load(int t){
	switch(t%4){
		case 0:
			return '|';
			break;
		case 1:
			return '/';
			break;
		case 2:
			return '-';
		case 3:
			return '\\';
			break;
		default:
			return ' ';
			break;
	}
	return ' ';
}

void setcolor(short f){
	HANDLE  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, f);
}

void hidecursor(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(h, &info);
}

void gotoxy(int x, int y){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(h,c);
}

void clearboard(){
	setcolor(C_RESET);
	system("cls");
	gotoxy(0,0);
}
