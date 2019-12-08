void menu_select_color_instr(int a, int b){
	if(a == b) setcolor(0xe0);
	else setcolor(C_RESET);
}

void key(int a){
	if(a == DOWN) printf("[DOWN]");
	
	printf("[%c]",a);
}

int instruc(){
	int select = 0;
	int _x = 30, _y = 15;
	draw_border(); 
	while(1){
		loop_key(); // Loop de teclado

		gotoxy(_x-6, _y); menu_select_color_instr(1, select); printf("MoverNave: [KeyArrows] :: (< ^ v >)");
		gotoxy(_x-6, _y+1); menu_select_color_instr(2, select); printf("Disparar: [SPACE]");
		gotoxy(_x-6, _y+2); menu_select_color_instr(3, select); printf("OtrasOpciones: [C]");
		gotoxy(_x-2, _y+4); setcolor(0x08); printf("PRESS [SPACE] to exit");

		select += -(UP==KEY) +(DOWN==KEY);

		if(select < 1) select = 3;
		else if(select >3) select = 1;

		if(KEY == SPACE) break;

		Sleep(SLEEPTIME); // Control de frames por segundo
	}

	clearboard();
	return select;
	
}

int credits_(){
	int select = 0;
	int _x = 30, _y = 15;
	draw_border(); 
	while(1){
		loop_key(); // Loop de teclado

		gotoxy(_x-6, _y); menu_select_color_instr(1, select); printf("Grober Erison Gonzales De La Cruz");
		gotoxy(_x-6, _y+1); menu_select_color_instr(2, select); printf("Mario Giraldo");
		gotoxy(_x-6, _y+2); menu_select_color_instr(3, select); printf("Made in DevC++");
		gotoxy(_x-2, _y+4); setcolor(0x08); printf("PRESS [SPACE] to exit");

		select += -(UP==KEY) +(DOWN==KEY);

		if(select < 1) select = 3;
		else if(select >3) select = 1;

		if(KEY == SPACE) break;

		Sleep(SLEEPTIME); // Control de frames por segundo
	}

	clearboard();
	return select;
}
