#include "HelloWorldScene.h"
#include "Definition.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mapGrid.MakeMap(this);
	player.SpawnPlayer(this);

	auto Klistener = EventListenerKeyboard::create();
	Klistener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	Klistener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Klistener, this);

    return true;
}

void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
		this->schedule(schedule_selector(HelloWorld::UpWalking), PLAYER_WALK_FRAME_TIME);
		player.UpWalkAnimation();
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
		this->schedule(schedule_selector(HelloWorld::LeftWalking), PLAYER_WALK_FRAME_TIME);
		player.LeftWalkAnimation();
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
		this->schedule(schedule_selector(HelloWorld::DownWalking), PLAYER_WALK_FRAME_TIME);
		player.DownWalkAnimation();
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
		this->schedule(schedule_selector(HelloWorld::RightWalking), PLAYER_WALK_FRAME_TIME);
		player.RightWalkAnimation();
		break;
	}
}

void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
		this->unschedule(schedule_selector(HelloWorld::UpWalking));
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
		this->unschedule(schedule_selector(HelloWorld::LeftWalking));
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
		this->unschedule(schedule_selector(HelloWorld::DownWalking));
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
		this->unschedule(schedule_selector(HelloWorld::RightWalking));
		break;
	}
}

void HelloWorld::UpWalking(float dt)
{
	player.UpWalking(this);
}

void HelloWorld::LeftWalking(float dt)
{
	player.LeftWalking(this);
}

void HelloWorld::DownWalking(float dt)
{
	player.DownWalking(this);
}

void HelloWorld::RightWalking(float dt)
{
	player.RightWalking(this);
}