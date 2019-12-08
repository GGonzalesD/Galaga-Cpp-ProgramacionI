struct Ship{
	int x, y, reload,live, timed, tshot;
	int l, ammon, ammont;
	bool cantmove;

	Ship(int _x, int _y): x(_x), y(_y){
		reload = 0;
		live = 3;
		l = 4;
		ammon = 3;
		ammont = 0;
		tshot = 1;
		LIVE = l;
		cantmove = true;
		timed = 31;
	};

	void erase();
	void draw();
	void loop();
	void play();
	void init_destroy();
} player(38,26);

void Ship::init_destroy(){
	drw_explosion(x,y,0);
	Sleep(200);
	drw_explosion(x,y,1);
	Sleep(200);
	drw_explosion(x,y,2);
	Sleep(200);
	
	live=3;
	l--;
	
	erase();
	x = 38;
	y = 26;
}

void Ship::erase(){
	gotoxy(x,y); printf("   ");
	gotoxy(x,y+1); printf("   ");
	gotoxy(x,y+2); printf("   ");
}

void Ship::loop(){
	x -= (-(KEY==RIGHT) +(KEY==LEFT))*(cantmove);

	if(tshot<1) tshot = 1;
	if(tshot>3) tshot = 3;

	if(ammont > 15){
		ammont = 0;
		ammon++;
	}

	reload++;
	if(ammon != 3) ammont++;

	if(x<=L_L) x=L_L+1;
	if(x+2>=L_R) x=L_R-3;

	if(y<=3) y=3;
	if(y>=26) y=26;
	
	if(KEY == SPACE && ammon>0){
		if(reload > 3){
			if(tshot==1) lst_bullet.add(x +1, y, 0);
			if(tshot==2){
				lst_bullet.add(x, y, 0);
				lst_bullet.add(x+2, y, 0);
			}
			
			if(tshot==3){
				lst_bullet.add(x, y+1, 0);
				lst_bullet.add(x+1, y, 0);
				lst_bullet.add(x+2, y+1, 0);
			}
			ammon--;
			reload = 0;	
		}
			
	}

	if(live <= 0) init_destroy();
}

void Ship::draw(){
	drw_ship(x,y);
}

void Ship::play(){
	timed++;
	if(timed>30){
		erase();
		loop();
		draw();	
	}else if(timed==30){
		erase();
		x = 38;
		y = 26;
	}else{
		erase();
	}
	
}
