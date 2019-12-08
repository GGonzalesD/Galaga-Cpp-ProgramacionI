struct Exp{
	int x,y;
	float t;
	Exp(int _x, int _y, int ty_=0):x(_x),y(_y),t(10){};
	
	void erase(); // Borra la pinche explocion
	void loop(); // Comportamiento de la chinche explocion
	void draw(); // Pinta la explocion
	void play();
};

void Exp::erase(){
	gotoxy(x,y); printf("   ");
	gotoxy(x,y+1); printf("   ");
	gotoxy(x,y+2); printf("   ");
}

void Exp::loop(){
	t -= 0.5;
	

	
	if(x>60-4){
		y-=3;
	}else if(x<22){
		y+=3;
	}
	
}

void Exp::draw(){
	drw_explosion(x,y,t*1.5);
}

void Exp::play(){
	erase();
	loop();
	if(t>0) draw();
}


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------



struct LstExp{ // Lista de explociones
	int len;
	Exp* array[30];
	LstExp():len(30){
		
		for(int i=0; i<30; i++){
			array[i] = NULL;
		}
	};
	
	void play(); // Ejecuta el comportamiento de las explociones
	//void resize(int);
	void add(int,int); // Agrega explociones
	void clear(); // Limpia toda la lista
	Exp* get(int); // Obtenert una explocion de la lista
	void free(); // Actualizar la lista
} lst_explosion;

Exp* LstExp::get(int i){
	return array[i];
}

void LstExp::play(){
	for(int i=0; i<len; i++){
		if(array[i]!=NULL) array[i]->play();
	}
}

//void LstExp::resize(int i){
//	if(i!=len){
//		len = i;
//		array = (Exp**)realloc(array,(len)*sizeof(Exp*));
//	}
//}

void LstExp::add(int x, int y){
	//bool agregado = false;
	for(int i=0;i<len;i++){
		if(array[i] == NULL){
			array[i] = new Exp(x,y);
			//agregado = true;
			break;
		}
	}
	
	//if(!agregado){
	//	resize(len +1);
	//	array[len-1] = new Exp(x,y);
	//}
}

void LstExp::clear(){
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			array[i]->erase();
			delete array[i];
			array[i] = NULL;
		}
	}
	//resize(1);
}

void LstExp::free(){
	int id_ = 0;
	for(int i=0;i<len;i++){
		if(array[i]!=NULL){
			if((array[i]->t) <= 0){
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
