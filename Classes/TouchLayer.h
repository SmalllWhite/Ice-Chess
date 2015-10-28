#ifndef __TOUCH_LAYER__
#define __TOUCH_LAYER__
#include "GameScene.h"
#include "cocos2d.h"
USING_NS_CC;
class TouchLayer : public cocos2d::Layer  
{
public :
	bool init();
	CREATE_FUNC(TouchLayer);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	//void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	//void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	//void onTouchCancel(cocos2d::Touch *touch, cocos2d::Event *event);
private:
	
};

#endif //!__TOUCH_LAYER__