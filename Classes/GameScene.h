#include"cocos2d.h"
#include"GameLayer.h"
#include "OperatorLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class GameScene: public CCScene{
public:
	GameScene(void);
	~GameScene(void);
	virtual bool init();
	CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
	CC_SYNTHESIZE(OperatorLayer*, operatorLayer, OperatorLayer);
	CREATE_FUNC(GameScene);
};