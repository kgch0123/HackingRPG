#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "MapGrid.h"

class Player
{
public:
	Player();
	void SpawnPlayer(cocos2d::Layer *layer);
	void SpawnMonster(cocos2d::Layer *layer);
	void UpWalking(cocos2d::Layer *layer);
	void LeftWalking(cocos2d::Layer *layer);
	void DownWalking(cocos2d::Layer *layer);
	void RightWalking(cocos2d::Layer *layer);
	void UpWalkAnimation();
	void LeftWalkAnimation();
	void DownWalkAnimation();
	void RightWalkAnimation();
	void setMap(MapGrid mapGrid);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* playerSprite;
	cocos2d::Vector<cocos2d::SpriteFrame*> upWalkFrame;
	cocos2d::Vector<cocos2d::SpriteFrame*> downWalkFrame;
	cocos2d::Vector<cocos2d::SpriteFrame*> leftWalkFrame;
	cocos2d::Vector<cocos2d::SpriteFrame*> rightWalkFrame;
	cocos2d::Animate* upAnimate;
	cocos2d::Animate* downAnimate;
	cocos2d::Animate* leftAnimate;
	cocos2d::Animate* rightAnimate;
};

#endif //__PLAYER_H__
