#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
using namespace cocostudio;
using namespace cocos2d::ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//加载UI界面
	auto loginBack = GUIReader::getInstance()->widgetFromJsonFile("Login/DemoLogin.json");
	this->addChild(loginBack);

	auto login_Button = (Button*)loginBack->getChildByName("login_Button");
	login_Button->addTouchEventListener(this, toucheventselector(HelloWorld::touchButton));

	//加载Animation动画
	ArmatureDataManager::getInstance()->addArmatureFileInfo("NewAnimation/NewAnimation0.png", "NewAnimation/NewAnimation0.plist", "NewAnimation/NewAnimation.ExportJson");
	auto armature = Armature::create("NewAnimation");
	armature->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	armature->getAnimation()->play("Animation");
	this->addChild(armature);
    return true;
}

void HelloWorld::touchButton(cocos2d::Object* object, cocos2d::ui::TouchEventType type)
{
	auto button = (Button*)object;
	auto tag = button->getName();
	switch (type)
	{
	case TOUCH_EVENT_BEGAN:
		CCLOG("%s --Button Down", tag.c_str());
		break;
	case TOUCH_EVENT_ENDED:
		CCLOG("%s --Button Up", tag.c_str());
		break;
	default:
		break;
	}
}