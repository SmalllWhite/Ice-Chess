#include "TouchLayer.h"
#include "cocos2d.h"
#include "public.h"
#include "GameScene.h"
USING_NS_CC;
bool TouchLayer::init()
{
	if(!Layer::init()){
		return false;
	}
	auto listener=EventListenerTouchOneByOne::create();

	auto scene2=(GameScene*)this->getParent();
	//scene2->passTouch();
	listener->onTouchBegan=CC_CALLBACK_2(TouchLayer::onTouchBegan,this);
	//listener->onTouchEnded=CC_CALLBACK_2(TouchLayer::onTouchEnded,this);
	//listener->onTouchBegan=CC_CALLBACK_2(TouchLayer::onTouchBegan,this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	return true;
}
bool TouchLayer::onTouchBegan(Touch *touch, Event *event){
	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	CCLOG("x is %d ,y is %d",x,y);

	Rect rect=RECT_1;
	//rect.containsPoint(point)
	if(true){
		
		//_scene->touchChess();
	}
	return true;

}