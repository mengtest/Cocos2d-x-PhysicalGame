#include "PhysicalsScene.h"
USING_NS_CC;

Scene* PhysicalsScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics(); // ����������
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //�������Բ���
    
    // 'layer' is an autorelease object
	auto layer = PhysicalsScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

	layer->setPhyWorld(scene->getPhysicsWorld());
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PhysicalsScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	this->setTouchEnabled(true);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�������ĺ��Ӹ��壬��Ϊ��Ϸ����߽�
	//�����ֱ��Ǹ����С�����ʡ����ߺ��
	auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);

	auto edgeSp = Sprite::create();
	edgeSp->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	edgeSp->setPhysicsBody(body);
	edgeSp->setTag(0);

	this->addChild(edgeSp);
    return true;
}

void PhysicalsScene::setPhyWorld(cocos2d::PhysicsWorld* world)
{
	m_world = world;
}

void PhysicalsScene::addNewSpriteAtPosition(cocos2d::Point pos)
{
	auto sp = Sprite::create("player.png");
	sp->setTag(1);
	auto body = PhysicsBody::createBox(Size(78, 50));
	sp->setPhysicsBody(body);
	sp->setPosition(pos);
	this->addChild(sp);
}

bool PhysicalsScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto location = touch->getLocation();
	addNewSpriteAtPosition(location);
	return true;
}


