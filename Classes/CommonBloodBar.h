#include"cocos2d.h"

USING_NS_CC;

class CommonBloodBar:public CCNode{
public:
	CommonBloodBar();
	~CommonBloodBar();
	virtual bool init();
	void setRedBloodBar(int num);
	void setRedBloodBarType(bool flag);
	CREATE_FUNC(CommonBloodBar);
private:
	CCProgressTimer *redBloodProgress;
	CCSprite* heroIcon;
	CCSprite* monsterIcon;
};