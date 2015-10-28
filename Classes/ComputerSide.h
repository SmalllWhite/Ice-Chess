#ifndef __COMPUTER_SIDE__
#define __COMPUTER_SIDE__
#include "GameLayer.h"
#include "cocos2d.h"
#include "Chess.h"
#include <vector>
#include "chessdui.h"
using namespace std;
USING_NS_CC;
class ComputerSide{
public:
	ComputerSide(vector<Chess*> &chessvec);
	vector<Chess*> _chessvec;
	bool init();
	vector<Chess*> duistar(Chess* chess,vector<int> &aroundvec);
private:
	vector<Chess*> _whitechessvec;
	vector<Chess*> _blackchessvec;
	vector<chessdui*> _whitechessduis;
	vector<chessdui*> _blackchessduis;

};



#endif /!__COMPUTER_SIDE__