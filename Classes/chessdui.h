#ifndef __CHESS_DUI__
#define __CHESS_DUI__
#include "public.h"
#include <vector>
#include "Chess.h"
using namespace std;

class chessdui
{
public:
	chessdui(vector<Chess*> &duiStates,vector<Chess*> &aroundchess,vector<int> &duiAround);
	bool init();
	vector<Chess*> _duiStates;
	vector<int> _duiArounds;
	vector<Chess*> _aroundChess;
	int breath;
	int statenumber;

	int qi;


};






#endif //!__CHESS_DUI__