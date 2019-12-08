struct Bullet{
	int x,y,id;
	float t,yf;
	bool alive;
	int owner;

	Bullet(int _x, int _y, int _ow=0): x(_x), y(_y), alive(true), owner(_ow),t(0){
		yf=y;
	};
	
	void erase();
	void loop();
	void draw();
	void play();
	bool killenemy();
	bool killplayer();
};


bool Bullet::killenemy(){
	return owner==0;
}

bool Bullet::killplayer(){
	return owner!=0;
}

void Bullet::erase(){
	if(owner == 0){
		gotoxy(x,y); printf(" ");
		gotoxy(x,y+1); printf(" ");	
	}else{
		gotoxy(x,y); printf(" ");
		gotoxy(x,y-1); printf(" ");	
	}
	
}

void Bullet::loop(){
	yf+= -1*(owner==0) + 1*(owner!=0);
	y = yf;
	
	if(y<=3 || y > 27){
		alive = false;
	}
	t+=0.2;
}

void Bullet::draw(){
	if(owner == 0) drw_Bullet(x,y,t*4);
	if(owner == 1) drw_bullet_abispa(x,y,t*2);
	if(owner == 2) drw_bullet_jefe(x,y,t*0.5);
	if(owner == 3) drw_bullet_mariposa(x,y,t);
	if(owner == 4) drw_bullet_elvi(x,y,t*3);
}

void Bullet::play(){
	erase();
	loop();
	if(alive) draw();
}




// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

struct LstBullet{ // Lista de balas
	int len;
	Bullet* array[45];
	LstBullet():len(45){
		
		for(int i=0; i<45; i++){
			array[i] = NULL;
		}
	};
	
	void play();
	//void resize(int);
	void clear();
	void add(int,int,int);
	Bullet* get(int);
	void free();
} lst_bullet;

Bullet* LstBullet::get(int i){
	return array[i];
}

void LstBullet::play(){
	for(int i=0; i<len; i++){
		if(array[i]!=NULL) array[i]->play();
	}
}

//void LstBullet::resize(int i){
//	if(i!=len){
//		//len = i;
//		array = (Bullet**)realloc(array,(len)*sizeof(Bullet*));
//	}
//}

void LstBullet::add(int x, int y, int _w=0){
	bool agregado = false;
	for(int i=0;i<len;i++){
		if(array[i] == NULL){
			array[i] = new Bullet(x,y,_w);
			array[i]->id = i;
			agregado = true;
			break;
		}
	}
	
	//if(!agregado){
	//	resize(len +1);
	//	array[len-1] = new Bullet(x,y,_w);
	//	array[len-1]->id = len-1;
	//}
}

void LstBullet::clear(){
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			array[i]->erase();
			delete array[i];
			array[i] = NULL;
		}
	}
	//resize(1);
}

void LstBullet::free(){
	int id_ = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			if(!array[i]->alive){
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


