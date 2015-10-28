#include "cocos2d.h"
#include "GameScene.h"
#include "public.h"
#include "chessdui.h"
#include "SimpleAudioEngine.h"
#include "TiaozhanLayer.h"
using namespace std;
using namespace CocosDenshion;

USING_NS_CC;
bool GameScene::init(){
if(!Scene::init()){
	return false;
}
//¶¯»­»º´æ
SpriteFrameCache::getInstance()->addSpriteFramesWithFile("whiteballanim.plist","whiteballanim.png");
SpriteFrameCache::getInstance()->addSpriteFramesWithFile("blackballanim.plist","blackballanim.png");
auto animation2 = createAnimation("blackball", 14, 0.06f);
auto animation = createAnimation("whiteball", 14, 0.06f);
AnimationCache::getInstance()->addAnimation(animation, "whiteball");
AnimationCache::getInstance()->addAnimation(animation2, "blackball");

//auto gamelayer=GameLayer::create(gamemode);
//CCLOG("GAMEMODE:%d",gamemode);
//gamelayer->setTag(1);
//this->addChild(gamelayer);
if(gamemode==3){
auto tiaozhanlayer=TiaozhanLayer::create(guan);
this->addChild(tiaozhanlayer);}
else {
	auto gamelayer=GameLayer::create(gamemode);
	this->addChild(gamelayer);
}
//backgroundmusic
//Ô¤¼ÓÔØ±³¾°ÒôÀÖ
auto audio = SimpleAudioEngine::getInstance();
SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("xueyu.mp3");
//¿ªÊ¼²¥·Å±³¾°ÒôÀÖ£¬true±íÊ¾Ñ­»·
SimpleAudioEngine::sharedEngine()->playBackgroundMusic("xueyu.mp3",true);


//test



return true;


}
GameScene*  GameScene::create(int gamemode,int guan) 
{ 
    GameScene *pRet = new(std::nothrow) GameScene(); 
    if (pRet) 
    { 
		pRet->gamemode=gamemode;
		pRet->guan=guan;
		if(pRet->init()){
        pRet->autorelease(); 
		return pRet; }else{delete pRet; 
        pRet = NULL; 
        return NULL; }
    } 
    else 
    { 
        delete pRet; 
        pRet = NULL; 
        return NULL; 
    } 
}
Animation* GameScene::createAnimation(std::string prefixName, int framesNum, float delay)
{
    // 1
    Vector<SpriteFrame*> animFrames;
    // 2
    for (int i = 1; i <= framesNum; i++)
    {
        char buffer[20] = { 0 };
        sprintf(buffer, "%i.png",  i);
        std::string str =  prefixName + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    // 3
    return Animation::createWithSpriteFrames(animFrames, delay);
}