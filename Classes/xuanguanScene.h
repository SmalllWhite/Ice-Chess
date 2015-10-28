#ifndef __XUANGUAN_SCENE__
#define __XUANGUAN_SCENE__
#include "cocos2d.h"
#include "TiaozhanLayer.h"
#include "StartScene.h"
USING_NS_CC;
class xuanguanScene:public Scene
{
public:
	CREATE_FUNC(xuanguanScene);
	bool init();
	bool onTouchBegan(Touch *touch, Event *event);
	void back(cocos2d::Ref* pSender);
	void tiaozhan(Ref* pSender,int i);
};




#endif //!__XUANGUAN_SCENE__