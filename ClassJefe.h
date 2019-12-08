struct Jefe{
	int x,y,reload,shoted,tdown,ydown,cdown,abzt,id;
	float t,x_,yf;
	int live;
	bool toright,indown,indown1,scape,abzb,created, firstA;
	Jefe(int _x, int _y):x(_x),y(_y),live(2),t(0){
		toright = true;
		reload = rand()%120;
		x_ = x;
		yf=y;
		shoted = 0;
		indown = false;
		indown1 = false;
		firstA = false;
		ydown = 4;
		cdown = 0;
		scape = false;
		tdown = 300 + rand()%400;
		abzb = false;
		abzt = 0;
	};
	
	void erase();
	void loop();
	void draw();
	void play();
};

void Jefe::erase(){
	gotoxy(x,y); printf("     ");
	gotoxy(x,y+1); printf("     ");
	gotoxy(x,y+2); printf("     ");
	
	if(abzb){
		gotoxy(x,y+3); printf("     ");
		gotoxy(x,y+4); printf("     ");
		gotoxy(x,y+5); printf("     ");
		gotoxy(x,y+6); printf("     ");	
	}
	
}

void Jefe::loop(){
	t += 0.5;

	// ---------------------------------

	tdown--;
	abzt++;
	int _r = J_RELOAD_2*(shoted==1);
	//float _v = 0;
	
	if(indown){
		// Arriba hacia abajo
		if(!abzb){
			if(indown1){
				yf+=0.4;
				y=yf;
				if(y>21){
					indown1 = false;
					cdown++;
					abzb = true;
					abzt = 0;
				}
			}else{
				yf-=0.4;
				y=yf;
				if(y<=ydown){
					indown = false;
					tdown = 300 + rand()%400;
				}
			}	
		}else{
			if(!firstA){
				firstA = true;
				abzb = false;
			}else if(abzt>35){
				abzb = false;
				abzt = 0;
				created = false;
				player.cantmove = true;
			}else{
				if(player.x +2 >= x && player.x <= x+4 && player.cantmove && firstA){
					PlayerCorrupt* a = NULL;
					player.cantmove = false;
					if(!created){
						created = true;
						player.timed = 0;
						player.l --;
						player.live = 3;
						a =	lst_playerCo.add(player.x,player.y);
						a->tdown = 1;
						a->ydown = ydown;
					}
				}
			}
		}
		
	}else{
		// Movimiento normal
		float _v = J_SPEEP_1*(shoted==0) + J_SPEEP_2*(shoted==1);
		
		if(toright)x_+=_v;
		else x_-=_v;
		
		x = x_;

		if(x>60-6){
			toright = false;
		}else if(x<22){
			toright = true;
		}
	}
	
	// Contador de Movimiento abajo
	if(tdown==0){
		indown = true;
		indown1 = true;
	}
	// -----------------------------------
	
	reload++;
	if(!indown && shoted!=0){
		if(reload > _r - LVL){
			lst_bullet.add(x+2, y+1, 2);
			reload = 0;	
			
		}
			
	}
}

void Jefe::draw(){
	if(abzb && firstA) drw_abduzcan(x,y+3,t);
	drw_Jefe(x,y,t,shoted,indown);
}

void Jefe::play(){
	erase();
	loop();
	if(live>0) draw();
}


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------



struct LstJefe{ // Lista de Abispas
	int len;
	Jefe* array[20];
	LstJefe():len(20){
		
		for(int i=0; i<20; i++){
			array[i] = NULL;
		}
	};
	
	void play();
	//void resize(int);
	Jefe* add(int,int,int);
	void clear();
	Jefe* get(int);
	void free();
};

Jefe* LstJefe::get(int i){
	return array[i];
}

void LstJefe::play(){
	for(int i=0; i<len; i++){
		if(array[i]!=NULL) array[i]->play();
	}
}

//void LstJefe::resize(int i){
//	if(i!=len){
//		len = i;
//		array = (Jefe**)realloc(array,(len)*sizeof(Jefe*));
//	}
//}

Jefe* LstJefe::add(int x, int y, int _w=1){
	bool agregado = false;
	for(int i=0;i<len;i++){
		if(array[i] == NULL){
			COMDS++;ENEMYS++;
			array[i] = new Jefe(x,y);
			array[i]->id = i;
			agregado = true;
			return array[i];
			break;
		}
	}
	
	//if(!agregado){
	//	COMDS++;ENEMYS++;
	//	resize(len +1);
	//	array[len-1] = new Jefe(x,y);
	//	array[len-1]->id = len-1;
	//	return array[len-1];
	//}
}

void LstJefe::clear(){
	ENEMYS -= COMDS;
	COMDS = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			array[i]->erase();
			delete array[i];
			array[i] = NULL;
		}
	}
	//resize(1);
}

void LstJefe::free(){
	int id_ = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			if((array[i]->live) <= 0){
				lst_explosion.add(array[i]->x,array[i]->y);
				lst_explosion.add(array[i]->x+2,array[i]->y);
				COMDS--;
				ENEMYS--;
				array[i]->erase();
				delete array[i];
				array[i] = NULL;
				SCORE+=400;
			}	
		}
	}
	//for(int i=0;i<len;i++){
	//	if(get(i)!=NULL) id_ = i;
	//}
	//resize(id_+1);
}
