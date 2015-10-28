#ifndef __GAME_LAYER__
#define __GAME_LAYER__
#include "cocos2d.h"
#include "Chess.h"
#include "public.h"
#include <vector>
#include "chessdui.h"
using namespace std;
USING_NS_CC;
class GameLayer : public cocos2d::Layer
{ 
public :
	bool init();
	static GameLayer* create(int gamemode);
	GameLayer();
	
	//TOUCHCHESS
	//何种游戏模式
	
	int gamemode;
	bool vecIncludeChess(vector<Chess*> &vec,Chess* chess);
	bool qinclude(int *q,int num);
	bool vecinclude(vector<int> &vec,int i);
	void touchChess();
	void passTouch();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual bool onTouchBegan2(cocos2d::Touch *touch, cocos2d::Event *event);
	Chess* preChess;
	Chess* currChess;
	//悔棋功能
	vector<Chess*> preChessVec;
	bool canhuiqi;
	void huiqi(Ref* pSender);

	int whichRectContainsPoint(Point point);
	bool onceTouch;
	void initaroundVec();
	void examineDead(Chess* chess);
	void examineDeads();
	Chess* stateToChess(int state);
	Chess* idToChess(int id);
	int* stateToAround(int state);
	vector<int> statesToArounds(vector<int> &states);
	vector<int> statesToKongArounds(vector<int> &states);
	bool stateHasChess(int state,bool &side,bool &issameside);
	bool stateHasChess(int state);
	vector<Chess*> dui(Chess* chess,vector<int> &q);
	//重载dui
	vector<Chess*> dui(Chess* chess,vector<Chess*>&p,vector<int> &q);
	//computerside
	bool thisSide;
	bool blackSide();
	int examinekeng();
	vector<chessdui*> blackduis;
	vector<chessdui*> whiteduis;
	bool examineblackdead();
	bool examinewhitedead();
	int examinebothdead();
	//结束界面
	bool endScene(int i);
	bool endScene2(int i);
	void reverse(Ref* pSender);
	void goback(Ref* pSender);
	//界面UI
	void ui();
	vector<Chess*> testvec;
	vector<Chess*> chessVec;

	int _preTouch;
	int _currTouch;
	int _soundId;
	//vector<int*> aroundVec;
	
};
#endif //!__GAME_LAYER__