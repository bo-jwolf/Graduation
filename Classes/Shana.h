#pragma once

#include "Role.h"

enum SkillState {
	SKILL_NULL = 0,
	SKILL_A,
	SKILL_B,
	SKILL_C,
	SKILL_D
};

class Shana : public Role{
public:
	Shana();
	~Shana();
	virtual bool init();
	CREATE_FUNC( Shana );

	//void onMove( Vec2 direction, float distance );
	//void onMove( CCPoint direction, float distance );
	void onStop();

	CC_SYNTHESIZE( SkillState, _curSkillState, CurSkillState );
	CC_SYNTHESIZE( bool, _canMutilAtk, CanMutilAttack );

	virtual void runSkillAAnimation();
	virtual void runSkillBAnimation();
	virtual void runSkillCAnimation();
	virtual void runSkillDAnimation();
	virtual void runSkillEAnimation( );

private:
	void updateBox();
	virtual void update( float delta );
	void updateSelf();
	//bool getDirectionFlipX();
	//void centerViewOfPoint( Vec2 pos );
	void centerViewOfPoint( CCPoint pos );
	//void attackCallbackFunc( Node* pSender );
	void attackCallbackFunc( CCNode* pSender );
};
