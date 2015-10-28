#ifndef __START_SCENE__
#define __START_SCENE__
#include "cocos2d.h"
#include "GameLayer.h"
USING_NS_CC;
class StartScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StartScene);
	void menuCloseCallback1(float dt);
	void menuCloseCallback2(float dt);
	void transAnimation(cocos2d::Ref* pSender);
	void transAnimation2(cocos2d::Ref* pSender);
	void xuanguan(cocos2d::Ref* pSender);
};



#endif //!__START_SCENE__