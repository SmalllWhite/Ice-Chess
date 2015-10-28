#include "StartScene.h"
#include "GameScene.h"
#include "xuanguanScene.h"
USING_NS_CC;
Scene* StartScene::createScene()
{
	auto scene=Scene::create();
	auto layer=StartScene::create();
	scene->addChild(layer);
	return scene;
}
bool StartScene::init()
{
	if(!Layer::init()){return false;}

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//最底层
	auto background=Sprite::create("background2.png");
	background->setPosition(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2);
	this->addChild(background,0);
	//第二层，动态泡泡
	ccBezierConfig bezier;
	ccBezierConfig bezier2;
	ccBezierConfig bezier3;
    bezier.controlPoint_1 = Vec2(0, visibleSize.height/2);
    bezier.controlPoint_2 = Vec2(300, -visibleSize.height/2);
    bezier.endPosition = Vec2(200,200);
	bezier2.controlPoint_1 = Vec2(visibleSize.width/2, 0);
    bezier2.controlPoint_2 = Vec2(-visibleSize.width/2, 250);
    bezier2.endPosition = Vec2(100,480);
	bezier3.controlPoint_1 = Vec2(0, visibleSize.height/2);
    bezier3.controlPoint_2 = Vec2(300, -visibleSize.height/2);
	bezier3.endPosition = Vec2(visibleSize.width+50,visibleSize.height/2-100);
	auto bezierForward1 = BezierBy::create(3, bezier);
    auto bezierBack1 = bezierForward1->reverse();
    auto seq1 = Sequence::create(bezierForward1, bezierBack1, nullptr);
    auto rep1 = RepeatForever::create(seq1);
	auto bezierForward2 = BezierBy::create(3, bezier2);
    auto bezierBack2 = bezierForward2->reverse();
    auto seq2 = Sequence::create(bezierForward2, bezierBack2, nullptr);
    auto rep2= RepeatForever::create(seq2);
	auto bezierForward3 = BezierBy::create(3, bezier3);
    auto bezierBack3 = bezierForward3->reverse();
	auto seq3 = Sequence::create(bezierForward3, bezierBack3, nullptr);
    auto rep3= RepeatForever::create(seq3);
	auto pao=Sprite::create("actionball1.png");
	pao->setPosition(Vec2(100,0));
	this->addChild(pao,1);
	pao->runAction(rep1);
	auto pao2=Sprite::create("actionball2.png");
	pao2->setPosition(Vec2(220,0));
	this->addChild(pao2,2);
	pao2->runAction(rep2);
	auto pao3=Sprite::create("actionball3.png");
	pao3->setPosition(Vec2(0,visibleSize.height/2));
	this->addChild(pao3,3);
	pao3->runAction(rep3);



   //第三层 球
	auto ball =Sprite::create("whiteball.png");
	ball->setPosition(origin.x+visibleSize.width/2,origin.y+visibleSize.height*3/4);
	auto rotateAction=CCRepeatForever::create(RotateBy::create(3.0f,360.0f));
	this->addChild(ball,10);
	ball->setTag(1);
	//ball->runAction(rotateAction);
	

	//第四层，按钮
	auto selectItem1=MenuItemImage::create("item1.png","item11.png",CC_CALLBACK_1(StartScene::transAnimation, this));
	auto selectItem2=MenuItemImage::create("item2.png","item22.png",CC_CALLBACK_1(StartScene::transAnimation2, this));
	auto selectItem3=MenuItemImage::create("item3.png","item33.png",CC_CALLBACK_1(StartScene::xuanguan, this));
	selectItem1->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+200));
	selectItem2->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+120));
	selectItem3->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+280));
	auto menu=Menu::create(selectItem1,selectItem2,selectItem3,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,5);
	menu->setTag(2);

		return true;

}
void StartScene::menuCloseCallback1(float dt)
{
	auto scene=GameScene::create(1,0);
	auto director = Director::getInstance();
	int i=1;
	director->replaceScene(scene);
}
void StartScene::menuCloseCallback2(float dt)
{
	auto scene=GameScene::create(2,0);
	auto director = Director::getInstance();
	director->replaceScene(scene);
}
void StartScene::transAnimation(Ref* pSender)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto fadein=FadeOut::create(1.5f);
	auto menu=this->getChildByTag(2);
	menu->runAction(fadein);

	auto ball=this->getChildByTag(1);
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	//auto moveeasein=EaseIn(moveto->clone(),0.5f);
	ball->runAction(moveto);
	auto rotate=RotateBy::create(30.0f,360.0f);
	auto rotateever=CCRepeatForever::create(rotate);
	ball->runAction(rotateever);

	scheduleOnce(schedule_selector(StartScene::menuCloseCallback1), 3.0f);
}
void StartScene::transAnimation2(Ref* pSender)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto fadein=FadeOut::create(1.5f);
	auto menu=this->getChildByTag(2);
	menu->runAction(fadein);

	auto ball=this->getChildByTag(1);
	auto moveto1=MoveTo::create(0.2f,Vec2(origin.x+visibleSize.width*0.25,origin.y+visibleSize.height/2));
	//auto moveeasein=EaseIn(moveto->clone(),0.5f);
	ball->runAction(moveto1);
	auto rotate=RotateBy::create(30.0f,360.0f);
	auto rotateever=CCRepeatForever::create(rotate);
	auto scaleto=ScaleBy::create(0.2f,0.5f);
	ball->runAction(rotateever);
	ball->runAction(scaleto);

	auto moveto2=MoveTo::create(0.2f,Vec2(origin.x+visibleSize.width*0.75,origin.y+visibleSize.height/2));
	auto ball2=Sprite::create("blackball.png");
	ball2->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height*3/4));
	auto fade=FadeIn::create(0.2f);
	ball2->runAction(rotateever->clone());
	ball2->runAction(fade);
	ball2->runAction(moveto2);
	ball2->runAction(scaleto->clone());
	this->addChild(ball2,6);




	

	scheduleOnce(schedule_selector(StartScene::menuCloseCallback2), 3.0f);
}
void StartScene::xuanguan(Ref* pSender)
{
	auto scene=xuanguanScene::create();
	auto director = Director::getInstance();
	director->replaceScene(scene);
}