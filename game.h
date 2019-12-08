void show_ammon(int x, int y){
	gotoxy(x,y); printf("Ammon:[");
	setcolor(0x0e);
		switch(player.ammon){
			case 0:
				printf("%c%c%c",176,176,176);break;
			case 1:
				printf("%c%c%c",219,176,176);break;
			case 2:
				printf("%c%c%c",219,219,176);break;
			case 3:
				printf("%c%c%c",219,219,219);break;
		}
	setcolor(0x07);
	printf("]");
}

void kill_all(){
	lst_bullet.clear();
	lst_abispa.clear();
	lst_mariposa.clear();
	lst_jefe.clear();
	lst_playerCo.clear();
	lst_explosion.clear();
}

void show_lifes(){
	int y=24;
	int x=62;
	switch(player.l){
		case 1:
			drw_ship_void(x,y);
			drw_ship_void(x+4,y);
			drw_ship_void(x+8,y);
			break;
		case 2:
			drw_ship_void(x,y);
			drw_ship_void(x+4,y);
			drw_ship(x+8,y);
			break;
		case 3:
			drw_ship_void(x,y);
			drw_ship(x+4,y);
			drw_ship(x+8,y);
			break;
		case 4:
			drw_ship(x,y);
			drw_ship(x+4,y);
			drw_ship(x+8,y);
			break;
	}
}

void show_hearts(int x, int y){
	gotoxy(x,y); printf("hearts:[");
	setcolor(0x0c);
		switch(player.live){
			case 0:
				printf("%c%c%c",176,176,176);break;
			case 1:
				printf("%c%c%c",219,176,176);break;
			case 2:
				printf("%c%c%c",219,219,176);break;
			case 3:
				printf("%c%c%c",219,219,219);break;
		}
		setcolor(0x07);
	printf("]");
}
int TANDA = 0;

int TIME_TD = 0;
int CONT_TD1 = 0;
int CONT_TD2 = 0;
int CONT_TD3 = 0;
int CONT_TD4 = 0;

void generar(){
	//MARPS ABIPS COMDS= ENEMYS;
	
	if(TIME_TD>=105 && ENEMYS <3){
		TIME_TD = 0;
		TANDA++;
	}
	
	if(TIME_TD>10 && TIME_TD%15==0 && CONT_TD1<1+((LVL+1)/2) && TANDA ==1){
		Abispa* a_ = lst_abispa.add(42,4);
		Mariposa* b_ = lst_mariposa.add(42,4);
		
		CONT_TD1++;
		a_->tdown = 1;
		a_->toright = true;
		b_->tdown = 1;
		b_->toright = false;
	}
	
	if(TIME_TD%15==0 && CONT_TD2<2+((LVL+1)/2) && TANDA ==2){
		Jefe* a_ = lst_jefe.add(22,20);
		Mariposa* b_ = lst_mariposa.add(22,21);
		
		CONT_TD2++;
		a_->tdown = 1;
		a_->toright = true;
		b_->tdown = 1;
		b_->toright = true;
	}
	
	if(TIME_TD%15==0 && CONT_TD3<LVL+2 && TANDA ==3){
		Mariposa* b_ = lst_mariposa.add(56,22);
		
		CONT_TD3++;
		b_->tdown = 1;
		b_->toright = false;
	}
	
	if(TIME_TD%15==0 && CONT_TD4<2+LVL && TANDA ==4){
		Abispa* b_ = lst_abispa.add(42,4);
		
		CONT_TD4++;
		b_->tdown = 1;
		b_->toright = false;
	}
	
}

int game(){
	/*
		Funcion de juego
	*/
	
	srand(time(NULL));
	float t=0;
	int TIME_OUT = 0;
	
	if(player.l <= 0){
		player.l = 3;
		LIVE = 4;
		player.live = 4;
	}
	
	draw_border(); 

	player.x  = 38;
	player.y = 26;
	TANDA= 1;
	
	
	TIME = -1;
	
	
	while(1){
		loop_key();
		t++;
		
		if(t>10) draw_InitLvl(33,15,t*0.55);
		
		if(t>80 || KEY=='c') break;
		
		Sleep(SLEEPTIME);
	}
	clearboard();
	draw_border(); 
	

	while(player.l > 0 && !(SCORE>=2500 && ENEMYS==0) && ((TIME_GAME)-int(float(TIME)/30))>=0){
		TIME++;
		TIME_TD++;
		t++;
		TIME_OUT = TIME_GAME-int(float(TIME)/30);
		loop_key();
		
		generar();
		
		lst_abispa.play();
		lst_mariposa.play();
		player.play();
		lst_playerCo.play();
		lst_jefe.play();
		lst_explosion.play();
		lst_bullet.play();
		
		
		show_ammon(62,19);
		show_hearts(62,21);
		show_lifes();
		
		if(KEY == 'k'){
			player.l = 0;
			player.live = 0;
		}
		
		if(KEY == 'g'){
			SCORE +=2500;
			kill_all();
		}
		
		if(KEY == 'q'){
			player.live --;
		}
		
		if(KEY == 't'){
			TIME += 100;
		}
		// a e c
		if(SCORE >=2500) setcolor(0xa0);
		else setcolor(0x0c);
		gotoxy(21,1); printf("SCORE: %d",SCORE);
		
		if(TIME_OUT>=15 || SCORE >=2500) setcolor(0xa0);
		else if(TIME_OUT>=5){
			setcolor(0x0e);
			if(int(t*0.1)%2==0) setcolor(0xe0);
		}
		else{
			setcolor(0x0c);
			if(int(t*4)%2==0) setcolor(0xc0);
		}
		gotoxy(35,1); printf("TIME: %d ",n_maximo(TIME_OUT,0));
		
		setcolor(0x0e);
		gotoxy(48,1); printf("TOTAL: %d",AC_SCORE+SCORE);
		setcolor(0x07);
		
		
		for(int i=0;i<lst_bullet.len;i++){
			
			for(int j=0; j<lst_bullet.len; j++){
				if(lst_bullet.get(i)!=lst_bullet.get(j) && lst_bullet.get(j)!=NULL && lst_bullet.get(i)!=NULL)
				if(CollideB(lst_bullet.get(i), lst_bullet.get(j), 1	, 2) && CanCollideBullet(lst_bullet.get(i)->owner,lst_bullet.get(j)->owner)){
					lst_bullet.get(i)->alive = false;
					lst_bullet.get(j)->alive = false;
				}
			}
			
			for(int j=0;j<lst_abispa.len;j++){
				if(lst_bullet.get(i) != NULL && lst_abispa.get(j) != NULL)
				
				if(Collide(lst_bullet.get(i),lst_abispa.get(j),3,3) && lst_bullet.get(i)->killenemy()){
					lst_abispa.get(j)->live--;
					lst_bullet.get(i)->alive = false;	
				}
			
			}
			
			for(int j=0;j<lst_mariposa.len;j++){
				if(lst_bullet.get(i) != NULL && lst_mariposa.get(j) != NULL)
				if(Collide(lst_bullet.get(i),lst_mariposa.get(j),3,3) && lst_bullet.get(i)->killenemy()){
					lst_mariposa.get(j)->live--;
					lst_bullet.get(i)->alive = false;	
				}
			}
			
			for(int j=0;j<lst_playerCo.len;j++){
				if(lst_bullet.get(i) != NULL && lst_playerCo.get(j) != NULL)
				if(Collide(lst_bullet.get(i),lst_playerCo.get(j),3,3) && lst_bullet.get(i)->killenemy()){
					lst_playerCo.get(j)->live--;
					lst_bullet.get(i)->alive = false;	
				}
			}
			
			for(int j=0;j<lst_jefe.len;j++){
				if(lst_bullet.get(i) != NULL && lst_jefe.get(j) != NULL)
				if(Collide(lst_bullet.get(i),lst_jefe.get(j),5,2) && lst_bullet.get(i)->killenemy()){
					lst_jefe.get(j)->live--;
					lst_jefe.get(j)->shoted++;
					lst_bullet.get(i)->alive = false;	
				}
			}
			
			if(lst_bullet.get(i) != NULL){
				if(Collide(lst_bullet.get(i),&player,3,3) && lst_bullet.get(i)->killplayer()){
					if(player.cantmove){
						player.live--;
						lst_bullet.get(i)->alive = false;		
					}
					
				}
			}
		}
		
		

		Sleep(SLEEPTIME);
		
		lst_bullet.free();
		lst_abispa.free();
		lst_mariposa.free();
		lst_jefe.free();
		lst_playerCo.free();
		lst_explosion.free();
	}
	
	if(TIME_OUT <= 0 && SCORE<2500){
		player.l--; player.live = 3;
	}
	
	t=0;
	while(1){
		loop_key();
		t++;
		
		if(player.l<=0) draw_lost_live(37,12,t*0.5,t*0.1);
		else if(SCORE>=2500 && player.l > 0){
			if(LVL == 4) draw_WIN(31,10,t*0.45);
			else draw_ScoreGetted(32,15,t*0.55);
		}
		else{
			draw_TimeOut(37,12,t*0.5,t*0.05);
		}
		
		if(KEY == 'c') break;
		
		Sleep(SLEEPTIME);
	}
	
	// Resetear Variables del generador
	TIME_TD = 0;
	CONT_TD1 = 0;
	CONT_TD2 = 0;
	CONT_TD3 = 0;
	CONT_TD4 = 0;
	
	kill_all();
	
	clearboard();
	if(player.l <= 0){
		return 0;
	}else if(TIME_OUT <= 0 && SCORE<2500){
		return 2;
	}
	else{
		return SCORE>=2500;
	}
}
