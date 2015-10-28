#include "Fire.h"

Fire* Fire::create(int state) 
{ 
    Fire *pRet = new(std::nothrow) Fire(); 
    if (pRet) 
    { 
        pRet->autorelease(); 
		pRet->setState(state);
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
bool Fire::init()
{
	this->setDelay(0);

	auto sprite=Sprite::create("fireroot.png");
	this->addChild(sprite);

	auto rotate=RotateBy::create(2.0f,360.0f);
	auto FadeIn=FadeIn::create(0.3f);
	auto FadeOut=FadeOut::create(1.0f);
	auto Fade=Sequence::create(FadeIn,FadeOut,nullptr);
	sprite->runAction(CCRepeatForever::create(Fade));
	sprite->runAction(CCRepeatForever::create(rotate));
	return true;
}