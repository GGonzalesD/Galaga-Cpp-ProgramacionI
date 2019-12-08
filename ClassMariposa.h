struct Mariposa{
	int x,y,reload,tdown,ydown,cdown,id;
	float t,x_,yf;
	int live;
	bool toright,indown,indown1,scape;
	Mariposa(int _x, int _y):x(_x),y(_y),live(1),t(0){
		toright = true;
		reload = rand()%80;
		x_ = x;
		yf = y;
		tdown = 150;
		indown = false;
		indown1 = false;
		ydown = 8;
		cdown = 0;
		scape = false;
	};
	
	void erase();
	void loop();
	void draw();
	void play();
};

void Mariposa::erase(){
	gotoxy(x,y); printf("   ");
	gotoxy(x,y+1); printf("   ");
	gotoxy(x,y+2); printf("   ");
}

void Mariposa::loop(){
	t += 0.5;
	tdown--;
	
	if(indown){
		// Arriba hacia abajo
		if(indown1){
			yf+=0.3;
			y = yf;
			if(y>24){
				if(cdown >= M_MOVE_D){
					yf = 3;
				}else{
					indown1 = false;
					cdown++;
				}
			}
			if(y==7){
				yf+=2;
				indown1 = false;
				cdown = 0;
			}
			if(y+2 >= player.y  && x+2>=player.x && x<=player.x+2 && player.cantmove){
				player.live -= 3;
				live -= 3;
			}
		}else{
			yf-=0.3;
			y = yf;
			if(y<=ydown){
				indown = false;
				tdown = 100;
			}
		}
	}
	// Movimiento normal
	if(toright)x_+=0.4 + (0.05*LVL);
	else x_-=0.4 + (0.05*LVL);
	
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
	
	// Disparo
	reload++;
	if(reload > 140 - LVL*2){
		lst_bullet.add(x+1, y,3);
		reload = 0;	
	}
	
}

void Mariposa::draw(){
	drw_Mariposa(x,y,t*0.25,indown);
}

void Mariposa::play(){
	erase();
	loop();
	if(live>0) draw();
}


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------



struct LstMariposa{ // Lista de Mariposas
	int len;
	Mariposa* array[20];
	LstMariposa():len(20){
		
		for(int i=0; i<20;i++){
			array[i] = NULL;
		}
	};
	
	void play();
	//void resize(int);
	Mariposa* add(int,int,int);
	void clear();
	Mariposa* get(int);
	void free();
};

Mariposa* LstMariposa::get(int i){
	return array[i];
}

void LstMariposa::play(){
	for(int i=0; i<len; i++){
		if(array[i]!=NULL) array[i]->play();
	}
}

//void LstMariposa::resize(int i){
//	if(i!=len){
//		len = i;
//		array = (Mariposa**)realloc(array,(len)*sizeof(Mariposa*));
//	}
//}

Mariposa* LstMariposa::add(int x, int y, int _w=1){
	bool agregado = false;
	for(int i=0;i<len;i++){
		if(array[i] == NULL){
			ENEMYS++;
			MARPS++;
			array[i] = new Mariposa(x,y);
			array[i]->id = i;
			agregado = true;
			return array[i];
			break;
		}
	}
	
	//if(!agregado){
	//	ENEMYS++;
	//	MARPS++;
	//	resize(len +1);
	//	array[len-1] = new Mariposa(x,y);
	//	array[len-1]->id = len-1;
	//	return array[len-1];
	//}
}

void LstMariposa::clear(){
	ENEMYS -= MARPS;
	MARPS = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			array[i]->erase();
			delete array[i];
			array[i] = NULL;
		}
	}
//	resize(1);
}

void LstMariposa::free(){
	int id_ = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			if((array[i]->live) <= 0){
				ENEMYS--;
				MARPS--;
				if(!array[i]->scape){
					lst_explosion.add(array[i]->x,array[i]->y);
					SCORE+=160;
				}else{
					
				}
				
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
