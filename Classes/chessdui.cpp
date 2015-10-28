#include "chessdui.h"
#include "Chess.h"

chessdui::chessdui(vector<Chess*> &duiStates,vector<Chess*> &aroundchess,vector<int> &duiAround)
{
	_duiStates=duiStates;
	_duiArounds=duiAround;
	_aroundChess=aroundchess;
	init();
}
bool chessdui::init()
{
	statenumber=_duiStates.size();
	qi=_duiArounds.size();
	return true;
}