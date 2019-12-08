void menu_select_color(int a, int b){
	if(a == b) setcolor(C_SELECT);
	else setcolor(C_RESET);
}

int menu(){
	int select = 1;
	float t = 0;
	int _x = 37, _y = 22;
	draw_border();

	setcolor(0x0c);
	draw_logo(32,4);
	
	setcolor(0x08);
	gotoxy(31,27); printf("[SPACE] Seleccionar");
	
	setcolor(C_RESET);
	player.l = 4; // Iniciar La vida del jugador
	player.tshot = 1;
	player.live = 3;
	SCORE = 0;
	AC_SCORE = 0;
	
	while(1){
		t++;
		loop_key(); // Loop de teclado

		gotoxy(_x, _y); menu_select_color(1, select); printf(" Jugar ");
		gotoxy(_x-3, _y+1); menu_select_color(2, select); printf(" Instrucciones ");
		gotoxy(_x-1, _y+2); menu_select_color(3, select); printf(" Creditos ");
		gotoxy(_x, _y+3); menu_select_color(4, select); printf(" Salir ");

		select += -(UP==KEY) +(DOWN==KEY);

		if(select < 1) select = 4;
		else if(select >4) select = 1;

		if(KEY == SPACE) break;

		Sleep(SLEEPTIME); // Control de frames por segundo
	}

	clearboard();
	return select;
}
