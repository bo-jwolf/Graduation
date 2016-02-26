﻿#include"GameLayer.h"

GameLayer::GameLayer() :
	tilemap( NULL )
{
	GlobalCtrl::getInstance();
}
GameLayer::~GameLayer(void){
	CCNotificationCenter::sharedNotificationCenter()->removeObserver(this,"Attack");
};

bool GameLayer::init(){
	if(!CCLayer::init())
		return false;
	this->initTileMap();
	this->addShana();
	this->addOgre();
	this->addLabel();
	//启动updata事件
	//this->scheduleUpdate();
	//注册Message，如果接收到了，执行ObserverFunction  
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(GameLayer::ObserverFunction),"Attack",NULL);  
	return true;
};
void GameLayer::addLabel(){
	//标签上显示是否发生了碰撞
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	label=CCLabelTTF::create("NOT COLLUSION", "American Typewriter.ttf", 30);
    label->setPosition(ccp(visibleSize.width/2,visibleSize.height*0.7));
    this->addChild(label);
}

void GameLayer::initTileMap(){
	tilemap = CCTMXTiledMap::create("tilemap.tmx");
	CCObject *pObject = NULL;
	CCARRAY_FOREACH(tilemap->getChildren(), pObject){
		CCTMXLayer *child = (CCTMXLayer*)pObject;
		child->getTexture()->setAliasTexParameters();
	}
	GlobalCtrl::getInstance()->tilemap = tilemap;
	this->addChild(tilemap, -10);
};

void GameLayer::ObserverFunction(CCObject * object){
	bool flag = false;
    CCLOG("SecondLayer Receive num=%d",(int)object); 
	  CCLOG("update enter hurt 3");
	    if(abs(shana->getPositionY()-ogre->getPositionY())<30){
			CCLOG("update enter hurt 1");
			if(shana->getHitBox().intersectsRect(CCRectMake(ogre->getPositionX(), ogre->getPositionY(),
				ogre->GetSprite()->getContentSize().width, ogre->GetSprite()->getContentSize().height)))
			{
				 CCLOG("update enter hurt ");
				ogre->isHurt = true;
				ogre->isAttack = true;
				ogre->HurtAnimation();
				flag = true;
	         }
	     //}
	  //}
	}
	/*
	CCLOG("==============>>>>>>>>>>>>>>>>>>>>> shanabox %f %f %f %f", shana->getHitBox().getMinX(), shana->getHitBox().getMaxX(), shana->getHitBox().getMinY(), shana->getHitBox().getMaxY());	
	CCLOG("==============>>>>>>>>>>>>>>>>>>>>> shanabox %f %f %f %f", ogre->getPositionX() - ogre->GetSprite()->getContentSize().width / 2, ogre->getPositionX() + ogre->GetSprite()->getContentSize().width /2,
		ogre->getPositionY()-ogre->GetSprite()->getContentSize().height / 2, ogre->getPositionY()+ogre->GetSprite()->getContentSize().height / 2);*/
	if (flag) {
        label->setString("IS COLLUSION11111111111111111");
    }else{
        label->setString("NOT COLLUSION11111111111111111");
    }
}  

void GameLayer::addShana() {
	CCTMXTiledMap* map = GlobalCtrl::getInstance()->tilemap;
	CCTMXObjectGroup*  objectGroup = map->objectGroupNamed( "Role");
	CCDictionary* obj = objectGroup->objectNamed( "shana" );

	shana = Shana::create();
	shana->setPosition( CCPoint(
		((CCString*) obj->objectForKey("x"))->floatValue() - 100, 
		((CCString*) obj->objectForKey("y"))->floatValue()+shana->getSprite()->getContentSize().height/2 ));
	this->addChild( shana );
	GlobalCtrl::getInstance()->shana = shana;
	shana->StartListen();
}

void GameLayer::addOgre() {
	CCTMXTiledMap* map = GlobalCtrl::getInstance()->tilemap;
	CCTMXObjectGroup*  objectGroup = map->objectGroupNamed( "Role");
	CCDictionary* obj = objectGroup->objectNamed( "shana" );
	ogre = Ogre::create();
	this->addChild( ogre );
	ogre->setPosition(shana->getPositionX() + 200, shana->getPositionY());
	CCSize visibleSize = CCEGLView::sharedOpenGLView()->getVisibleSize();
	ogre -> StartListen();
}