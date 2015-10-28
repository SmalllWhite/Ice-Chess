#include "TiaozhanLayer.h"
#include <vector>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "StartScene.h"
#include "Chess.h"
#include "Fire.h"
#include <time.h>

using namespace CocosDenshion;
USING_NS_CC;
#define CREATECHESS(__ID__,__SIDE__,__COLOR__) \
{ \
    auto chess=Chess::create(__SIDE__,__ID__,__ID__,__COLOR__); \
	Point point=numToPoint(__ID__); \
    chess->setPosition(point);\
	this->addChild(chess);\
	chessVec.push_back(chess);\
}
///////////////////////////////////////////////////////////////////////////

#define INITLISTENER(__TOUCH__)\
{\
	auto dispatcher = Director::getInstance()->getEventDispatcher();\
	dispatcher->removeAllEventListeners();\
    auto listener=EventListenerTouchOneByOne::create();\
    listener->onTouchBegan=CC_CALLBACK_2(TiaozhanLayer::__TOUCH__,this);\
    dispatcher->addEventListenerWithSceneGraphPriority(listener,this);\
}

/////////////////////////////////////////////////////////////////////////////
#define INITGUAN(__GUAN__)\
{\
	Size visibleSize = Director::getInstance()->getVisibleSize();\
    Vec2 origin = Director::getInstance()->getVisibleOrigin();\
    this->removeAllChildren();\
	auto qipan=Sprite::create("qipan9.png");\
    qipan->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));\
    this->addChild(qipan,0);\
	chessVec.clear();\
	myui();\
	thisSide=false;\
	_guan=__GUAN__;\
}
////////////////////////////////////
#define CREATESCALEANIMATION(__POINTNUM__,__PNG__)\
{\
	Point point=numToPoint(__POINTNUM__);\
    auto sprite=Sprite::create(__PNG__);\
	sprite->setPosition(point);\
	this->addChild(sprite);\
	auto Fade=FadeOut::create(2.0f);\
	auto Scale=ScaleTo::create(2.0f,2.0f);\
	sprite->runAction(Fade);\
    sprite->runAction(Scale);\
}

	
TiaozhanLayer* TiaozhanLayer::create(int guan) 
{ 
    TiaozhanLayer *pRet = new(std::nothrow) TiaozhanLayer(); 
    if (pRet) 
    { 
		pRet->_guan=guan;
		if(pRet->init()){
        pRet->autorelease(); 
		return pRet; }
		else{
		delete pRet; 
        pRet = NULL;
        return NULL; 
		}
    } 
    else 
    { 
        delete pRet; 
        pRet = NULL;
        return NULL; 
    } 
}


bool TiaozhanLayer::init()
{
	if(!GameLayer::init())
	{
		return false;
	}
	CCLOG("TIAOZHAN COMMING");
	this->removeAllChildren();
	numToInit(_guan);

	return true;

}
//带教程
bool TiaozhanLayer::init_1()
{   
	INITLISTENER(onTouchBegan3);
	INITGUAN(1);
	guidenum=1;
	//布置棋子
	
	CREATECHESS(1,false,0);
	CREATECHESS(2,false,0);
	CREATECHESS(4,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(3,true,0);
	guide(1);
	
	
	return true;
}
bool TiaozhanLayer::init_2()
{
	INITLISTENER(onTouchBegan3);
	INITGUAN(2);
	CREATECHESS(4,true,0);
	CREATECHESS(21,true,0);
	CREATECHESS(2,true,0);
    CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	
	guidenum=5;
	guide(5);
	return true;
}
bool TiaozhanLayer::init_3()
{
	INITLISTENER(onTouchBegan3);
	INITGUAN(3);
	guidenum=7;
	guide(7);
	CREATECHESS(5,true,0);
	CREATECHESS(9,true,0);
	CREATECHESS(11,true,0);
	CREATECHESS(10,true,0);
	CREATECHESS(18,true,0);
	CREATECHESS(14,true,0);
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);
	
	return true;
}
bool TiaozhanLayer::init_4()
{
	INITLISTENER(onTouchBegan3);
	INITGUAN(4);
	guidenum=9;
	guide(9);
	CREATECHESS(5,true,0);
	CREATECHESS(9,true,0);
	CREATECHESS(11,true,0);
	CREATECHESS(10,true,0);
	CREATECHESS(18,true,0);
	CREATECHESS(14,true,0);
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(3,false,0);
	
	return true;
}
bool TiaozhanLayer::init_5()
{
	INITLISTENER(onTouchBegan3);
	INITGUAN(5);
	guidenum=11;
	guide(11);
	CREATECHESS(1,true,0);
	CREATECHESS(2,true,0);
	CREATECHESS(4,true,0);
	CREATECHESS(16,true,0);
	CREATECHESS(10,false,0);
	CREATECHESS(19,false,0);
	CREATECHESS(13,false,0);
	CREATECHESS(3,false,0);
	CREATECHESS(15,false,0);
	
	return true;

}
bool TiaozhanLayer::init_6()
{
	INITLISTENER(onTouchBegan3);
	INITGUAN(6);
	guidenum=13;
	guide(13);
	CREATECHESS(5,true,0);
	CREATECHESS(11,true,0);
	CREATECHESS(9,true,0);
	CREATECHESS(10,true,0);
	CREATECHESS(18,true,0);
	CREATECHESS(14,true,0);
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	
	
	return true;

}
bool TiaozhanLayer::init_7()
{
	INITLISTENER(onTouchBegan4);
	INITGUAN(7);
	guidenum=0;
	fireVec.clear();
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);


	CREATECHESS(5,true,1);
	

	




	return true;
}
bool TiaozhanLayer::init_8()
{
    INITLISTENER(onTouchBegan4);
	INITGUAN(8);
	guidenum=0;
	fireVec.clear();
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);


	CREATECHESS(5,true,1);
	CREATECHESS(9,true,0);
	CREATECHESS(10,true,0);
	CREATECHESS(11,true,0);


	




	return true;
}
bool TiaozhanLayer::init_9()
{
	INITLISTENER(onTouchBegan4);
	INITGUAN(9);
	guidenum=0;
	fireVec.clear();

	CREATECHESS(10,true,1);
	CREATECHESS(5,true,1);
	
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);
	
	return true;
}
bool TiaozhanLayer::init_10()
{
	INITLISTENER(onTouchBegan4);
	INITGUAN(10);
	guidenum=0;
	fireVec.clear();

	CREATECHESS(21,true,1);
	CREATECHESS(20,true,1);
	CREATECHESS(12,true,1);
	
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(9,false,0);
	CREATECHESS(11,false,0);
	
	return true;
}
bool TiaozhanLayer::init_11()
{
	INITLISTENER(onTouchBegan4);
	INITGUAN(11);
	guidenum=0;
	fireVec.clear();

	CREATECHESS(1,false,0);
	CREATECHESS(2,false,0);
	CREATECHESS(3,false,0);
	CREATECHESS(4,false,0);
	CREATECHESS(5,true,1);
    CREATECHESS(6,true,1);
	CREATECHESS(7,true,1);
	CREATECHESS(8,true,1);

	addFire(10,10);
	addFire(13,13);
	addFire(19,19);
	addFire(16,16);
	return true;
}
bool TiaozhanLayer::init_12()
{
	INITLISTENER(onTouchBegan4);
	INITGUAN(12);
	guidenum=15;
	fireVec.clear();
	//
	{
	auto chess=Chess::create(true,21,21,2); 
	Point point=numToPoint(21); 
    chess->setPosition(point);
	this->addChild(chess);
	chessVec.push_back(chess);
	chess->setTag(21);}
	CREATECHESS(1,true,0);
	CREATECHESS(6,true,1);
	CREATECHESS(8,true,1);

	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(9,false,0);
	CREATECHESS(11,false,0);
	//
	//_firebreak=true;
	guide(15);
	thisSide=!thisSide;
	_firebreak=true;
	return true;
}
bool TiaozhanLayer::init_13()
{
	INITLISTENER(onTouchBegan5);
	INITGUAN(13);
	shadeVec.clear();
	shadeChessVec.clear();
	CREATECHESS(1,true,3);
	CREATECHESS(2,true,0);
	CREATECHESS(4,true,0);
	CREATECHESS(6,false,0);
	CREATECHESS(5,false,0);
	CREATECHESS(19,false,0);
	CREATECHESS(3,false,0);
	CREATECHESS(21,false,0);
	
	return true;
}
bool TiaozhanLayer::init_14()
{
	INITLISTENER(onTouchBegan5);
	INITGUAN(14);
	shadeVec.clear();
	shadeChessVec.clear();
	CREATECHESS(5,true,3);
	CREATECHESS(10,true,3);
	CREATECHESS(21,true,0);
	CREATECHESS(1,true,0);
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);
	
	return true;
}
bool TiaozhanLayer::init_15()
{
	INITLISTENER(onTouchBegan5);
	INITGUAN(15);
	shadeVec.clear();
	shadeChessVec.clear();
	CREATECHESS(1,true,3);
	CREATECHESS(2,true,3);
	CREATECHESS(3,true,3);
	CREATECHESS(4,true,3);
	CREATECHESS(13,false,0);
	CREATECHESS(6,false,0);
	CREATECHESS(14,false,0);
	CREATECHESS(12,false,0);
	CREATECHESS(18,false,0);
	CREATECHESS(8,false,0);
	CREATECHESS(19,false,0);
	CREATECHESS(20,false,0);
	return true;
}
bool TiaozhanLayer::init_16()
{
	INITLISTENER(onTouchBegan5);
	INITGUAN(16);
	shadeVec.clear();
	shadeChessVec.clear();

	CREATECHESS(8,true,0);
	CREATECHESS(4,true,0);
	CREATECHESS(2,true,0);
	CREATECHESS(6,true,0);
	CREATECHESS(9,true,3);
	CREATECHESS(11,true,3);

	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);

	return true;
}
bool TiaozhanLayer::init_17()
{
	INITLISTENER(onTouchBegan5);
	INITGUAN(17);
	guidenum=17;
	shadeVec.clear();
	shadeChessVec.clear();
    CREATECHESS(6,true,3);
	CREATECHESS(9,true,3);
	CREATECHESS(11,true,3);
	CREATECHESS(21,true,3);
	CREATECHESS(5,true,5);

	CREATECHESS(16,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(8,false,0);
	CREATECHESS(10,false,0);
	CREATECHESS(12,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(7,false,0);

	guide(17);
	return true;
}
bool TiaozhanLayer::init_18()
{
	INITLISTENER(onTouchBegan6);
	INITGUAN(18);

	CREATECHESS(21,true,6);
	

	CREATECHESS(2,false,0);
	CREATECHESS(4,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(15,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(11,false,0);
	CREATECHESS(9,false,0);
	CREATECHESS(14,false,0);
	CREATECHESS(12,false,0);
	CREATECHESS(18,false,0);
	CREATECHESS(20,false,0);
	return true;
}
bool TiaozhanLayer::init_19()
{
	INITLISTENER(onTouchBegan6);
	INITGUAN(19);

	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);
	CREATECHESS(5,true,6);
	CREATECHESS(9,true,0);
	CREATECHESS(11,true,0);
	
	return true;
}
bool TiaozhanLayer::init_20()
{
	INITLISTENER(onTouchBegan6);
	INITGUAN(20);
	CREATECHESS(1,false,0);
	CREATECHESS(2,false,0);
	CREATECHESS(3,false,0);
	CREATECHESS(4,false,0);
	CREATECHESS(21,false,0);

	CREATECHESS(5,true,6);
	CREATECHESS(7,true,6);
	CREATECHESS(6,true,0);
	CREATECHESS(8,true,0);

	return true;
}
bool TiaozhanLayer::init_21()
{
	INITLISTENER(onTouchBegan6);
	INITGUAN(21);
	//CREATECHESS(9,true,6);
	//CREATECHESS(11,true,6);
	CREATECHESS(5,true,6);
	//CREATECHESS(10,true,0);
	CREATECHESS(18,true,6);
	CREATECHESS(14,true,6);

	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);
	CREATECHESS(21,false,0);

	return true;
}
bool TiaozhanLayer::init_22()
{
	INITLISTENER(onTouchBegan6);
	INITGUAN(22);
	guidenum=19;
	guide(19);
	
	CREATECHESS(15,false,0);
	CREATECHESS(16,false,0);
	CREATECHESS(17,false,0);
	CREATECHESS(7,false,0);
	CREATECHESS(20,false,0);
	CREATECHESS(12,false,0);

	CREATECHESS(21,true,7);

	
	return true;
}
//tag 10~20为guide专用
void TiaozhanLayer::guide(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	switch(i)
	{
	case 1:
		if(guidenum==1)
		{
			auto guide1=Sprite::create("guide01.png");
			guide1->setPosition(Vec2(origin.x+320,origin.y+120));
			auto action1=MoveBy::create(0.8f,Vec2(0,10));
			auto action2=MoveBy::create(0.1f,Vec2(0,-10));
			auto action=CCRepeatForever::create(Sequence::create(action1,action2,nullptr));
			guide1->runAction(action);
			this->addChild(guide1);
			guide1->setTag(11);
			guidenum++;
			
		}
		break;
	case 2:
		if(guidenum==2)
		{
			this->removeChildByTag(11);
			auto guide=Sprite::create("guide03.png");
			guide->setPosition(Vec2(origin.x+320,origin.y+236));
			MoveBy* action21=MoveBy::create(0.8f,Vec2(0,10));
			MoveBy* action22=MoveBy::create(0.1f,Vec2(0,-10));
			Action* action20=CCRepeatForever::create(Sequence::create(action21,action22,nullptr));
			guide->runAction(action20);
			this->addChild(guide);
			guide->setTag(11);

			guidenum++;
		}
		break;
	case 3:
		if(guidenum==3)
		{
			this->removeChildByTag(11);
			auto guide=Sprite::create("guide02.png");
			guide->setPosition(Vec2(origin.x+320,origin.y+334));
			MoveBy* action21=MoveBy::create(0.8f,Vec2(0,10));
			MoveBy* action22=MoveBy::create(0.1f,Vec2(0,-10));
			Action* action20=CCRepeatForever::create(Sequence::create(action21,action22,nullptr));
			guide->runAction(action20);
			this->addChild(guide);
			guide->setTag(11);
			guidenum++;
		}
		break;
	case 4:
		if(guidenum==4)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 5:
		if(guidenum==5)
		{
			auto guide=Sprite::create("guide04.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}
		break;
	case 6:
		if(guidenum==6)
		{
		this->removeChildByTag(11);
		guidenum++;
		}
		break;
	case 7:
		if(guidenum==7)
		{
			auto guide=Sprite::create("guide05.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}
		break;
	case 8:
		if(guidenum==8)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 9:
		if(guidenum==9)
		{
			auto guide=Sprite::create("guide06.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}
		break;
	case 10:
		if(guidenum==10)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 11:
		if(guidenum==11)
		{
			auto guide=Sprite::create("guide07.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}
		break;
	case 12:
		if(guidenum==12)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 13:
		if(guidenum==13)
		{
			auto guide=Sprite::create("guide08.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}
		break;
	case 14:
		if(guidenum==14)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 15:
		if(guidenum==15)
		{
			auto guide=Sprite::create("guide09.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
			CCLOG("GUIDE 15");
		}break;
	case 16:
		if(guidenum==16)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 17:
		if(guidenum==17)
		{
			auto guide=Sprite::create("guide10.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}break;
	case 18:
		if(guidenum==18)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	case 19:
		if(guidenum==19)
		{
			auto guide=Sprite::create("guide11.png");
			guide->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
			this->addChild(guide,11);
			guide->setTag(11);
			guidenum++;
		}break;
	case 20:
		if(guidenum==20)
		{
			this->removeChildByTag(11);
			guidenum++;
		}
		break;
	default:break;
	}
}
bool TiaozhanLayer::onTouchBegan3(Touch *touch, Event *event){
	guide(6);
	guide(8);
	guide(10);
	guide(12);
	guide(14);
	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	CCLOG("x is %d ,y is %d",x,y);
	int rectnum=0;
	rectnum=whichRectContainsPoint(point);
	//CCLOG("rectnum is %d" ,rectnum);
	//rect.containsPoint(point)
    //是否让电脑走
	bool passside=false;

	if(rectnum){
		bool wuzi=true;
		auto it=chessVec.begin();
		for(auto it:chessVec){
			if(it->getState()==rectnum){
				if(!(it->getDeaded())){wuzi=false;currChess=it; break;}
			}
		}
		//CCLOG("CURRCHESS : %d",currChess?currChess->getId():0);
		if(wuzi)
		{
			CCLOG("WUZI");
			if(preChess)
			{
				
				int *q=stateToAround(preChess->getState()) ;
				//CCLOG("road are %d %d %d %d",q[0],q[1],q[2],q[3]);
				bool road=false;
				//for(int i=0;i<4;i++){
				//	if (q[i]==rectnum){road=true;break;}
				//	CCLOG("rectnum is %d,q[i] is %d",rectnum,q[i]);
				//}
				int a1=(int)q[0];
				int a2=(int)q[1];
				int a3=(int)q[2];
				int a4=(int)q[3];
				if((a1==rectnum)||(a2==rectnum)||(a3==rectnum)||(a4==rectnum)){
				road=true;
				}
			   // CCLOG(" %d %d %d %d",a1,a2,a3,a4);
			
				
				if(road){
			    preChessVec.clear();
				preChess->setPreState(preChess->getState());
				preChessVec.push_back(preChess);
				canhuiqi=true;

				preChess->touchAction();
				preChess->setState(rectnum);
				//CCLOG("RECTNUM IS %d",rectnum);
				Point point=numToPoint(rectnum);
				auto MoveTo=MoveTo::create(2,point);
				//preChess->runAction(MoveTo);
				preChess->setPosition(point);
				//转换side状态
				thisSide=!thisSide;
				//CCLOG("SET POSITION TO  %d",rectnum);
				//guide
				if(preChess->getState()==3)
				{
					guide(4);
				}
				if(preChess->getState()==16)
				{
					guide(3);
				}
				preChess=NULL;
				//停止音效，可以选择单独停掉一个音效，这个值是由playEffect返回的
SimpleAudioEngine::sharedEngine()->stopEffect(_soundId);
                //computer time
                passside=true;
				
                
				}
				else{
					preChess->touchAction();preChess=NULL;
				}
			}
			else 
			{}
		}
		else{
			if(preChess){
				if(currChess->getId()==preChess->getId())
				{
					preChess->touchAction();
					preChess=NULL;
				}
				//包含吃子部分
				else if(currChess->getSide()==preChess->getSide())
			
				{
					currChess->touchAction();
					preChess->touchAction();
					preChess=currChess;
				}
				else
				{
					if(preChess->getTouched()){
						preChess->touchAction();
					}
					preChess=NULL;
				}
			}
			else
			{
				if((currChess->getSide()==thisSide)&&(currChess->getSide()==false)){
				currChess->touchAction();
				preChess=currChess;
				guide(2);
				//开始播放背景音效，false表示不循环
               _soundId=SimpleAudioEngine::sharedEngine()->playEffect("touchsound2.mp3",false);}
			}
		}
	}
	else if(preChess)
	{
		preChess->touchAction();
		preChess=NULL;
	}
	//第一次检测死亡
	for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
	if(examineblackdead()){
		if(_guan==6){
		tongguan(1);
		}else{
			endScene_CHU(1);}return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	//computer time
	if(passside)
	{
		CCLOG("COMPUTER TIME!");
		blackSide();
		//第二次检测死亡
		for(auto it:chessVec)
	{
		it->setDui(false);
	}
		for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
		if(examinewhitedead()){endScene_CHU(2);return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	}else{}

	
	CCLOG("preChess id is %d", preChess?preChess->getId():0) ;
	

	

	return true;

}
bool TiaozhanLayer::onTouchBegan4(Touch *touch, Event *event){
	if((_guan==12)&&(_firebreak)){
		guide(16);
		firebreak();		
		thisSide=!thisSide;
		_firebreak=false;
		return true;
	}
	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	CCLOG("x is %d ,y is %d",x,y);
	int rectnum=0;
	rectnum=whichRectContainsPoint(point);
	//CCLOG("rectnum is %d" ,rectnum);
	//rect.containsPoint(point)
    //是否让电脑走
	bool passside=false;

	if(rectnum){
		bool wuzi=true;
		auto it=chessVec.begin();
		for(auto it:chessVec){
			if(it->getState()==rectnum){
				if(!(it->getDeaded())){wuzi=false;currChess=it; break;}
			}
		}
		//CCLOG("CURRCHESS : %d",currChess?currChess->getId():0);
		if(wuzi)
		{
			CCLOG("WUZI");
			if(preChess)
			{
				
				int *q=stateToAround(preChess->getState()) ;
				//CCLOG("road are %d %d %d %d",q[0],q[1],q[2],q[3]);
				bool road=false;
				//for(int i=0;i<4;i++){
				//	if (q[i]==rectnum){road=true;break;}
				//	CCLOG("rectnum is %d,q[i] is %d",rectnum,q[i]);
				//}
				int a1=(int)q[0];
				int a2=(int)q[1];
				int a3=(int)q[2];
				int a4=(int)q[3];
				if((a1==rectnum)||(a2==rectnum)||(a3==rectnum)||(a4==rectnum)){
				road=true;
				}
			   // CCLOG(" %d %d %d %d",a1,a2,a3,a4);
			
				
				if(road){
			    preChessVec.clear();
				preChess->setPreState(preChess->getState());
				preChessVec.push_back(preChess);
				canhuiqi=true;

				preChess->touchAction();
				preChess->setState(rectnum);
				//CCLOG("RECTNUM IS %d",rectnum);
				Point point=numToPoint(rectnum);
				auto MoveTo=MoveTo::create(2,point);
				//preChess->runAction(MoveTo);
				preChess->setPosition(point);
				//转换side状态
				thisSide=!thisSide;
				//CCLOG("SET POSITION TO  %d",rectnum);
				preChess=NULL;
				//停止音效，可以选择单独停掉一个音效，这个值是由playEffect返回的
SimpleAudioEngine::sharedEngine()->stopEffect(_soundId);
                //computer time
                passside=true;
				examineFireDead();
				
                
				}
				else{
					preChess->touchAction();preChess=NULL;
				}
			}
			else 
			{}
		}
		else{
			if(preChess){
				if(currChess->getState()==preChess->getState())
				{
					preChess->touchAction();
					preChess=NULL;
				}
				//包含吃子部分
				else if(currChess->getSide()==preChess->getSide())
			
				{
					currChess->touchAction();
					preChess->touchAction();
					preChess=currChess;
				}
				else
				{
					if(preChess->getTouched()){
						preChess->touchAction();
					}
					preChess=NULL;
				}
			}
			else
			{
				if((currChess->getSide()==thisSide)&&(currChess->getSide()==false)){
				currChess->touchAction();
				preChess=currChess;
				guide(2);
				//开始播放背景音效，false表示不循环
               _soundId=SimpleAudioEngine::sharedEngine()->playEffect("touchsound2.mp3",false);}
			}
		}
	}
	else if(preChess)
	{
		preChess->touchAction();
		preChess=NULL;
	}
	//第一次检测死亡
	
	for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
	if(examineblackdead()){
		if(_guan==12){
		tongguan(2);
		}else{
			endScene_HUO(1);}return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	//computer time
	if(passside)
	{
		CCLOG("COMPUTER TIME!");
		redSide();
		//第二次检测死亡
		for(auto it:chessVec)
	{
		it->setDui(false);
	}
		for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
		//fire
		cleanFire();

		if(examinewhitedead()){endScene_HUO(2);return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	}else{}

	CCLOG("preChess id is %d", preChess?preChess->getId():0) ;
	
	return true;

}
bool TiaozhanLayer::onTouchBegan5(Touch *touch, Event *event){
	guide(18);
	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	CCLOG("x is %d ,y is %d",x,y);
	int rectnum=0;
	rectnum=whichRectContainsPoint(point);
	//CCLOG("rectnum is %d" ,rectnum);
	//rect.containsPoint(point)
    //是否让电脑走
	bool passside=false;

	if(rectnum){
		bool wuzi=true;
		auto it=chessVec.begin();
		for(auto it:chessVec){
			if(it->getState()==rectnum){
				if(!(it->getDeaded())){wuzi=false;currChess=it; break;}
			}
		}
		//CCLOG("CURRCHESS : %d",currChess?currChess->getId():0);
		if(wuzi)
		{
			CCLOG("WUZI");
			if(preChess)
			{
				
				int *q=stateToAround(preChess->getState()) ;
				//CCLOG("road are %d %d %d %d",q[0],q[1],q[2],q[3]);
				bool road=false;
				//for(int i=0;i<4;i++){
				//	if (q[i]==rectnum){road=true;break;}
				//	CCLOG("rectnum is %d,q[i] is %d",rectnum,q[i]);
				//}
				int a1=(int)q[0];
				int a2=(int)q[1];
				int a3=(int)q[2];
				int a4=(int)q[3];
				if((a1==rectnum)||(a2==rectnum)||(a3==rectnum)||(a4==rectnum)){
				road=true;
				}
			   // CCLOG(" %d %d %d %d",a1,a2,a3,a4);
			
				
				if(road){
			    preChessVec.clear();
				preChess->setPreState(preChess->getState());
				preChessVec.push_back(preChess);
				canhuiqi=true;

				preChess->touchAction();
				preChess->setState(rectnum);
				//CCLOG("RECTNUM IS %d",rectnum);
				Point point=numToPoint(rectnum);
				auto MoveTo=MoveTo::create(2,point);
				//preChess->runAction(MoveTo);
				preChess->setPosition(point);
				//转换side状态
				thisSide=!thisSide;
				//CCLOG("SET POSITION TO  %d",rectnum);
				
				preChess=NULL;
				//停止音效，可以选择单独停掉一个音效，这个值是由playEffect返回的
SimpleAudioEngine::sharedEngine()->stopEffect(_soundId);
                //computer time
                passside=true;
				
                
				}
				else{
					preChess->touchAction();preChess=NULL;
				}
			}
			else 
			{}
		}
		else{
			if(preChess){
				if((currChess->getState()==preChess->getState())&&(currChess->getSide()==preChess->getSide()))
				{
					preChess->touchAction();
					preChess=NULL;
				}
				//包含吃子部分
				else if(currChess->getSide()==preChess->getSide())
			
				{
					currChess->touchAction();
					preChess->touchAction();
					preChess=currChess;
				}
				else
				{
					if(preChess->getTouched()){
						preChess->touchAction();
					}
					preChess=NULL;
				}
			}
			else
			{
				if((currChess->getSide()==thisSide)&&(currChess->getSide()==false)){
				currChess->touchAction();
				preChess=currChess;
				//开始播放背景音效，false表示不循环
               _soundId=SimpleAudioEngine::sharedEngine()->playEffect("touchsound2.mp3",false);}
			}
		}
	}
	else if(preChess)
	{
		preChess->touchAction();
		preChess=NULL;
	}
	//shade
	if(thisSide)
	{
		//shade examine
		updateShade();
		CCLOG("UPDATESHADE");
				
	}
	
	//第一次检测死亡
	for(auto it:chessVec)
	{
		//CCLOG("EXAMINEDEAD");
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
	if(examineblackdead()){
		if(_guan==17){
		tongguan(3);
		}else{
			endScene_Shade(1);}return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	//computer time
	if(passside)
	{
		CCLOG("COMPUTER TIME!");
		shadeSide();
		updateShade();
		//第二次检测死亡
		for(auto it:chessVec)
	{
		it->setDui(false);
	}
		for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
		if(examinewhitedead()){endScene_Shade(2);return true;}
		if(examineblackdead()){endScene_Shade(1);return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	}else{}

	
	CCLOG("preChess id is %d", preChess?preChess->getId():0) ;
	

	

	return true;

}
bool TiaozhanLayer::onTouchBegan6(Touch *touch, Event *event){
	if(_guan==22)
	{
		guide(20);
	}

	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	CCLOG("x is %d ,y is %d",x,y);
	int rectnum=0;
	rectnum=whichRectContainsPoint(point);
	//CCLOG("rectnum is %d" ,rectnum);
	//rect.containsPoint(point)
    //是否让电脑走
	bool passside=false;

	if(rectnum){
		bool wuzi=true;
		auto it=chessVec.begin();
		for(auto it:chessVec){
			if(it->getState()==rectnum){
				if(!(it->getDeaded())){wuzi=false;currChess=it; break;}
			}
		}
		//CCLOG("CURRCHESS : %d",currChess?currChess->getId():0);
		if(wuzi)
		{
			CCLOG("WUZI");
			if(preChess)
			{
				
				int *q=stateToAround(preChess->getState()) ;
				//CCLOG("road are %d %d %d %d",q[0],q[1],q[2],q[3]);
				bool road=false;
				//for(int i=0;i<4;i++){
				//	if (q[i]==rectnum){road=true;break;}
				//	CCLOG("rectnum is %d,q[i] is %d",rectnum,q[i]);
				//}
				int a1=(int)q[0];
				int a2=(int)q[1];
				int a3=(int)q[2];
				int a4=(int)q[3];
				if((a1==rectnum)||(a2==rectnum)||(a3==rectnum)||(a4==rectnum)){
				road=true;
				}
			   // CCLOG(" %d %d %d %d",a1,a2,a3,a4);
			
				
				if(road){
			    preChessVec.clear();
				preChess->setPreState(preChess->getState());
				preChessVec.push_back(preChess);
				canhuiqi=true;

				preChess->touchAction();
				preChess->setState(rectnum);
				//CCLOG("RECTNUM IS %d",rectnum);
				Point point=numToPoint(rectnum);
				auto MoveTo=MoveTo::create(2,point);
				//preChess->runAction(MoveTo);
				preChess->setPosition(point);
				//转换side状态
				thisSide=!thisSide;
				//CCLOG("SET POSITION TO  %d",rectnum);
				
				preChess=NULL;
				//停止音效，可以选择单独停掉一个音效，这个值是由playEffect返回的
SimpleAudioEngine::sharedEngine()->stopEffect(_soundId);
                //computer time
                passside=true;
				
                
				}
				else{
					preChess->touchAction();preChess=NULL;
				}
			}
			else 
			{}
		}
		else{
			if(preChess){
				if(currChess->getId()==preChess->getId())
				{
					preChess->touchAction();
					preChess=NULL;
				}
				//包含吃子部分
				else if(currChess->getSide()==preChess->getSide())
			
				{
					currChess->touchAction();
					preChess->touchAction();
					preChess=currChess;
				}
				else
				{
					if(preChess->getTouched()){
						preChess->touchAction();
					}
					preChess=NULL;
				}
			}
			else
			{
				if((currChess->getSide()==thisSide)&&(currChess->getSide()==false)){
				currChess->touchAction();
				preChess=currChess;
				//开始播放背景音效，false表示不循环
               _soundId=SimpleAudioEngine::sharedEngine()->playEffect("touchsound2.mp3",false);}
			}
		}
	}
	else if(preChess)
	{
		preChess->touchAction();
		preChess=NULL;
	}

	
	//第一次检测死亡
	for(auto it:chessVec)
	{
		//CCLOG("EXAMINEDEAD");
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
	if(examineblackdead()){
		if(_guan==6){
		tongguan(1);
		}else{
			endScene_Mo(1);}return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	//computer time
	if(passside)
	{
		CCLOG("COMPUTER TIME!");
		moSide();
		//第二次检测死亡
		for(auto it:chessVec)
	{
		it->setDui(false);
	}
		for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
		if(examinewhitedead()){endScene_Mo(2);return true;}
		if(examineblackdead()){endScene_Mo(1);return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	}else{}

	
	CCLOG("preChess id is %d", preChess?preChess->getId():0) ;
	

	

	return true;

}
bool TiaozhanLayer::endScene_CHU(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	if(i==1){auto win=Sprite::create("tiaozhanpass1.png");board=win;}else if(i==2){auto fail=Sprite::create("tiaozhanlose1.png");board=fail;}
	board->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height+200));
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem13.png","passitem13.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem11=MenuItemImage::create("passitem13.png","passitem13.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem2=MenuItemImage::create("passitem12.png","passitem12.png",CC_CALLBACK_1(TiaozhanLayer::reverse, this));
	auto selectItem3=MenuItemImage::create("passitem11.png","passitem11.png",CC_CALLBACK_1(TiaozhanLayer::pass,this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem11->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	selectItem3->setPosition(Vec2(120,90));
	auto menu1=Menu::create(selectItem1,selectItem3,NULL);
	auto menu2=Menu::create(selectItem11,selectItem2,NULL);
	menu1->setPosition(Vec2::ZERO);
	menu2->setPosition(Vec2::ZERO);
	if(i==1){
		board->addChild(menu1,5);}
	else if(i==2){board->addChild(menu2,5);}

	

	return true;
}
bool TiaozhanLayer::endScene_HUO(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	if(i==1){auto win=Sprite::create("tiaozhanpass2.png");board=win;}else if(i==2){auto fail=Sprite::create("tiaozhanlose2.png");board=fail;}
	board->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height+200));
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem23.png","passitem23.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem11=MenuItemImage::create("passitem23.png","passitem23.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem2=MenuItemImage::create("passitem22.png","passitem22.png",CC_CALLBACK_1(TiaozhanLayer::reverse, this));
	auto selectItem3=MenuItemImage::create("passitem21.png","passitem21.png",CC_CALLBACK_1(TiaozhanLayer::pass,this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem11->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	selectItem3->setPosition(Vec2(120,90));
	auto menu1=Menu::create(selectItem1,selectItem3,NULL);
	auto menu2=Menu::create(selectItem11,selectItem2,NULL);
	menu1->setPosition(Vec2::ZERO);
	menu2->setPosition(Vec2::ZERO);
	if(i==1){
		board->addChild(menu1,5);}
	else if(i==2){board->addChild(menu2,5);}

	

	return true;
}
bool TiaozhanLayer::endScene_Shade(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	if(i==1){auto win=Sprite::create("tiaozhanpass3.png");board=win;}else if(i==2){auto fail=Sprite::create("tiaozhanlose3.png");board=fail;}
	board->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height+200));
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem33.png","passitem33.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem11=MenuItemImage::create("passitem33.png","passitem33.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem2=MenuItemImage::create("passitem32.png","passitem32.png",CC_CALLBACK_1(TiaozhanLayer::reverse, this));
	auto selectItem3=MenuItemImage::create("passitem31.png","passitem31.png",CC_CALLBACK_1(TiaozhanLayer::pass,this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem11->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	selectItem3->setPosition(Vec2(120,90));
	auto menu1=Menu::create(selectItem1,selectItem3,NULL);
	auto menu2=Menu::create(selectItem11,selectItem2,NULL);
	menu1->setPosition(Vec2::ZERO);
	menu2->setPosition(Vec2::ZERO);
	if(i==1){
		board->addChild(menu1,5);}
	else if(i==2){board->addChild(menu2,5);}

	return true;
}
bool TiaozhanLayer::endScene_Mo(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	if(i==1){auto win=Sprite::create("tiaozhanpass4.png");board=win;}else if(i==2){auto fail=Sprite::create("tiaozhanlose4.png");board=fail;}
	board->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height+200));
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem43.png","passitem43.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem11=MenuItemImage::create("passitem43.png","passitem43.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	auto selectItem2=MenuItemImage::create("passitem42.png","passitem42.png",CC_CALLBACK_1(TiaozhanLayer::reverse, this));
	auto selectItem3=MenuItemImage::create("passitem41.png","passitem41.png",CC_CALLBACK_1(TiaozhanLayer::pass,this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem11->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	selectItem3->setPosition(Vec2(120,90));
	auto menu1=Menu::create(selectItem1,selectItem3,NULL);
	auto menu2=Menu::create(selectItem11,selectItem2,NULL);
	menu1->setPosition(Vec2::ZERO);
	menu2->setPosition(Vec2::ZERO);
	if(i==1){
		board->addChild(menu1,5);}
	else if(i==2){board->addChild(menu2,5);}

	return true;
}
void TiaozhanLayer::pass(Ref* pSender)
{
	numToInit(_guan+1);
}
void TiaozhanLayer::numToInit(int i)
{
	switch(i)
	{
	case 1:
		init_1();break;
	case 2:
		init_2();break;
	case 3:
		init_3();break;
	case 4:
		init_4();break;
	case 5:
		init_5();break;
	case 6:
		init_6();break;
	case 7:
		init_7();break;
	case 8:
	    init_8();break;
	case 9:
		init_9();break;
	case 10:
		init_10();break;
	case 11:
		init_11();break;
	case 12:
		init_12();break;
	case 13:
		init_13();break;
	case 14:
		init_14();break;
	case 15:
		init_15();break;
	case 16:
		init_16();break;
	case 17:
		init_17();break;
    case 18:
		init_18();break;
	 case 19:
		init_19();break;
	 case 20:
		init_20();break;
	case 21:
		init_21();break;
	case 22:
		init_22();break;
	default:
		CCLOG("NO INIT:%d",i);break;
		
	}
}

void TiaozhanLayer::reverse(Ref* pSender)
{
	myui();
	numToInit(_guan);
}
bool TiaozhanLayer::tongguan(int i)
{
	switch(i)
	{
	case 1:
		{ Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	auto win=Sprite::create("tongguan2.png");
	win->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y-visibleSize.height/2));
	board=win;
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem21.png","passitem21.png",CC_CALLBACK_1(TiaozhanLayer::pass, this));
	auto selectItem2=MenuItemImage::create("passitem23.png","passitem23.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	auto menu=Menu::create(selectItem1,selectItem2,NULL);
	menu->setPosition(Vec2::ZERO);
	board->addChild(menu);
   }break;
	case 2:
		{ Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	auto win=Sprite::create("tongguan3.png");
	win->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y-visibleSize.height/2));
	board=win;
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem31.png","passitem31.png",CC_CALLBACK_1(TiaozhanLayer::pass, this));
	auto selectItem2=MenuItemImage::create("passitem33.png","passitem33.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	auto menu=Menu::create(selectItem1,selectItem2,NULL);
	menu->setPosition(Vec2::ZERO);
	board->addChild(menu);
   }break;
	case 3:
		{ Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	auto win=Sprite::create("tongguan4.png");
	win->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y-visibleSize.height/2));
	board=win;
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("passitem41.png","passitem41.png",CC_CALLBACK_1(TiaozhanLayer::pass, this));
	auto selectItem2=MenuItemImage::create("passitem43.png","passitem43.png",CC_CALLBACK_1(TiaozhanLayer::goback, this));
	selectItem1->setPosition(Vec2(360,90));
	selectItem2->setPosition(Vec2(120,90));
	auto menu=Menu::create(selectItem1,selectItem2,NULL);
	menu->setPosition(Vec2::ZERO);
	board->addChild(menu);
   }break;

		
	}
	return true;
}
void TiaozhanLayer::myui()	
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto doorback=MenuItemImage::create("doorback.png","doorback.png",CC_CALLBACK_1(GameLayer::goback, this));
	doorback->setPosition(origin.x+0.1*visibleSize.width,origin.y+0.87*visibleSize.height);
	//this->addChild(doorback,8);

	auto reverse=MenuItemImage::create("reverse.png","reverse.png",CC_CALLBACK_1(TiaozhanLayer::reverse,this));
	reverse->setPosition(origin.x+0.35*visibleSize.width,origin.y+0.12*visibleSize.height);
	//this->addChild(reverse);
	auto huiqi=MenuItemImage::create("tong.png","tong.png",CC_CALLBACK_1(TiaozhanLayer::pass,this));
	huiqi->setPosition(origin.x+0.59*visibleSize.width,origin.y+0.12*visibleSize.height);

	auto menu=Menu::create(doorback,reverse,huiqi,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,7);
}
bool TiaozhanLayer::redSide()
{ 
	blackduis.clear();
	whiteduis.clear();
	//构造 whiteduis,blackduis
	for(auto it:chessVec){
		if((it->getState()!=-1)&&(!(it->getDui()))){
	     //aroundvec
		 vector<Chess*> aroundchess;
		 vector<int> aroundvec;
	     vector<Chess*> Cvec=dui(it,aroundchess,aroundvec);
		 
	     bool side=it->getSide();
		 //statesvec
		 vector<int> states;
		 if(side){
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 blackduis.push_back(adui);
		 }else
		 {
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 whiteduis.push_back(adui);
		 }
		
		}
     }
	//抉择与收益序列 <操作棋子（state)，目的，收益>
	vector<vector<int>> allActions;
	//1.检测是否有可吃(一气）
	for(auto it:whiteduis)
	{
		if(it->qi==1){
			int onceqi=*(it->_duiArounds.cbegin());
			int *q=stateToAround(onceqi);
			int b[4];
			for(int i=0;i<4;i++){b[i]=q[i];}
			for(int i=0;i<4;i++)
			{
				Chess* chess=stateToChess(b[i]);
				if (chess){}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					//CCLOG("is included? %d",(int)include);
					if(!include){
					vector<int> vec;
					int i=(it->statenumber)*3+4;
					vec.push_back(chess->getState());
					vec.push_back(onceqi);
					vec.push_back(i);
					allActions.push_back(vec);
					}
					else{}
				}
			}

		}
	}
	//检测可逃（一气）
	for(auto it:blackduis)
	{
		bool pass=false;
		if(it->qi==1){
		int onceqi=*(it->_duiArounds.cbegin());
	    int *q=stateToAround(onceqi);
		int b[4];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			Chess* chess1=stateToChess(b[i]);
			if(chess1)
			{
				vector<Chess*> vec1=it->_aroundChess;
				bool include=vecIncludeChess(it->_aroundChess,chess1);
				if((!include)&&(!chess1->getSide())){pass=true;break;}
			}
		}
		if(pass){
		for(int i=0;i<4;i++){
			Chess *chess=stateToChess(b[i]);
			if(chess&&chess->getSide())
			{
				bool include =vecIncludeChess(it->_duiStates,chess);
				if(include)
				{
					vector<int> vec;
					int i=(it->statenumber)*3+3;
					vec.push_back(chess->getState());
					vec.push_back(onceqi);
					vec.push_back(i);
					allActions.push_back(vec);
				}
			}

			}}
		
		}
	}
    //检测预吃（两口气）
	for(auto it:whiteduis)
	{
		if(it->qi==2){
			//CCLOG("QI:%d",it->qi);
			vector<int> qivec;
			qivec=it->_duiArounds;
			//CCLOG("QIVEC:%d %d",qivec[0],qivec[1]);
			vector<int> arounds=statesToKongArounds(qivec);
			//
			for(auto is=arounds.begin();is!=arounds.end();is++){CCLOG("AROUNDS:%d",*is);}
			for(auto is=arounds.begin();is!=arounds.end();is++)
			{
				Chess* chess=stateToChess(*is);
				if (chess){}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					CCLOG("is included? %d",(int)include);
					if(!include){
					vector<int> vec;
					int i=(it->statenumber)*3+2;
					vec.push_back(chess->getState());
					int *q=stateToAround(chess->getState());
					int b[5];
					for(int j=0;j<4;j++){b[j]=q[j];}
					if(qinclude(b,qivec[0])){vec.push_back(qivec[0]);}
					else{vec.push_back(qivec[1]);}

					vec.push_back(i);
					allActions.push_back(vec);
					}
					else{}
				}
			}

		}
	}
	for(auto it:blackduis)
	{
		bool pass=false;
		if(it->qi==2){
		vector<int> qivec;
		qivec=it->_duiArounds;
		//CCLOG("QIVEC:%d %d",qivec[0],qivec[1]);
		vector<int> arounds=statesToKongArounds(qivec);
		for(auto is=arounds.begin();is!=arounds.end();is++)
		{
			Chess* chess1=stateToChess(*is);
			if(chess1)
			{
				vector<Chess*> vec1=it->_aroundChess;
				bool include=vecIncludeChess(it->_aroundChess,chess1);
				if((!include)&&(!chess1->getSide())){pass=true;break;}
			}
		}
		if(pass){
		for(auto is=arounds.begin();is!=arounds.end();is++){
			Chess *chess=stateToChess(*is);
			if(chess&&chess->getSide())
			{
				bool include =vecIncludeChess(it->_duiStates,chess);
				if(include)
				{
					vector<int> vec;
					int i=(it->statenumber)*3+2;
					vec.push_back(chess->getState());
					int *q=stateToAround(chess->getState());
					int b[5];
					for(int j=0;j<4;j++){b[j]=q[j];}
					if(qinclude(b,qivec[0])){vec.push_back(qivec[0]);}
					else{vec.push_back(qivec[1]);}
					vec.push_back(i);
					allActions.push_back(vec);
				}
			}

			}}
		
		}
	}
	//权衡比较，决定最终行动
	if(allActions.size()>=1){
	CCLOG("ALLACTION.SIZE:%d",allActions.size());
	vector<int> endaction;
	endaction=allActions[0];
	auto is=endaction.end()-1;
	for(int i=0;i<allActions.size();i++)
	{
		auto t=allActions[i].end()-1;
		if(*t>*is){is=t;endaction=allActions[i];}
	}
	auto it2=endaction.begin();
	auto actionchess=stateToChess(*it2);
	it2++;

	actionchess->setPreState(actionchess->getState());
	preChessVec.push_back(actionchess);

	Point point=numToPoint(*it2);
	actionchess->setPosition(point);
	actionchess->setState(*it2);
	thisSide=false;

	//Fire
	if(actionchess->getSuperColor()==1){
		addFire(actionchess->getPreState());}
	else if(actionchess->getSuperColor()==2)
	{
		firebreak();
	}
	
	
	}
	//随机行动
	else{
		int num=0;
		while(1){
		auto largeqidui=blackduis[0];
		for(auto it:blackduis)
		{if (it->qi>largeqidui->qi){largeqidui=it;}}
		//CCLOG("MAXDUINUM: %d",maxdui->statenumber);
		//随机选取一个空qi
		int size=largeqidui->_duiArounds.size();
		int onebreath=largeqidui->_duiArounds[rand()%size];
		int *q=stateToAround(onebreath);
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		CCLOG("B:%d,%d,%d,%d",b[0],b[1],b[2],b[3]);
		//行动棋子
		Chess* actionchess=NULL;
		for(auto it:largeqidui->_duiStates)
		{
			if (qinclude(b,it->getState())){actionchess=it;CCLOG("OK");break;}
		}
		if(actionchess)
		{
		
			//限制次数到，弹出
			if(num==10){
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);

			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			thisSide=false;
			//Fire
	        	if(actionchess->getSuperColor()==1){
		addFire(actionchess->getPreState());}
	else if(actionchess->getSuperColor()==2)
	{
		firebreak();
	}

			return true;
			}
			//跳坑测试
			else{
			int prestate=actionchess->getState();
			actionchess->setState(onebreath);
			int shouyi=examinekeng();
			actionchess->setState(prestate);
			CCLOG("SHOUYI:%d",shouyi);
			if(shouyi>=0){
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);
			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			thisSide=false;
			//Fire
	       	if(actionchess->getSuperColor()==1){
		    addFire(actionchess->getPreState());}
	     else if(actionchess->getSuperColor()==2)
	    {
		   firebreak();
	     }

			return true;
			}
			num++;
			CCLOG("NUM:%d",num);
			}
			
		}
		}

	}




	return true;
}
bool TiaozhanLayer::shadeSide()
{ 
	blackduis.clear();
	whiteduis.clear();
	srand(time(NULL));
	//构造 whiteduis,blackduis
	for(auto it:chessVec){
		if((it->getState()!=-1)&&(!(it->getDui()))){
	     //aroundvec
		 vector<Chess*> aroundchess;
		 vector<int> aroundvec;
	     vector<Chess*> Cvec=dui(it,aroundchess,aroundvec);
		 
	     bool side=it->getSide();
		 //statesvec
		 vector<int> states;
		 if(side){
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 blackduis.push_back(adui);
		 }else
		 {
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 whiteduis.push_back(adui);
		 }
		
		}
     }
	//抉择与收益序列 <操作棋子（state)，目的，收益>
	vector<vector<int>> allActions;
	//shadechessvec
	shadeChessVec.clear();
	for(auto it:chessVec)
	{
		if(((it->getSuperColor()==3)||(it->getSuperColor()==5))&&(it->getState()!=-1)){shadeChessVec.push_back(it);}
	}
	//1.检测是否有可吃(一气）
	for(auto it:whiteduis)
	{
		if(it->qi==1){
			
			int onceqi=*(it->_duiArounds.cbegin());
			int *q=stateToAround(onceqi);
			int b[4];
			for(int i=0;i<4;i++){b[i]=q[i];}
			for(int i=0;i<4;i++)
			{
				Chess* chess=stateToChess(b[i]);
				if (chess){}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					//CCLOG("is included? %d",(int)include);
					if(!include){
					vector<int> vec;
					int i=(it->statenumber)*3+4;
					vec.push_back(chess->getState());
					vec.push_back(onceqi);
					vec.push_back(i);
					allActions.push_back(vec);

					}
					else{
						//shade
			if(shadeChessVec.size())
			{
				//Shade
				int size=shadeChessVec.size();
				Chess* actionchess=shadeChessVec[0];
				int onceqi=*(it->_duiArounds.cbegin());
				if(kengexamine(onceqi,true)){break;}
				actionchess->setPreState(actionchess->getState());
	            preChessVec.push_back(actionchess);
				actionchess->setState(onceqi);
				Point point=numToPoint(onceqi);
				actionchess->setPosition(point);
				addShade(actionchess->getPreState());
				thisSide=false;
				CCLOG("CHIONRQI");
				//anim
				//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);
				return true;

			}
					}
				}else
				{
					//shade
			if(shadeChessVec.size())
			{
				//Shade
				int size=shadeChessVec.size();
				Chess* actionchess=shadeChessVec[0];
				int onceqi=*(it->_duiArounds.cbegin());
				if(kengexamine(onceqi,true)){break;}
				actionchess->setPreState(actionchess->getState());
	            preChessVec.push_back(actionchess);
				actionchess->setState(onceqi);
				Point point=numToPoint(onceqi);
				actionchess->setPosition(point);
				addShade(actionchess->getPreState());
				thisSide=false;
				CCLOG("CHIONRQI");
			//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);
				return true;

			}
				}
			}

		}
	}
	//检测可逃（一气）
	for(auto it:blackduis)
	{
		//30%直接跳shade
		/*int by=rand()%100;
		if(shadeChessVec.size()&&(by>80))
		{
			
			vector<int> zhanwei;
			for(auto it:chessVec)
			{
				if(it->getState()!=-1)
				{
					zhanwei.push_back(it->getState());
				}
			}
			vector<int> kongstate;
			for(int j=1;j<22;j++){
			if(!vecinclude(zhanwei,j)){
				kongstate.push_back(j);
			}
			}
			int size=kongstate.size();
			int size2=shadeChessVec.size();
			Chess* actionchess;
			
			if(size2!=1){
				actionchess=shadeChessVec[rand()%(size2-1)];}
			else{actionchess=shadeChessVec[0];}
			int onceqi=0;
			if(size==1){
				 onceqi=kongstate[0];}
			else{onceqi=kongstate[rand()%(size-1)];}
				for(int i=0;i<size;i++)
				{
					if(!kengexamine(kongstate[i],true))
					{
						onceqi=kongstate[i];
					}
				}
				
				actionchess->setPreState(actionchess->getState());
	            preChessVec.push_back(actionchess);
				actionchess->setState(onceqi);
				Point point=numToPoint(onceqi);
				actionchess->setPosition(point);
				addShade(actionchess->getPreState());
				thisSide=false;
				//anim
				//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);

				CCLOG("TAOONRQI");
				return true;

			}*/
		bool pass=false;
		if(it->qi==1){
		int onceqi=*(it->_duiArounds.cbegin());
	    int *q=stateToAround(onceqi);
		int b[4];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			Chess* chess1=stateToChess(b[i]);
			if(chess1)
			{
				vector<Chess*> vec1=it->_aroundChess;
				bool include=vecIncludeChess(it->_aroundChess,chess1);
				if((!include)&&(!chess1->getSide())){pass=true;break;}
			}
		}
		if(pass){
		for(int i=0;i<4;i++){
			Chess *chess=stateToChess(b[i]);
			if(chess&&chess->getSide())
			{
				bool include =vecIncludeChess(it->_duiStates,chess);
				if(include)
				{
					vector<int> vec;
					int i=(it->statenumber)*3+3;
					vec.push_back(chess->getState());
					vec.push_back(onceqi);
					vec.push_back(i);
					allActions.push_back(vec);
				}
			}

			}}
		
		}
	}
    //检测预吃（两口气）
	for(auto it:whiteduis)
	{
		if(it->qi==2){
			
			//CCLOG("QI:%d",it->qi);
			vector<int> qivec;
			qivec=it->_duiArounds;
			//CCLOG("QIVEC:%d %d",qivec[0],qivec[1]);
			vector<int> arounds=statesToKongArounds(qivec);
			//
			for(auto is=arounds.begin();is!=arounds.end();is++){CCLOG("AROUNDS:%d",*is);}
			for(auto is=arounds.begin();is!=arounds.end();is++)
			{
				Chess* chess=stateToChess(*is);
				if (chess){}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					CCLOG("is included? %d",(int)include);
					if(!include){
					vector<int> vec;
					int i=(it->statenumber)*3+2;
					vec.push_back(chess->getState());
					int *q=stateToAround(chess->getState());
					int b[5];
					for(int j=0;j<4;j++){b[j]=q[j];}
					if(qinclude(b,qivec[0])){vec.push_back(qivec[0]);}
					else{vec.push_back(qivec[1]);}

					vec.push_back(i);
					allActions.push_back(vec);
					}
					else{}
				}
			}

		}
	}
	//
	for(auto it:blackduis)
	{
		bool pass=false;
		if(it->qi==2){
		vector<int> qivec;
		qivec=it->_duiArounds;
		//CCLOG("QIVEC:%d %d",qivec[0],qivec[1]);
		vector<int> arounds=statesToKongArounds(qivec);
		for(auto is=arounds.begin();is!=arounds.end();is++)
		{
			Chess* chess1=stateToChess(*is);
			if(chess1)
			{
				vector<Chess*> vec1=it->_aroundChess;
				bool include=vecIncludeChess(it->_aroundChess,chess1);
				if((!include)&&(!chess1->getSide())){pass=true;break;}
			}
		}
		if(pass){
		for(auto is=arounds.begin();is!=arounds.end();is++){
			Chess *chess=stateToChess(*is);
			if(chess&&chess->getSide())
			{
				bool include =vecIncludeChess(it->_duiStates,chess);
				if(include)
				{
					vector<int> vec;
					int i=(it->statenumber)*3+2;
					vec.push_back(chess->getState());
					int *q=stateToAround(chess->getState());
					int b[5];
					for(int j=0;j<4;j++){b[j]=q[j];}
					if(qinclude(b,qivec[0])){vec.push_back(qivec[0]);}
					else{vec.push_back(qivec[1]);}
					vec.push_back(i);
					allActions.push_back(vec);
				}
			}

			}}
		
		}
	}
	//权衡比较，决定最终行动
	if(allActions.size()>=1){


	CCLOG("ALLACTION.SIZE:%d",allActions.size());
	vector<int> endaction;
	endaction=allActions[0];
	auto is=endaction.end()-1;
	for(int i=0;i<allActions.size();i++)
	{
		auto t=allActions[i].end()-1;
		if(*t>*is){is=t;endaction=allActions[i];}
	}
	auto it2=endaction.begin();
	auto actionchess=stateToChess(*it2);
	it2++;

	actionchess->setPreState(actionchess->getState());
	preChessVec.push_back(actionchess);

	Point point=numToPoint(*it2);
	actionchess->setPosition(point);
	actionchess->setState(*it2);
	thisSide=false;
	//shade
	if((actionchess->getSuperColor()==3)||(actionchess->getSuperColor()==5))
	{
		addShade(actionchess->getPreState());
		//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);
	}
	


	
	
	
	}
	//随机行动
	else{
		//50%直接跳shade
		int by=rand()%100;
		if(shadeChessVec.size()&&(by>50))
		{
			vector<int> zhanwei;
			for(auto it:chessVec)
			{
				if(it->getState()!=-1)
				{
					zhanwei.push_back(it->getState());
				}
			}
			vector<int> kongstate;
			for(int j=1;j<22;j++){
			if(!vecinclude(zhanwei,j)){
				kongstate.push_back(j);
			}
			}
			int size=kongstate.size();
			int size2=shadeChessVec.size();
			Chess* actionchess;
			if(size2!=1){
				actionchess=shadeChessVec[rand()%(size2-1)];}
			else{actionchess=shadeChessVec[0];}
				int onceqi=kongstate[0];
				for(int i=0;i<size;i++)
				{
					if(!kengexamine(kongstate[i],true))
					{
						onceqi=kongstate[i];
					}
				}
				actionchess->setPreState(actionchess->getState());
	            preChessVec.push_back(actionchess);
				actionchess->setState(onceqi);
				Point point=numToPoint(onceqi);
				actionchess->setPosition(point);
				addShade(actionchess->getPreState());
				thisSide=false;
				//anim
				//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);

				CCLOG("随机跳");
				return true;

			}

		int num=0;
		while(blackduis.size()){
		auto largeqidui=blackduis[0];
		for(auto it:blackduis)
		{if (it->qi>largeqidui->qi){largeqidui=it;}}
		//CCLOG("MAXDUINUM: %d",maxdui->statenumber);
		//随机选取一个空qi
		int size=largeqidui->_duiArounds.size();
		int onebreath=largeqidui->_duiArounds[rand()%size];
		int *q=stateToAround(onebreath);
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		CCLOG("B:%d,%d,%d,%d",b[0],b[1],b[2],b[3]);
		//行动棋子
		Chess* actionchess=NULL;
		for(auto it:largeqidui->_duiStates)
		{
			if (qinclude(b,it->getState())){actionchess=it;CCLOG("OK");break;}
		}
		if(actionchess)
		{
		
			//限制次数到，弹出
			if(num==10){
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);

			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			//shade

	if((actionchess->getSuperColor()==3)||(actionchess->getSuperColor()==5))
	{
		addShade(actionchess->getPreState());
			//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);
	}

			return true;
			}
			//跳坑测试
			else{
			int prestate=actionchess->getState();
			actionchess->setState(onebreath);
			int shouyi=examinekeng();
			actionchess->setState(prestate);
			CCLOG("SHOUYI:%d",shouyi);
			if(shouyi>=0){
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);
			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			thisSide=false;
			//shade
	if((actionchess->getSuperColor()==3)||(actionchess->getSuperColor()==5))
	{
		addShade(actionchess->getPreState());
		//anim
				Point point1=numToPoint(actionchess->getState());
	            auto sprite1=Sprite::create("yingshan.png");
	            sprite1->setPosition(point1);
	            auto scale=ScaleBy::create(1.0f,3.0f);
	            auto fade=FadeOut::create(1.0f);
	            sprite1->runAction(scale);
	            sprite1->runAction(fade);
	            this->addChild(sprite1);
	}
	
			return true;
			}
			num++;
			CCLOG("NUM:%d",num);
			}
			
		}
		}

	}




	return true;
}
bool TiaozhanLayer::moSide()
{ 
	blackduis.clear();
	whiteduis.clear();
	//构造 whiteduis,blackduis
	for(auto it:chessVec){
		if((it->getState()!=-1)&&(!(it->getDui()))){
	     //aroundvec
		 vector<Chess*> aroundchess;
		 vector<int> aroundvec;
	     vector<Chess*> Cvec=dui(it,aroundchess,aroundvec);
		 
	     bool side=it->getSide();
		 //statesvec
		 vector<int> states;
		 if(side){
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 blackduis.push_back(adui);
		 }else
		 {
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 whiteduis.push_back(adui);
		 }
		
		}
     }

	//变子
	for(auto it:blackduis)
	{
		vector<Chess*> purpleVec;
		vector<Chess*> aroundVec;
		aroundVec=it->_aroundChess;
		bool isdao=false;
		for(auto is:it->_duiStates)
		{
			if((is->getSuperColor()==6)||(is->getSuperColor()==7))
			{
				purpleVec.push_back(is);
				if(is->getSuperColor()==7)
				{
					isdao=true;
				}
			}
		}
		if(purpleVec.size()&&aroundVec.size())
		{
			srand(time(NULL));
			int duinum=it->statenumber;
			int purplenum=purpleVec.size();
			CCLOG("PURPLENUM:%d",purplenum);
			int qi=it->qi;
			duinum=duinum-purplenum;
			int transby=purplenum*50-duinum*15-qi*15;
			int by=rand()%100;
			//转化
			CCLOG("TRANSBY:%d,BY:%d",transby,by);
			if(by<transby)
			{
				int size=aroundVec.size();
				Chess* transchess=NULL;
				if(size==1){transchess=aroundVec[0];}else{transchess=aroundVec[rand()%(size-1)];}
				int pointnum=transchess->getState();
				transchess->setSide(true);
				if(isdao){
					transchess->setSuperColor(7);}
				else{transchess->setSuperColor(1);}
				transchess->updatecolor();
				CREATESCALEANIMATION(pointnum,"purpletrans.png");
			}
		}
	}

	blackduis.clear();
	whiteduis.clear();
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	//构造 whiteduis,blackduis
	for(auto it:chessVec){
		if((it->getState()!=-1)&&(!(it->getDui()))){
	     //aroundvec
		 vector<Chess*> aroundchess;
		 vector<int> aroundvec;
	     vector<Chess*> Cvec=dui(it,aroundchess,aroundvec);
		 
	     bool side=it->getSide();
		 //statesvec
		 vector<int> states;
		 if(side){
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 blackduis.push_back(adui);
		 }else
		 {
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 whiteduis.push_back(adui);
		 }
		
		}
     }

	//抉择与收益序列 <操作棋子（state)，目的，收益>
	vector<vector<int>> allActions;
	//1.检测是否有可吃(一气）
	for(auto it:whiteduis)
	{
		if(it->qi==1){
			int onceqi=*(it->_duiArounds.cbegin());
			int *q=stateToAround(onceqi);
			int b[4];
			for(int i=0;i<4;i++){b[i]=q[i];}
			for(int i=0;i<4;i++)
			{
				Chess* chess=stateToChess(b[i]);
				if (chess){}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					//CCLOG("is included? %d",(int)include);
					if(!include){
					vector<int> vec;
					int i=(it->statenumber)*2+3;
					vec.push_back(chess->getState());
					vec.push_back(onceqi);
					vec.push_back(i);
					allActions.push_back(vec);
					}
					else{}
				}
			}

		}
	}
	//检测可逃（一气）
	for(auto it:blackduis)
	{
		bool pass=false;
		if(it->qi==1){
		int onceqi=*(it->_duiArounds.cbegin());
	    int *q=stateToAround(onceqi);
		int b[4];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			Chess* chess1=stateToChess(b[i]);
			if(chess1)
			{
				vector<Chess*> vec1=it->_aroundChess;
				bool include=vecIncludeChess(it->_aroundChess,chess1);
				if((!include)&&(!chess1->getSide())){pass=true;break;}
			}
		}
		if(pass){
		for(int i=0;i<4;i++){
			Chess *chess=stateToChess(b[i]);
			if(chess&&chess->getSide())
			{
				bool include =vecIncludeChess(it->_duiStates,chess);
				if(include)
				{
					vector<int> vec;
					int i=(it->statenumber)*2+2;
					vec.push_back(chess->getState());
					vec.push_back(onceqi);
					vec.push_back(i);
					allActions.push_back(vec);
				}
			}

			}}
		
		}
	}
    //检测预吃（两口气）
	for(auto it:whiteduis)
	{
		if(it->qi==2){
			//CCLOG("QI:%d",it->qi);
			vector<int> qivec;
			qivec=it->_duiArounds;
			//CCLOG("QIVEC:%d %d",qivec[0],qivec[1]);
			vector<int> arounds=statesToKongArounds(qivec);
			//
			for(auto is=arounds.begin();is!=arounds.end();is++){CCLOG("AROUNDS:%d",*is);}
			for(auto is=arounds.begin();is!=arounds.end();is++)
			{
				Chess* chess=stateToChess(*is);
				if (chess){}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					CCLOG("is included? %d",(int)include);
					if(!include){
					vector<int> vec;
					int i=(it->statenumber)*2+1;
					vec.push_back(chess->getState());
					int *q=stateToAround(chess->getState());
					int b[5];
					for(int j=0;j<4;j++){b[j]=q[j];}
					if(qinclude(b,qivec[0])){vec.push_back(qivec[0]);}
					else{vec.push_back(qivec[1]);}

					vec.push_back(i);
					allActions.push_back(vec);
					}
					else{}
				}
			}

		}
	}
	//检测欲逃
	for(auto it:blackduis)
	{
		bool pass=false;
		if(it->qi==2){
		vector<int> qivec;
		qivec=it->_duiArounds;
		//CCLOG("QIVEC:%d %d",qivec[0],qivec[1]);
		vector<int> arounds=statesToKongArounds(qivec);
		for(auto is=arounds.begin();is!=arounds.end();is++)
		{
			Chess* chess1=stateToChess(*is);
			if(chess1)
			{
				vector<Chess*> vec1=it->_aroundChess;
				bool include=vecIncludeChess(it->_aroundChess,chess1);
				if((!include)&&(!chess1->getSide())){pass=true;break;}
			}
		}
		if(pass){
		for(auto is=arounds.begin();is!=arounds.end();is++){
			Chess *chess=stateToChess(*is);
			if(chess&&chess->getSide())
			{
				bool include =vecIncludeChess(it->_duiStates,chess);
				if(include)
				{
					vector<int> vec;
					int i=(it->statenumber)*2+2;
					vec.push_back(chess->getState());
					int *q=stateToAround(chess->getState());
					int b[5];
					for(int j=0;j<4;j++){b[j]=q[j];}
					if(qinclude(b,qivec[0])){vec.push_back(qivec[0]);}
					else{vec.push_back(qivec[1]);}
					vec.push_back(i);
					allActions.push_back(vec);
				}
			}

			}}
		
		}
	}


	//权衡比较，决定最终行动
	if(allActions.size()>=1){
	CCLOG("ALLACTION.SIZE:%d",allActions.size());
	vector<int> endaction;
	endaction=allActions[0];
	auto is=endaction.end()-1;
	for(int i=0;i<allActions.size();i++)
	{
		auto t=allActions[i].end()-1;
		if(*t>*is){is=t;endaction=allActions[i];}
	}
	auto it2=endaction.begin();
	auto actionchess=stateToChess(*it2);
	it2++;

	actionchess->setPreState(actionchess->getState());
	preChessVec.push_back(actionchess);

	Point point=numToPoint(*it2);
	actionchess->setPosition(point);
	actionchess->setState(*it2);
	thisSide=false;
	
	
	}
	//随机行动
	else{
		int num=0;
		while(blackduis.size()){
		auto largeqidui=blackduis[0];
		for(auto it:blackduis)
		{if (it->qi>largeqidui->qi){largeqidui=it;}}
		//CCLOG("MAXDUINUM: %d",maxdui->statenumber);
		//随机选取一个空qi
		int size=largeqidui->_duiArounds.size();
		int onebreath=largeqidui->_duiArounds[rand()%size];
		int *q=stateToAround(onebreath);
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		CCLOG("B:%d,%d,%d,%d",b[0],b[1],b[2],b[3]);
		//行动棋子
		Chess* actionchess=NULL;
		for(auto it:largeqidui->_duiStates)
		{
			if (qinclude(b,it->getState())){actionchess=it;CCLOG("OK");break;}
		}
		if(actionchess)
		{
			/*
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);

			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			thisSide=false;
			*/
			//限制次数到，弹出
			if(num==10){
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);

			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			thisSide=false;
			return true;
			}
			//跳坑测试
			else{
			int prestate=actionchess->getState();
			actionchess->setState(onebreath);
			int shouyi=examinekeng();
			actionchess->setState(prestate);
			CCLOG("SHOUYI:%d",shouyi);
			if(shouyi>=0){
			actionchess->setPreState(actionchess->getState());
	        preChessVec.push_back(actionchess);
			Point point=numToPoint(onebreath);
			auto move=MoveTo::create(0.3f,point);
			actionchess->runAction(move);
			actionchess->setState(onebreath);
			thisSide=false;
			return true;
			}
			num++;
			CCLOG("NUM:%d",num);
			}
			
		}
		}

	}




	return true;
}
Fire* TiaozhanLayer::stateToFire(int state)
{
	Fire* fire=NULL;
	for(auto it:fireVec)
	{
		if(it->getState()==state)
		{
			fire=it;
			break;
		}
	}
	return fire;
}
void TiaozhanLayer::addFire(int num)
{
	int b[5];
	int *q=stateToAround(num);
	for(int i=0;i<4;i++){b[i]=q[i];}
	int bo=0;
	if(b[3]==0){
		bo=rand()%2;}else{bo=rand()%3;}
	int state=b[bo];
	auto fire=stateToFire(state);
	if(fire)
	{
		fire->setDelay(0);
	}
	else{
	        Point point=numToPoint(state);
         	auto fire=Fire::create(state);
        	fire->setPosition(point);
	        this->addChild(fire);
			fireVec.push_back(fire);
	}
}
void TiaozhanLayer::addFire(int num,int state)
{
	auto fire=stateToFire(state);
	if(fire)
	{
		fire->setDelay(0);
	}
	else{
	        Point point=numToPoint(state);
         	auto fire=Fire::create(state);
        	fire->setPosition(point);
	        this->addChild(fire);
			fireVec.push_back(fire);
	}
}
void TiaozhanLayer::addFire(vector<int> &vec)
{
	for(auto it=vec.begin();it!=vec.end();it++)
	{
		    CCLOG("FIRE ADD :%d ",*it);
	        Point point=numToPoint(*it);
         	auto fire=Fire::create(*it);
        	fire->setPosition(point);
			fire->setDelay(2);
	        this->addChild(fire);
			fireVec.push_back(fire);
	}
}
void TiaozhanLayer::killFire(int num)
{
	for(auto it:fireVec)
	{
		if(it->getState()==num)
		{
			it->setState(-1);
			it->setPosition(Vec2(-100,-100));
		}
	}
}
void TiaozhanLayer::cleanFire()
{
	//先清理
    for(auto it:fireVec)
	{
		if(it->getDelay()==2)
		{
			it->setPosition(-100,-100);
			it->setState(-1);
		}
	}
	//刷新delay
	for(auto it:fireVec)
	{
		int i=it->getDelay()+1;
		it->setDelay(i);
	}

}
void TiaozhanLayer::examineFireDead()
{
	for(auto it:chessVec)
	{
		if(!(it->getSide())){
		int num=it->getState();
		auto fire=stateToFire(num);
		if(fire&&(fire->getState()!=-1))
		{

			//kill chess
			fire->setState(-1);
			fire->setPosition(Vec2(-100,-100));

			auto cache = AnimationCache::getInstance();
            auto animation2 = cache->getAnimation("whiteball");
			auto sprite=Sprite::createWithSpriteFrameName("whiteball1.png");
			Point point=numToPoint(it->getState());
			sprite->setPosition(point);
			auto action2=Animate::create(animation2);
			sprite->runAction(action2);
			this->addChild(sprite);
			it->setPreState(it->getState());
			preChessVec.push_back(it);
			it->setDeaded(true);
			it->setPosition(Vec2(-50,-50));
			it->setState(-1);
			CCLOG("DEAD CHESS: %d",it->getPreState());
		}
		}
	}
}
void TiaozhanLayer::firebreak()
{
	auto dragon=this->getChildByTag(21);
	auto dragon2=(Chess*)dragon;

	Point point=numToPoint(dragon2->getState());
	auto sprite1=Sprite::create("Dragonkill.png");
	sprite1->setPosition(point);
	auto scale=ScaleBy::create(2.0f,5.0f);
	auto fade=FadeOut::create(2.0f);
	sprite1->runAction(scale);
	sprite1->runAction(fade);
	this->addChild(sprite1);

	//fire
	//产生j个随机数
	vector<int> intvec;
	
	for(int i=1;i<22;i++)
	{
		if(i!=dragon2->getState())
		intvec.push_back(i);
	}
	vector<int> selete;
	int i=0;
	int j=3;
	while(i!=j)
	{
		int num=rand()%19;
		if(intvec[num]!=0)
		{
			selete.push_back(intvec[num]);
			intvec[num]=0;
			i++;
		}
	}
	//
	for(int i=0;i<j;i++)
	{
		CCLOG("SELETE :%d",selete[i]);
		Point point=numToPoint(selete[i]);
		auto sprite3=Sprite::create("fireroot.png");
		auto rotate=RotateBy::create(4.0f,180.0f);
		auto fade=FadeOut::create(4.0f);
		sprite3->setPosition(point);
		sprite3->runAction(rotate);
		sprite3->runAction(fade);
		this->addChild(sprite3);
	}
	//add fire
	for(int i=0;i<j;i++){
		addFire(selete[i],selete[i]);}
	

	
	
}
void TiaozhanLayer::addShade(int num)
{
	Point point=numToPoint(num);
	Chess* shade=Chess::create(true,num+100,num,4);
	if(_guan==17)
	{
		shade->setDelay(2);
		CCLOG("GUAN17");
	}
	else{shade->setDelay(1);}
	shadeVec.push_back(shade);
	chessVec.push_back(shade);
	shade->setPosition(point);
	this->addChild(shade);


}
bool TiaozhanLayer::updateShade()
{
	if(shadeVec.size()==0)
	{
		return true;
	}
	//先清理
	for(auto it:shadeVec)
	{
		if(it->getDelay()==0)
		{
			it->setState(-1);
			it->setDeaded(true);
			it->setPosition(-100,-100);
		}
	}
	//加
	for(auto it:shadeVec)
	{
		int delay=it->getDelay()-1;
		it->setDelay(delay);
	}
	return true;
}
bool TiaozhanLayer::kengexamine(int num,bool side)
{
	bool unside=!side;
	int b[5];
	int *q=stateToAround(num);
	for(int i=0;i<4;i++){b[i]=q[i];}
	int j=0;
	if (b[3]==0){j=3;}else{j=4;}
	for(int is=0;is<j;is++)
	{
		Chess *chess=stateToChess(b[is]);
		if(!chess){return false;}
		else if(chess->getSide()==side){return false;}
	}
	return true;



}
void TiaozhanLayer::examineDead(Chess* chess)
{
	
	vector<int> intvec;
	vector<Chess*> Cvec=dui(chess,intvec);
	bool side=chess->getSide();
	bool istrue=true;
	for(auto it=intvec.begin();it!=intvec.end();it++)
	{
		Chess *chess=stateToChess(*it);
		if((!chess)||(chess->getSide()==side)){istrue=false;}
	}
	if(istrue)
	{
		for(auto it:Cvec)
		{
		
			//animation
			auto cache = AnimationCache::getInstance();
            auto animation2 = cache->getAnimation("whiteball");
			auto animation1 = cache->getAnimation("blackball");
			auto sprite=Sprite::createWithSpriteFrameName("whiteball1.png");
			auto sprite2=Sprite::createWithSpriteFrameName("blackball1.png");
			Point point=numToPoint(it->getState());
			sprite->setPosition(point);
			sprite2->setPosition(point);
			auto action2=Animate::create(animation2);
			auto action1=Animate::create(animation1);
			if(it->getSide()){
			sprite2->runAction(action1);
			this->addChild(sprite2);
			}else{
			sprite->runAction(action2);
			this->addChild(sprite);}

			it->setPreState(it->getState());
			preChessVec.push_back(it);
			CCLOG("%d has deaded",it->getId());
			

			it->setDeaded(true);
			it->setPosition(Vec2(-50,-50));
			it->setState(-1);
			//shade
			vector<Chess*> liveshadeVec;
			for(auto it:shadeVec)
			{
				if(it->getState()!=-1)
				{
					liveshadeVec.push_back(it);
				}
			}
			int liveshadesize=liveshadeVec.size();
			if(liveshadesize&&(it->getSuperColor()==5))
			{
				
				CCLOG("SHADE&&BEST");
				Chess* yingchess=NULL;
				if(liveshadesize=1){yingchess=liveshadeVec[0];}
				else {yingchess=liveshadeVec[rand()%(liveshadesize-1)];}
				int yingnum=yingchess->getState();
				Point point=numToPoint(yingnum);
				Chess* actionchess=it;
				actionchess->setDeaded(false);
				actionchess->setPosition(point);
				actionchess->setState(yingnum);
				yingchess->setState(-1);
				yingchess->setPosition(-100,-100);
				//animation
				Point point2=numToPoint(actionchess->getPreState());
				auto sprite=Sprite::create("yingshan2.png");
				auto Scale=ScaleTo::create(1.0f,3.0f);
				auto Fade=FadeOut::create(1.0f);
				sprite->setPosition(point2);
				sprite->runAction(Scale);
				sprite->runAction(Fade);
				this->addChild(sprite);

				

			}
		}
	}
}