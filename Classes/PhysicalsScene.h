#ifndef __PHYSICALS_SCENE_H__
#define __PHYSICALS_SCENE_H__

#include "cocos2d.h"

class PhysicalsScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    // implement the "static create()" method manually
	CREATE_FUNC(PhysicalsScene);

	void setPhyWorld(cocos2d::PhysicsWorld* world);

	void addNewSpriteAtPosition(cocos2d::Point pos);

private:
	cocos2d::PhysicsWorld* m_world;
};

#endif // __PHYSICALS_SCENE_H__
