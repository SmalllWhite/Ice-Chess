#ifndef __FIRE__
#define __FIRE__
#include "cocos2d.h"
USING_NS_CC;

class Fire:public Node
{
public:
	static Fire* create(int state);
	bool init();
	CC_SYNTHESIZE(int, _delay,Delay);
	CC_SYNTHESIZE(int,_state,State);

};




#endif //!__FIRE__