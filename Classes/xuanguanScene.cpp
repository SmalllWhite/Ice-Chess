#include "xuanguanScene.h"
#include "GameScene.h"

bool xuanguanScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite=Sprite::create("background2.png");
	sprite->setPosition(visibleSize.width/2+origin.x,visibleSize.height/2+origin.y);
	this->addChild(sprite);
	
	auto back=MenuItemImage::create("tiaozhanback.png","tiaozhanback.png",CC_CALLBACK_1(xuanguanScene::back, this));
	back->setPosition(origin.x+72,origin.y+885);
	auto menu1=Menu::create(back,NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1);

	auto board=Sprite::create("tiaozhanscene.png");
	board->setPosition(origin.x+visibleSize.width/2,origin.y+0.9*visibleSize.height+20);
	this->addChild(board);

	auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=CC_CALLBACK_2(xuanguanScene::onTouchBegan,this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener,this);


	//นุ
	auto guanchu=MenuItemImage::create(
                                           "chuzhizhang.png",
                                           "chuzhizhang.png",
										   CC_CALLBACK_1(xuanguanScene::tiaozhan,this,1));

	guanchu->setPosition(origin.x+visibleSize.width/2,origin.y+750);
	auto guanhuo=MenuItemImage::create(
                                           "huozhizhang.png",
                                           "huozhizhang.png",
										   CC_CALLBACK_1(xuanguanScene::tiaozhan,this,7));
	guanhuo->setPosition(origin.x+visibleSize.width/2,origin.y+600);
	auto guanying=MenuItemImage::create(
                                           "yingzhizhang.png",
                                           "yingzhizhang.png",
										   CC_CALLBACK_1(xuanguanScene::tiaozhan,this,13));
	guanying->setPosition(origin.x+visibleSize.width/2,origin.y+450);
	auto guanmo=MenuItemImage::create(
                                           "mozhizhang.png",
                                           "mozhizhang.png",
										   CC_CALLBACK_1(xuanguanScene::tiaozhan,this,18));
	guanmo->setPosition(origin.x+visibleSize.width/2,origin.y+300);
	auto menu2=Menu::create(guanchu,guanhuo,guanying,guanmo,NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2);

	return true;
}
bool xuanguanScene::onTouchBegan(Touch *touch, Event *event){
	
	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	CCLOG("x is %d ,y is %d",x,y);
	int rectnum=0;

	return true;
}
void xuanguanScene::back(Ref* pSender )
{
	auto director = Director::getInstance();
	auto scene=StartScene::createScene();
	director->replaceScene(scene);
}
void xuanguanScene::tiaozhan(Ref * pSender,int i)
{
	auto scene=GameScene::create(3,i);
	auto director = Director::getInstance();
	director->replaceScene(scene);

}
