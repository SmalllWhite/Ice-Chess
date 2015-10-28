#include "GameLayer.h"
#include "cocos2d.h"
#include "public.h"
#include "Chess.h"
#include <vector>
#include <iostream>
#include "SimpleAudioEngine.h"
#include "StartScene.h"
using namespace CocosDenshion;
using namespace std;
USING_NS_CC;
vector<int*> aroundVec;
GameLayer*  GameLayer::create(int gamemode) 
{ 
    GameLayer *pRet = new(std::nothrow) GameLayer(); 
    if (pRet) 
    { 
		pRet->gamemode=gamemode;
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
GameLayer::GameLayer(){
	_preTouch=0;
	_currTouch=0;
	preChess=NULL;
	currChess=NULL;
	gamemode=1;
}

bool GameLayer::init(){
if(!Layer::init()){
return false;


}
Size visibleSize = Director::getInstance()->getVisibleSize();
Vec2 origin = Director::getInstance()->getVisibleOrigin();
//棋盘
auto qipan=Sprite::create("qipan9.png");
qipan->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
this->addChild(qipan,0);
//何棋先走
thisSide=false;


{auto chess=Chess::create(false,15,15,0); 
Point point=numToPoint(15); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,16,16,0); 
Point point=numToPoint(16); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,7,7,0); 
Point point=numToPoint(7); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,17,17,0); 
Point point=numToPoint(17); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,12,12,0); 
Point point=numToPoint(12); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,20,20,0); 
Point point=numToPoint(20); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}


{auto chess=Chess::create(true,11,11,0); 
Point point=numToPoint(11); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,5,5,0); 
Point point=numToPoint(5); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,9,9,0); 
Point point=numToPoint(9); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,10,10,0); 
Point point=numToPoint(10); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,14,14,0); 
Point point=numToPoint(14); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,18,18,0); 
Point point=numToPoint(18); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}


CCLOG("LAYERGAMEMODE:%d",this->gamemode);
//listener
auto dispatcher = Director::getInstance()->getEventDispatcher();
auto listener=EventListenerTouchOneByOne::create();
auto listener2=EventListenerTouchOneByOne::create();
listener->onTouchBegan=CC_CALLBACK_2(GameLayer::onTouchBegan,this);
listener2->onTouchBegan=CC_CALLBACK_2(GameLayer::onTouchBegan2,this);

if(gamemode==1)
{dispatcher->addEventListenerWithSceneGraphPriority(listener,this);CCLOG("DISPATHER ADD");}
else if(gamemode==2)
{dispatcher->addEventListenerWithSceneGraphPriority(listener2,this);CCLOG("DISPATHER ADD2");}


//ui
ui();
//huiqi
canhuiqi=false;


//音效
//预加载音效
SimpleAudioEngine::sharedEngine()->preloadEffect("touchsound2.mp3");



return true;

}

void GameLayer::touchChess(){
	//
	//Chess* chess=(Chess*)this->getChildByTag(1);
 //   chess1->touchAction(); 

}
bool GameLayer::onTouchBegan(Touch *touch, Event *event){
	
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
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
	if(examineblackdead()){endScene(1);return true;}
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
		if(examinewhitedead()){endScene(2);return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	}else{}

	
	//CCLOG("preChess id is %d", preChess?preChess->getId():0) ;
	

	//test
	vector<int> intvec;
	vector<int> aroundsvec;
	intvec.push_back(15);
	intvec.push_back(7);
	aroundsvec=statesToArounds(intvec);

	return true;

}

int GameLayer::whichRectContainsPoint(Point point){
	vector<Rect> vec;
	Rect rect1=RECT_1;
	Rect rect2=RECT_2;
	Rect rect3=RECT_3;
	Rect rect4=RECT_4;
	Rect rect5=RECT_5;
	Rect rect6=RECT_6;
	Rect rect7=RECT_7;
	Rect rect8=RECT_8;
	Rect rect9=RECT_9;
	Rect rect10=RECT_10;
	Rect rect11=RECT_11;
	Rect rect12=RECT_12;
	Rect rect13=RECT_13;
	Rect rect14=RECT_14;
	Rect rect15=RECT_15;
	Rect rect16=RECT_16;
	Rect rect17=RECT_17;
	Rect rect18=RECT_18;
	Rect rect19=RECT_19;
	Rect rect20=RECT_20;
	Rect rect21=RECT_21;
	//auto rec=&rects;
	vec.push_back(rect1);
	vec.push_back(rect2);
	vec.push_back(rect3);
	vec.push_back(rect4);
	vec.push_back(rect5);
	vec.push_back(rect6);
	vec.push_back(rect7);
	vec.push_back(rect8);
	vec.push_back(rect9);
	vec.push_back(rect10);
	vec.push_back(rect11);
	vec.push_back(rect12);
	vec.push_back(rect13);
	vec.push_back(rect14);
	vec.push_back(rect15);
	vec.push_back(rect16);
	vec.push_back(rect17);
	vec.push_back(rect18);
	vec.push_back(rect19);
	vec.push_back(rect20);
	vec.push_back(rect21);

	
	int count=0;
	//auto  it=*rec.begin();
	for( auto it:vec)
	{
		count++;
		if (it.containsPoint(point))
		{
			return count;
		}
		
	}

	count=0;
	return count;

}
void GameLayer::initaroundVec()
{
	int q1[]={10,2,21,4};
	int q2[]={1,13,3,21};
	int q3[]={21,2,16,4};
	int q4[]={1,21,3,19};
	int q5[]={9,10,11,0};
	int q6[]={14,12,13,0};
	int q7[]={16,17,15,0};
	int q8[]={18,19,20,0};
	int q9[]={5,14,10,0};
	int q10[]={5,9,1,11};
	int q11[]={5,10,18,0};
	int q12[]={6,17,13,0};
	int q13[]={14,6,12,2};
	int q14[]={9,6,13,0};
	int q15[]={16,7,20,0};
	int q16[]={3,17,7,15};
	int q17[]={12,7,16,0};
	int q18[]={11,19,8,0};
	int q19[]={18,4,20,8};
	int q20[]={19,15,8,0};
	int q21[]={1,2,3,4};

	aroundVec.push_back(q1);
	aroundVec.push_back(q2);
	aroundVec.push_back(q3);
	aroundVec.push_back(q4);
	aroundVec.push_back(q5);
	aroundVec.push_back(q6);
	aroundVec.push_back(q7);
	aroundVec.push_back(q8);
	aroundVec.push_back(q9);
	aroundVec.push_back(q10);
	aroundVec.push_back(q11);
	aroundVec.push_back(q12);
	aroundVec.push_back(q13);
	aroundVec.push_back(q14);
	aroundVec.push_back(q15);
	aroundVec.push_back(q16);
	aroundVec.push_back(q17);
	aroundVec.push_back(q18);
	aroundVec.push_back(q19);
	aroundVec.push_back(q20);
	aroundVec.push_back(q21);

	int *q=aroundVec[0];
	//CCLOG("road %d %d %d %d",q[0],q[1],q[2],q[3]);


}
void GameLayer::examineDeads()
{
	

}
void GameLayer::examineDead(Chess* chess)
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
			//CCLOG("%d has deaded",it->getId());
			

			
			it->setDeaded(true);
			it->setPosition(Vec2(-50,-50));
			it->setState(-1);
		}
	}
}
//important function
Chess* GameLayer::stateToChess(int state)
{
	int chessId=0;
	for(auto it:chessVec){
		if(it->getState()==state)
		{
			//多余信息：Id
			chessId=it->getId();
			return it;
		}
	}
	return NULL;
}
Chess* GameLayer::idToChess(int id)
{
	for(auto it:chessVec){
		if(it->getId()==id){return it;}
	}
	return NULL;
}
int* GameLayer::stateToAround(int state)
{
	int *q;
	int q1[]={10,2,21,4};
	int q2[]={1,13,3,21};
	int q3[]={21,2,16,4};
	int q4[]={1,21,3,19};
	int q5[]={9,10,11,0};
	int q6[]={14,12,13,0};
	int q7[]={16,17,15,0};
	int q8[]={18,19,20,0};
	int q9[]={5,14,10,0};
	int q10[]={5,9,1,11};
	int q11[]={5,10,18,0};
	int q12[]={6,17,13,0};
	int q13[]={14,6,12,2};
	int q14[]={9,6,13,0};
	int q15[]={16,7,20,0};
	int q16[]={3,17,7,15};
	int q17[]={12,7,16,0};
	int q18[]={11,19,8,0};
	int q19[]={18,4,20,8};
	int q20[]={19,15,8,0};
	int q21[]={1,2,3,4};
	switch(state){
	case 1:q=q1;break;
	case 2:q=q2;break;
	case 3:q=q3;break;
	case 4:q=q4;break;
	case 5:q=q5;break;
	case 6:q=q6;break;
	case 7:q=q7;break;
	case 8:q=q8;break;
	case 9:q=q9;break;
	case 10:q=q10;break;
	case 11:q=q11;break;
	case 12:q=q12;break;
	case 13:q=q13;break;
	case 14:q=q14;break;
	case 15:q=q15;break;
	case 16:q=q16;break;
	case 17:q=q17;break;
	case 18:q=q18;break;
	case 19:q=q19;break;
	case 20:q=q20;break;
	case 21:q=q21;break;
	
	default:q=NULL;break;
	}
	return q;


}
vector<int> GameLayer::statesToArounds(vector<int> &states)
{
	vector<int> aroundvec;
	for(auto it=states.begin();it!=states.end();it++)
	{
		int *q=stateToAround(*it);
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			aroundvec.push_back(b[i]);
		}
	}
	//第一步：除零
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		if(*it==0)
		{
			it=aroundvec.erase(it);
		}
		else {it++;}
	
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.2 %d",*it);
	}
	//第二步：除被占
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		Chess* chess=stateToChess(*it);
		if(chess){it=aroundvec.erase(it);}
		else {it++;}
	}
	//除重复
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		bool add=true;
		for(auto is=aroundvec.begin();is!=it;is++)
		{
			if(*is==*it){it=aroundvec.erase(it);add=false;break;}
		}
		if(add){it++;}else{}
	}
	//除自身
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		bool erase=false;
		for(auto is=states.begin();is!=states.end();is++)
		{
			if(*is==*it){it=aroundvec.erase(it);erase=true;break;}
		}
		if(!erase){it++;}
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;
	}
	return aroundvec;
}
vector<int> GameLayer::statesToKongArounds(vector<int> &states)
{
	vector<int> aroundvec;
	for(auto it=states.begin();it!=states.end();it++)
	{
		int *q=stateToAround(*it);
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			aroundvec.push_back(b[i]);
		}
	}
	//第一步：除零
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		if(*it==0)
		{
			it=aroundvec.erase(it);
		}
		else {it++;}
	
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.2 %d",*it);
	}
	//除重复
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		bool add=true;
		for(auto is=aroundvec.begin();is!=it;is++)
		{
			if(*is==*it){it=aroundvec.erase(it);add=false;break;}
		}
		if(add){it++;}else{}
	}
	//除自身
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		bool erase=false;
		for(auto is=states.begin();is!=states.end();is++)
		{
			if(*is==*it){it=aroundvec.erase(it);erase=true;break;}
		}
		if(!erase){it++;}
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;
	}
	return aroundvec;
}
bool GameLayer::stateHasChess(int state)
{
	bool is=false;
	for(auto it:chessVec)
	{
		if(it->getState()==state){is=true;}
	}
	if(state==0){is=true;}
	return is;
}
vector<Chess*>  GameLayer::dui(Chess* chess,vector<int> &aroundvec)
{
	queue<Chess*> que;
	que.push(chess);
	bool side=chess->getSide();
	chess->setDui(true);
	vector<Chess*> vec;
	while(que.size())
	{
	Chess* chess1=que.front();
	vec.push_back(chess1);
	//CCLOG("PUSH A CHESS");
	que.pop();
	int *q=stateToAround(chess1->getState());
	int b[5];
	for(int i=0;i<4;i++){b[i]=q[i];}
	for(int i=0;i<4;i++)
	{
		Chess* chess2=stateToChess(b[i]);
		if(chess2&&(!(chess2->getDui()))&&(chess2->getSide()==side))
		{
			que.push(chess2);
			chess2->setDui(true);
		}
	}
	}
	for(auto it:vec)
	{
		//std::cout<<"chess:"<<it->getId();
		//CCLOG("CHESS %d" ,it->getId());
	}
	//CCLOG("HAS DUIED");
	//获取堆所有周边位置
	for(auto it:vec)
	{
		int *q=stateToAround(it->getState());
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			aroundvec.push_back(b[i]);
			
		}
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.1 %d",*it);
	}
	//处理堆周边位置
	//第一步：除零
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		if(*it==0)
		{
			it=aroundvec.erase(it);
		}
		else {it++;}
	
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.2 %d",*it);
	}
	//第二步：除被占
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		Chess* chess=stateToChess(*it);
		if(chess){it=aroundvec.erase(it);}
		else {it++;}
	}
	//除重复
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		bool add=true;
		for(auto is=aroundvec.begin();is!=it;is++)
		{
			if(*is==*it){it=aroundvec.erase(it);add=false;break;}
		}
		if(add){it++;}else{}
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.end %d",*it);
	}
	//CCLOG("  END");
	return vec;

}
vector<Chess*>  GameLayer::dui(Chess* chess,vector<Chess*> &p,vector<int> &aroundvec)
{
	queue<Chess*> que;
	que.push(chess);
	bool side=chess->getSide();
	chess->setDui(true);
	vector<Chess*> vec;
	while(que.size())
	{
	Chess* chess1=que.front();
	vec.push_back(chess1);
	//CCLOG("PUSH A CHESS");
	que.pop();
	int *q=stateToAround(chess1->getState());
	int b[5];
	for(int i=0;i<4;i++){b[i]=q[i];}
	for(int i=0;i<4;i++)
	{
		Chess* chess2=stateToChess(b[i]);
		if(chess2&&(!(chess2->getDui()))&&(chess2->getSide()==side))
		{
			que.push(chess2);
			chess2->setDui(true);
		}
	}
	}
	for(auto it:vec)
	{
		//std::cout<<"chess:"<<it->getId();
		//CCLOG("CHESS %d" ,it->getId());
	}
	//CCLOG("HAS DUIED");
	//获取堆所有周边位置
	for(auto it:vec)
	{
		int *q=stateToAround(it->getState());
		int b[5];
		for(int i=0;i<4;i++){b[i]=q[i];}
		for(int i=0;i<4;i++)
		{
			aroundvec.push_back(b[i]);
			
		}
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.1 %d",*it);
	}
	//处理堆周边位置
	//第一步：除零
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		if(*it==0)
		{
			it=aroundvec.erase(it);
		}
		else {it++;}
	
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.2 %d",*it);
	}
	//第二步：除被占
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		Chess* chess=stateToChess(*it);
		if(chess){it=aroundvec.erase(it);
		if(chess->getSide()!=side){p.push_back(chess);}
		else{}}
		else {it++;}
	}
	//除重复
	for(auto it=aroundvec.begin();it!=aroundvec.end();it)
	{
		bool add=true;
		for(auto is=aroundvec.begin();is!=it;is++)
		{
			if(*is==*it){it=aroundvec.erase(it);add=false;break;}
		}
		if(add){it++;}else{}
	}
	for(auto it=aroundvec.begin();it!=aroundvec.end();it++){int i=*it;//CCLOG("no.end %d",*it);
	}
	//CCLOG("  END");
	return vec;

}

bool GameLayer::blackSide()
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
	//CCLOG("blackDUINUMBER: %d",blackduis.size());
	//CCLOG("whiteDUINUMBER: %d",whiteduis.size());
	int i=1;
	for(auto it:blackduis)
	{
		CCLOG("blackDUI%d breath: %d difangzhanwei:%d",i++,it->_duiArounds.size(),it->_aroundChess.size());
	}
	i=1;
	for(auto it:whiteduis)
	{
		CCLOG("whiteDUI%d breath: %d difangzhanwei:%d",i++,it->_duiArounds.size(),it->_aroundChess.size());
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
int GameLayer::examinekeng()
{
	vector<chessdui*> Ablackduis;
	vector<chessdui*> Awhiteduis;
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
			 Ablackduis.push_back(adui);
		 }else
		 {
			 chessdui* adui=new chessdui(Cvec,aroundchess,aroundvec);
			 Awhiteduis.push_back(adui);
		 }
		
		}
     }
	
	//收益
	int shouyi=0;
    //1.检测是否有可吃(一气）
	for(auto it:Awhiteduis)
	{
		if(it->qi==1){
			int onceqi=*(it->_duiArounds.cbegin());
			int *q=stateToAround(onceqi);
			int b[4];
			for(int i=0;i<4;i++){b[i]=q[i];}
			for(int i=0;i<4;i++)
			{
				Chess* chess=stateToChess(b[i]);
				if (chess){
					//CCLOG("CHESS ID: %d",chess->getId());
				}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					//CCLOG("is included? %d",(int)include);
					if(!include){
					int i=(it->statenumber)*5+4;
					shouyi+=i;
					}
					else{}
				}
			}

		}
	}
	//检测可逃（一气）
	for(auto it:Ablackduis)
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
					int i=(it->statenumber)*2+3;
					shouyi-=i;
				}
			}

			}}
		
		}
	}
    //检测预吃（两口气）
	for(auto it:Awhiteduis)
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
				if (chess){//CCLOG("CHESS ID: %d",chess->getId());
				}
				
				if(chess&&chess->getSide())
				{
					bool include=vecIncludeChess(it->_aroundChess,chess);
					//CCLOG("is included? %d",(int)include);
					if(!include){
					int i=(it->statenumber)*2+2;
					shouyi+=i;
					}
					else{}
				}
			}

		}
	}
	//检测欲逃
	for(auto it:Ablackduis)
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
					int i=(it->statenumber)*2+2;
					shouyi-=i;
				}
			}

			}}
		
		}
	}



	return shouyi;
}
bool GameLayer::vecIncludeChess(vector<Chess*> &vec,Chess* chess)
{
	for (auto it:vec)
	{
		if((it->getId())==(chess->getId())){return true;}
	}
	return false;

}
bool GameLayer::qinclude(int *q,int num)
{
	
	for(int j=0;j<4;j++)
	{
		if (q[j]==num){
		return true;}
	}
	return false;
}
bool GameLayer::vecinclude(vector<int> &vec,int i)
{
	for(auto it=vec.begin();it!=vec.end();it++)
	{
		if(*it==i){return true;}
	}
	return false;
}
bool GameLayer::endScene(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	if(i==1){auto win=Sprite::create("winitem.png");board=win;}else if(i==2){auto fail=Sprite::create("faileditem.png");board=fail;}
	board->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height+200));
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("backitem.png","backitem.png",CC_CALLBACK_1(GameLayer::goback, this));
	auto selectItem2=MenuItemImage::create("reverseitem.png","reverseitem.png",CC_CALLBACK_1(GameLayer::reverse, this));
	selectItem1->setPosition(Vec2(77,50));
	selectItem2->setPosition(Vec2(229,50));
	auto menu=Menu::create(selectItem1,selectItem2,NULL);
	menu->setPosition(Vec2::ZERO);
	board->addChild(menu,5);

	

	return true;
}
void GameLayer::reverse(Ref* pSender)
{

this->removeAllChildren();
chessVec.clear();
//血的教训
auto dispatcher = Director::getInstance()->getEventDispatcher();
dispatcher->removeAllEventListeners();

Size visibleSize = Director::getInstance()->getVisibleSize();
Vec2 origin = Director::getInstance()->getVisibleOrigin();
//棋盘
auto qipan=Sprite::create("qipan9.png");
qipan->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
this->addChild(qipan,0);

//何棋先走
thisSide=false;


//CHESS


{auto chess=Chess::create(false,15,15,0); 
Point point=numToPoint(15); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,16,16,0); 
Point point=numToPoint(16); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,7,7,0); 
Point point=numToPoint(7); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,17,17,0); 
Point point=numToPoint(17); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,12,12,0); 
Point point=numToPoint(12); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(false,20,20,0); 
Point point=numToPoint(20); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}


{auto chess=Chess::create(true,11,11,0); 
Point point=numToPoint(11); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,5,5,0); 
Point point=numToPoint(5); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,9,9,0); 
Point point=numToPoint(9); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,10,10,0); 
Point point=numToPoint(10); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,14,14,0); 
Point point=numToPoint(14); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
{auto chess=Chess::create(true,18,18,0); 
Point point=numToPoint(18); 
chess->setPosition(point);
this->addChild(chess);
chessVec.push_back(chess);}
//ui
ui();
canhuiqi=false;

//auto dispatcher = Director::getInstance()->getEventDispatcher();
auto listener=EventListenerTouchOneByOne::create();
auto listener2=EventListenerTouchOneByOne::create();
listener->onTouchBegan=CC_CALLBACK_2(GameLayer::onTouchBegan,this);
listener2->onTouchBegan=CC_CALLBACK_2(GameLayer::onTouchBegan2,this);

if(gamemode==1)
{dispatcher->addEventListenerWithSceneGraphPriority(listener,this);}
else if(gamemode==2)
{dispatcher->addEventListenerWithSceneGraphPriority(listener2,this);}


}
void GameLayer::goback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene=StartScene::createScene();
	director->replaceScene(scene);

	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	
}
bool GameLayer::examineblackdead()
{
	for(auto it:chessVec)
	{
		
		if((it->getSide())&&(!(it->getDeaded()))){return false;}
	}
	return true;
}
bool GameLayer::examinewhitedead()
{
	for(auto it:chessVec)
	{
		int i=(int)it->getDeaded();
		//CCLOG("DEAD: %d",i);
		if((!it->getSide())&&(!(it->getDeaded()))){return false;}
	}
	return true;
}
bool GameLayer::onTouchBegan2(Touch *touch, Event *event){
	Point point=touch->getLocation();
	int x=point.x;
	int y=point.y;
	//CCLOG("x is %d ,y is %d",x,y);
	int rectnum=0;
	rectnum=whichRectContainsPoint(point);
	CCLOG("rectnum is %d" ,rectnum);
	//rect.containsPoint(point)
    //是否让电脑走
	//bool passside=false;

	if(rectnum){
		bool wuzi=true;
		auto it=chessVec.begin();
		for(auto it:chessVec){
			if(it->getState()==rectnum){
				if(!(it->getDeaded())){wuzi=false;currChess=it; break;}
			}
		}
		if(wuzi)
		{
			//CCLOG("WUZI");
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
			    //CCLOG(" %d %d %d %d",a1,a2,a3,a4);
			
				
				if(road){
					//清空悔棋数组
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
               // passside=true;
                
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
				if((currChess->getSide()==thisSide)){
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
	if(preChess){
		CCLOG("PRECHESS IS %d",preChess->getId());}
	//第一次检测死亡
	for(auto it:chessVec)
	{
		if((it->getState()!=-1)&&(!(it->getDui())))
		{
			examineDead(it);	
		}
	}
	if(examinebothdead()==1){endScene2(1);return true;}else if(examinebothdead()==2){endScene2(2);return true;}
	for(auto it:chessVec)
	{
		it->setDui(false);
	}
	//computer time
	

	return true;

}
bool GameLayer::endScene2(int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeAllEventListeners();

	Sprite* board=NULL;
	if(i==1){auto win=Sprite::create("whitewinitem.png");board=win;}else if(i==2){auto fail=Sprite::create("backwinitem.png");board=fail;}
	board->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height+200));
	auto moveto=MoveTo::create(0.5f,Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto easein=EaseOut::create(moveto,1.0f);
	this->addChild(board);
	board->runAction(easein);
	auto selectItem1=MenuItemImage::create("backitem.png","backitem.png",CC_CALLBACK_1(GameLayer::goback, this));
	auto selectItem2=MenuItemImage::create("reverseitem.png","reverseitem.png",CC_CALLBACK_1(GameLayer::reverse, this));
	if(i==1){
	selectItem1->setPosition(Vec2(71,50));
	selectItem2->setPosition(Vec2(213,50));}
	else if(i==2){
	selectItem1->setPosition(Vec2(71,50));
	selectItem2->setPosition(Vec2(213,50));
	}
	auto menu=Menu::create(selectItem1,selectItem2,NULL);
	menu->setPosition(Vec2::ZERO);
	board->addChild(menu,5);

	

	return true;
}
int  GameLayer::examinebothdead()
{
	int whodead=0;
	if(examineblackdead()){whodead=1;}
	if(examinewhitedead()){whodead=2;}
	return whodead;

}
void GameLayer::ui()	
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto doorback=MenuItemImage::create("doorback.png","doorback.png",CC_CALLBACK_1(GameLayer::goback, this));
	doorback->setPosition(origin.x+0.1*visibleSize.width,origin.y+0.87*visibleSize.height);
	//this->addChild(doorback,8);

	auto reverse=MenuItemImage::create("reverse.png","reverse.png",CC_CALLBACK_1(GameLayer::reverse,this));
	reverse->setPosition(origin.x+0.35*visibleSize.width,origin.y+0.12*visibleSize.height);
	//this->addChild(reverse);
	auto huiqi=MenuItemImage::create("huiqi.png","huiqi.png",CC_CALLBACK_1(GameLayer::huiqi,this));
	huiqi->setPosition(origin.x+0.59*visibleSize.width,origin.y+0.12*visibleSize.height);

	auto menu=Menu::create(doorback,reverse,huiqi,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,7);
}
void GameLayer::huiqi (Ref* pSender)
{
	if(canhuiqi)
	{
		for(auto it:preChessVec)
		{
			Point point=numToPoint(it->getPreState());
			it->setState(it->getPreState());
			it->setPosition(point);
			if(it->getDeaded()){it->setDeaded(false);}
		}
		
		canhuiqi=false;
		if(gamemode==2){
			thisSide=!thisSide;}
	}
}