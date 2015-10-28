#ifndef __TIAOZHAN_LAYER__
#define __TIAOZHAN_LAYER__

#include "cocos2d.h"
#include "GameLayer.h"
#include <vector>
#include "Fire.h"
USING_NS_CC;
class TiaozhanLayer:public GameLayer
{
public:
	//CREATE_FUNC(TiaozhanLayer);
	bool init();
	//��ǰ�ؿ�
	int _guan;
	//ͨ��
	void pass(Ref* pSender);
	void numToInit(int i);
	void reverse(Ref* pSender);
	//���ֽ̳�
	void guide(int i);
	//���ֹؿ�
	bool init_1();
	bool init_2();
	bool init_3();
	bool init_4();
	bool init_5();
	bool init_6();
	bool init_7();
	bool init_8();
	bool init_9();
	bool init_10();
	bool init_11();
	bool init_12();
	bool init_13();
	bool init_14();
	bool init_15();
	bool init_16();
	bool init_17();
	bool init_18();
	bool init_19();
	bool init_20();
	bool init_21();
	bool init_22();
	//�ؿ���ת
    void zhongzhuan();
	//������ֽ̳�
	bool onTouchBegan3(Touch *touch, Event *event);
	bool onTouchBegan4(Touch *touch, Event *event);
	bool onTouchBegan5(Touch *touch, Event *event);
	bool onTouchBegan6(Touch *touch, Event *event);

	static TiaozhanLayer* create(int guan);
	//
	void myui();
	int guidenum;
	bool endScene_CHU(int i);
	bool endScene_HUO(int i);
	bool endScene_Shade(int i);
	bool endScene_Mo(int i);
	bool tongguan(int i);
	//FIRE 
	bool redSide();
	bool shadeSide();
	bool moSide();
	vector<Fire*> fireVec;
	vector<Chess*> fireChessVec;
	void addFire(int num);
	void addFire(int num,int state);
	void addFire(vector<int> &vec);
	Fire* stateToFire(int state);
	void examineFireDead();
	void cleanFire();
	void killFire(int num);
	void firebreak();
	bool _firebreak;
	//Shade
	bool updateShade();
	vector<Chess*> shadeVec;
	void addShade(int num);
	vector<Chess*> shadeChessVec;
	bool kengexamine(int num,bool side);
	void examineDead(Chess* chess);
	
	

};




#endif //!__TIAOZHAN_LAYER__