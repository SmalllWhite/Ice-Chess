#ifndef __CHESS__
#define __CHESS__

#include "cocos2d.h"
USING_NS_CC;

class Chess : public cocos2d::Node{
public:
	Chess();
	
	bool init();
	//CREATE_FUNC(Chess);
	static Chess* create(bool side,int id,int state,int color);

	CC_SYNTHESIZE(int ,_preState,PreState);
	CC_SYNTHESIZE(bool,_side,Side);
	CC_SYNTHESIZE(int,_id,Id);
	CC_SYNTHESIZE(int,_state,State);
	CC_SYNTHESIZE(bool,_touched,Touched);
	CC_SYNTHESIZE(bool,_deaded,Deaded);
	CC_SYNTHESIZE(bool,_dui,Dui);
	CC_SYNTHESIZE(int,_supercolor,SuperColor);
	CC_SYNTHESIZE(int,_delay,Delay);
	
	void someAction();
	void touchAction();
	void stopTouchAction();
	void initcolor();
	void updatecolor();
	Action *_blinkaciton;
	Node* _node;
	Sprite* _sprite;
private:
	
	
	
};




#endif //!__CHESS__