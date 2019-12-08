struct PlayerCorrupt{
	int x,y,reload,tdown,ydown,cdown,id;
	float t,x_;
	int live;
	bool toright,indown,indown1,scape;
	PlayerCorrupt(int _x, int _y):x(_x),y(_y),live(1),t(0){
		toright = true;
		reload = rand()%80;
		x_ = x;
		tdown = 70 + rand()%100;
		indown = false;
		indown1 = false;
		ydown = y;
		cdown = 0;
		scape = false;
	};
	
	void erase();
	void loop();
	void draw();
	void play();
};

void PlayerCorrupt::erase(){
	gotoxy(x,y); printf("   ");
	gotoxy(x,y+1); printf("   ");
	gotoxy(x,y+2); printf("   ");
}

void PlayerCorrupt::loop(){
	t += 0.5;
	tdown--;
	
	if(indown){
		// Arriba hacia abajo
		if(indown1){
			if(y>24){
				indown1 = false;
			}else{
				y++;
			}
			if(y+2 >= player.y  && x+2>=player.x && x<=player.x+2 && player.cantmove){
				player.live -= 3;
				live -= 3;
			}
		}else{
			y--;
			if(y<=ydown){
				indown = false;
				tdown = 200 + rand()%120;
			}
		}
	}else{
		// Movimiento normal
		if(toright)x_+=0.8;
		else x_-=0.8;
	
		x = x_;

		if(x>60-4){
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
	
	// Disparo
	reload++;
	if(reload > 25 && !indown){
		lst_bullet.add(x+1, y,4);
		reload = 0;	
	}
	
}

void PlayerCorrupt::draw(){
	drw_Cship(x,y);
	//drw_PlayerCorrupt(x,y,t*0.25,indown);
}

void PlayerCorrupt::play(){
	erase();
	loop();
	if(live>0) draw();
}


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------



struct LstPlayerCorrupt{ // Lista de PlayerCorrupts
	int len;
	PlayerCorrupt* array[10];
	LstPlayerCorrupt():len(10){
		for(int i=0; i<10; i++){
			array[i] = NULL;
		}
	};
	
	void play();
	//void resize(int);
	void clear();
	PlayerCorrupt* add(int,int,int);
	PlayerCorrupt* get(int);
	void free();
} lst_playerCo;

PlayerCorrupt* LstPlayerCorrupt::get(int i){
	return array[i];
}

void LstPlayerCorrupt::play(){
	for(int i=0; i<len; i++){
		if(array[i]!=NULL) array[i]->play();
	}
}

//void LstPlayerCorrupt::resize(int i){
//	if(i!=len){
//		len = i;
//		array = (PlayerCorrupt**)realloc(array,(len)*sizeof(PlayerCorrupt*));
//	}
//}

PlayerCorrupt* LstPlayerCorrupt::add(int x, int y, int _w=1){
//	bool agregado = false;
	for(int i=0;i<len;i++){
		if(array[i] == NULL){
			ENEMYS++;
			PlayerCorrupt* a = new PlayerCorrupt(x,y);
			array[i] = a;
			array[i]->id = i;
		//	agregado = true;
			return a;
			break;
		}
	}
	
	//if(!agregado){
	//	ENEMYS++;
	//	resize(len +1);
	//	PlayerCorrupt* a = new PlayerCorrupt(x,y);
	//	array[len-1] = a;
	//	array[len-1]->id = len-1;
	//	return a;
	//}
}

void LstPlayerCorrupt::clear(){
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			ENEMYS--;
			array[i]->erase();
			delete array[i];
			array[i] = NULL;
		}
	}
	//resize(1);
}

void LstPlayerCorrupt::free(){
	int id_ = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			if((array[i]->live) <= 0){
				ENEMYS--;
				if(!array[i]->scape){
					lst_explosion.add(array[i]->x,array[i]->y);
				}else{
					
				}
				player.tshot++;
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
