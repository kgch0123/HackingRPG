#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "MapGrid.h"
#include "Status.h"


class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

private:
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void UpWalking(float dt);
	void LeftWalking(float dt);
	void DownWalking(float dt);
	void RightWalking(float dt);
	void LevelUp(float dt);

	Player player;
	MapGrid mapGrid;
	Status* status;
};

#endif // __HELLOWORLD_SCENE_H__
