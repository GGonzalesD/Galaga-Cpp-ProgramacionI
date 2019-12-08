struct Abispa{
	int x,y,reload,tdown,ydown,cdown,id;
	float t,x_,yf;
	int live;
	bool toright,indown,indown1,scape;
	Abispa(int _x, int _y):x(_x),y(_y),live(1),t(0){
		toright = true;
		reload = rand()%80;
		x_ = x;
		yf = y;
		tdown = 120;
		indown = false;
		indown1 = false;
		ydown = 12;
		cdown = 1;
		scape = false;
	};
	
	void erase();
	void loop();
	void draw();
	void play();
};

void Abispa::erase(){
	gotoxy(x,y); printf("   ");
	gotoxy(x,y+1); printf("   ");
	gotoxy(x,y+2); printf("   ");
}

void Abispa::loop(){
	t += 0.5;
	tdown--;
	
	if(indown){
		// Arriba hacia abajo
		if(indown1){
			yf+=0.2;
			y = yf;
			if(y>24){
				if(cdown >= M_MOVE_D){
					yf = 3;
				}else{
					indown1 = false;
					cdown++;
				}
			}
			if(y==11){
				yf+=2;
				indown1 = false;
				cdown = 0;
			}
			if(y+2 >= player.y  && x+2>=player.x && x<=player.x+2 && player.cantmove){
				player.live -= 3;
				live -= 3;
			}
		}else{
			yf-=0.2;
			y = yf;
			if(y<=ydown){
				indown = false;
				tdown = 120;
			}
		}
	}
	// Movimiento normal
	if(toright)x_+=0.35 + (0.05*LVL);
	else x_-=0.35 + (0.05*LVL);
	
	x = x_;

	if(x>60-4){
		toright = false;
	}else if(x<22){
		toright = true;
	}
	
	
	// Contador de Movimiento abajo
	if(tdown==0){
		indown = true;
		indown1 = true;
	}
	
	reload++;
	if(reload > 140 - LVL*2 && !indown){
		lst_bullet.add(x+1, y-1, 1);
		reload = 0;	
	}
	
}

void Abispa::draw(){
	if(indown) drw_Abispa_down(x,y,t*0.25);
	else drw_Abispa(x,y,t);
}

void Abispa::play(){
	erase();
	loop();
	if(live>0) draw();
}


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------



struct LstAbispa{ // Lista de Abispas
	int len;
	Abispa* array[20];
	LstAbispa():len(20){
		for(int i=0; i<20; i++){
			array[i] = NULL;
		}
	};
	
	void play();
	//void resize(int);
	Abispa* add(int,int,int);
	void clear();
	Abispa* get(int);
	void free();
};

Abispa* LstAbispa::get(int i){
	return array[i];
}

void LstAbispa::play(){
	for(int i=0; i<len; i++){
		if(array[i]!=NULL) array[i]->play();
	}
}

//void LstAbispa::resize(int i){
//	if(i!=len){
//		len = i;
//		array = (Abispa**)realloc(array,(len)*sizeof(Abispa*));
//	}
//}

Abispa* LstAbispa::add(int x, int y, int _w=1){
	bool agregado = false;
	for(int i=0;i<len;i++){
		if(array[i] == NULL){
			ENEMYS++;
			ABIPS++;
			array[i] = new Abispa(x,y);
			array[i]->id = i;
			agregado = true;
			return array[i];
			break;
		}
	}
	
	//if(!agregado){
	//	ENEMYS++;
	//	ABIPS++;
	//	resize(len +1);
	//	array[len-1] = new Abispa(x,y);
	//	array[len-1]->id = len-1;
	//	return array[len-1];
	//}
}

void LstAbispa::clear(){
	ENEMYS -= ABIPS;
	ABIPS = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			array[i]->erase();
			delete array[i];
			array[i] = NULL;
		}
	}
	//resize(1);
}

void LstAbispa::free(){
	int id_ = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			if((array[i]->live) <= 0){
				if(!array[i]->scape){
					lst_explosion.add(array[i]->x,array[i]->y);
					SCORE+=100;
				}else{
					
				}
				ABIPS--;
				ENEMYS--;
				array[i]->erase();
				delete array[i];
				array[i] = NULL;
			}	
		}
	}
	//for(int i=0;i<len;i++){
	//	if(get(i)!=NULL) id_ = i;
	//}
	//resize(id_+1);
}
