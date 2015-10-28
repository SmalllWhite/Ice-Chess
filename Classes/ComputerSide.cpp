#include "ComputerSide.h"
#include <vector>
#include "cocos2d.h"
#include "Chess.h"
#include "GameLayer.h"
USING_NS_CC;
using namespace std;
ComputerSide::ComputerSide (vector<Chess*> &chessvec)
{
	_chessvec=chessvec;
}
bool ComputerSide::init()
{
	//先把黑白分开
	for(auto i:_chessvec)
	{
		if(i->getSide()){_whitechessvec.push_back(i);}
		else{_blackchessvec.push_back(i);}
	}
	//
	return true;

}
