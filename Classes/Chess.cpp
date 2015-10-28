#include "cocos2d.h"
#include "chess.h"
#include "public.h"
#include "SimpleAudioEngine.h"
using namespace std;
using namespace CocosDenshion;

USING_NS_CC;
Chess::Chess()
{
	_blinkaciton=NULL;
	_node=NULL;
	_sprite=NULL;
}
Chess* Chess::create(bool side,int id,int state,int color) 
{ 
    Chess *pRet = new(std::nothrow) Chess(); 
    if (pRet) 
    { 
        pRet->autorelease();
		//
		pRet->setSide(side);
		pRet->setId(id);
		pRet->setState(state);
		pRet->setDeaded(false);
		pRet->setDui(false);
		pRet->setTouched(false);
		pRet->setSuperColor(color);
		
		//pRet->init();
		if(pRet->init()){
			return pRet; }

    } 
    else 
    { 
        delete pRet; 
        pRet = NULL; 
        return NULL; 
    } 
}
bool Chess::init()
{
	//设初始数据
	
	int i=this->getSide();
	if(this->getSuperColor()){i=this->getSuperColor()+1;}
	switch(i)
	{
	case 1:
		{
		auto sprite1=Sprite::create("blackchess3.png");
	    _sprite=sprite1;
		this->addChild(_sprite);
		}break;
	case 0:
		{auto sprite2=Sprite::create("whitechess3.png");
		_sprite=sprite2;
		this->addChild(_sprite);}
		break;
	case 2:
		{auto sprite3=Sprite::create("firechess.png");
		_sprite=sprite3;
		this->addChild(_sprite);}
		break;
	case 3:
		{auto sprite4=Sprite::create("fireDragonchess.png");
		_sprite=sprite4;
		this->addChild(_sprite);}
		break;
	case 4:
		{auto sprite5=Sprite::create("greenchess.png");
		_sprite=sprite5;
		this->addChild(_sprite);}
		break;
	case 5:
		{auto sprite6=Sprite::create("ying.png");
		_sprite=sprite6;
		this->addChild(_sprite);}
		break;
	case 6:
		{auto sprite7=Sprite::create("shadeBestchess.png");
		_sprite=sprite7;
		this->addChild(_sprite);}
		break;
	case 7:
		{auto sprite8=Sprite::create("purplechess.png");
		_sprite=sprite8;
		this->addChild(_sprite);}
		break;
	case 8:
		{auto sprite9=Sprite::create("modao.png");
		_sprite=sprite9;
		this->addChild(_sprite);}
		break;
	default:
		break;

	}
	



	this->setTouched(false);
	//this->addChild(node);
	
	this->setDelay(0);
	
	this->setPreState(this->getState());

	

	

	return true;

}

void Chess::touchAction(){
    bool zhi=this->getTouched();
	this->setTouched(!zhi);
	//yinxiao
	
 
	auto FadeIn=FadeIn::create(0.2f);
	auto FadeOut=FadeOut::create(0.3f);
	auto rotateTo = RotateBy::create(1.0f, 360.0f);
	auto FadeOut2=FadeIn::create(0.0f);
	//auto action=RepeatForever::create(Sequence::create(FadeIn,FadeOut,nullptr));
	auto action=RepeatForever::create(rotateTo);
	_sprite->stopAllActions();
	CCLOG("STOP ROTATE");
	//_sprite->runAction(FadeOut2);
 	if(this->getTouched())
	{
	//auto sprite3=(Sprite*)_node->getChildByTag(1);
	CCLOG("ROTATE");
	_sprite->runAction(action);
//	_node->runAction(_blinkaciton);
	}

}
void Chess::stopTouchAction(){
	auto action=FadeIn::create(0.0f);
		_sprite->stopAllActions();
	_sprite->runAction(action);
}
void Chess::updatecolor()
{
	int i=this->getSuperColor();
	this->removeAllChildren();
	switch(i)
	{
		CCLOG("superchess:%d",i);
	case 1:
		{
		auto sprite1=Sprite::create("blackchess3.png");
	    _sprite=sprite1;
		this->addChild(_sprite);
		}break;
	case 0:
		{auto sprite2=Sprite::create("whitechess3.png");
		_sprite=sprite2;
		this->addChild(_sprite);}
		break;
	case 2:
		{auto sprite3=Sprite::create("firechess.png");
		_sprite=sprite3;
		this->addChild(_sprite);}
		break;
	case 3:
		{auto sprite4=Sprite::create("fireDragonchess.png");
		_sprite=sprite4;
		this->addChild(_sprite);}
		break;
	case 4:
		{auto sprite5=Sprite::create("greenchess.png");
		_sprite=sprite5;
		this->addChild(_sprite);}
		break;
	case 5:
		{auto sprite6=Sprite::create("ying.png");
		_sprite=sprite6;
		this->addChild(_sprite);}
		break;
	case 6:
		{auto sprite7=Sprite::create("shadeBestchess.png");
		_sprite=sprite7;
		this->addChild(_sprite);}
		break;
	case 7:
		{auto sprite8=Sprite::create("purplechess.png");
		_sprite=sprite8;
		this->addChild(_sprite);}
		break;
	case 8:
		{auto sprite9=Sprite::create("modao.png");
		_sprite=sprite9;
		this->addChild(_sprite);}
		break;
	default:
		
		break;

	}
}