#ifndef __GAME_SCENE__
#define __GAME_SCENE__

#include "cocos2d.h"
#include "public.h"
#include "GameLayer.h"
#include "TouchLayer.h"
#include "SimpleAudioEngine.h"
class GameScene : public cocos2d::Scene
{
public :
	bool init();
	static GameScene* create(int gamemode,int guan);
	
	//MOVE CHESS
	void passTouch();

	int gamemode;
	Animation* createAnimation(std::string prefixName, int framesNum, float delay);
	//listener
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	//Point numToPoint(int num);
	int guan;
private:
	//EventListenerCustom* _listener;
};



#endif // !__GAME_SCENE__