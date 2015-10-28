#include "public.h"
#include "cocos2d.h"
USING_NS_CC;

Point numToPoint(int num)

{
	Point point;
	switch (num)
	{
	case 1:point=POINT_1;break;
	case 2:point=POINT_2;break;
	case 3:point=POINT_3;break;
	case 4:point=POINT_4;break;
	case 5:point=POINT_5;break;
	case 6:point=POINT_6;break;
	case 7:point=POINT_7;break;
	case 8:point=POINT_8;break;
	case 9:point=POINT_9;break;
	case 10:point=POINT_10;break;
	case 11:point=POINT_11;break;
	case 12:point=POINT_12;break;
	case 13:point=POINT_13;break;
	case 14:point=POINT_14;break;
	case 15:point=POINT_15;break;
	case 16:point=POINT_16;break;
	case 17:point=POINT_17;break;
	case 18:point=POINT_18;break;
	case 19:point=POINT_19;break;
	case 20:point=POINT_20;break;
	case 21:point=POINT_21;break;
	default:
		break;
	}
	return point;


}