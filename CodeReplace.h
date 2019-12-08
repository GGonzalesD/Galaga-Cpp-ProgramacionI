#define repeat(iter,start_,end_) for(int iter=start_; iter<=end_; iter++)
#define Collide(obj1, obj2, w_	, h_) (((obj1)->x >= (obj2)->x && (obj1)->x < (obj2)->x+w_) && ((obj1)->y >= (obj2)->y && (obj1)->y<(obj2)->y+w_))
#define CollideB(obj1, obj2, w_	, h_) (((obj1)->x >= (obj2)->x && (obj1)->x < (obj2)->x+w_) && abs(((obj1)->y)-((obj2)->y))<=h_)
#define CanCollideBullet(a,b) ((a==0 && b>0)+(a>0 && b==0))
