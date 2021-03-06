#include"cocos2d.h"
#include"Ogre.h"
#include "Shana.h"
#include "GlobalCtrl.h"
#include"cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
class GameLayer:public CCLayer{
private:
	cocos2d::CCSprite*		m_pBG;
	CCTMXTiledMap* tilemap;
	void addShana();
	void addOgre();
	void updateMonster(float delta);
	//void update(float delta);
	
	int killnum;
	int rolehight;
	int currentLevel;
	bool startGamevisible;
	CCArmature*	m_pVIP;
	//CFrontground*			m_pCFrontgroud;
public:
	GameLayer(void);
	~GameLayer(void);
	void initTileMap(int level);
	virtual bool init();
    void ObserverFunction(CCObject * object);
	void startMonsterlist(bool visible);//开启所有怪物监听
	Ogre* ogre;
	Shana* shana;
	int getkillnum();
	CCArray* ogreArray;
	void output();
	cocos2d::CCArray*		m_pMonsterArray;
	void StartGameLevel(int _level, int _difficult);
	int GetMapNums();//地图数目
	CREATE_FUNC(GameLayer);
};