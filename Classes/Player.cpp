#include "Player.h"
#include "Definition.h"

USING_NS_CC;

Player::Player()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	upWalkFrame.reserve(6);
	downWalkFrame.reserve(6);
	leftWalkFrame.reserve(6);
	rightWalkFrame.reserve(6);
	for (int i = 0; i < 6; i++) {
		downWalkFrame.pushBack(SpriteFrame::create("Sprite_claudius_walk.png", Rect(GRID_SIZE*(i % 6), GRID_SIZE * 2 * 0, GRID_SIZE, GRID_SIZE * 2)));
		upWalkFrame.pushBack(SpriteFrame::create("Sprite_claudius_walk.png", Rect(GRID_SIZE*(i % 6), GRID_SIZE * 2 * 1, GRID_SIZE, GRID_SIZE * 2)));
		leftWalkFrame.pushBack(SpriteFrame::create("Sprite_claudius_walk.png", Rect(GRID_SIZE*(i % 6), GRID_SIZE * 2 * 2, GRID_SIZE, GRID_SIZE * 2)));
		rightWalkFrame.pushBack(SpriteFrame::create("Sprite_claudius_walk.png", Rect(GRID_SIZE*(i % 6), GRID_SIZE * 2 * 3, GRID_SIZE, GRID_SIZE * 2)));
	}
	
	
	
	
}

void Player::SpawnPlayer(cocos2d::Layer *layer)
{
	playerSprite = Sprite::create("Sprite_claudius_walk.png", Rect(0, 0, GRID_SIZE, GRID_SIZE * 2));
	playerSprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
	layer->addChild(playerSprite);
}


void Player::UpWalking(cocos2d::Layer *layer)
{
	playerSprite->setPosition(playerSprite->getPositionX(), playerSprite->getPositionY() + PLAYER_WALK_SPEED_PER_FRAME_TIME);
}

void Player::LeftWalking(cocos2d::Layer *layer)
{
	playerSprite->setPosition(playerSprite->getPositionX() - PLAYER_WALK_SPEED_PER_FRAME_TIME, playerSprite->getPositionY());
	
}

void Player::DownWalking(cocos2d::Layer *layer)
{
	playerSprite->setPosition(playerSprite->getPositionX(), playerSprite->getPositionY() - PLAYER_WALK_SPEED_PER_FRAME_TIME);
}

void Player::RightWalking(cocos2d::Layer *layer)
{
	playerSprite->setPosition(playerSprite->getPositionX() + PLAYER_WALK_SPEED_PER_FRAME_TIME, playerSprite->getPositionY());
}


void Player::UpWalkAnimation()
{
	playerSprite->stopAllActions();
	Animation* upWalkAnimation = Animation::createWithSpriteFrames(upWalkFrame, PLAYER_WALK_FRAMERATE);
	upAnimate = Animate::create(upWalkAnimation);
	playerSprite->runAction(RepeatForever::create(upAnimate));
}
void Player::LeftWalkAnimation()
{
	playerSprite->stopAllActions();
	Animation* leftWalkAnimation = Animation::createWithSpriteFrames(leftWalkFrame, PLAYER_WALK_FRAMERATE);
	leftAnimate = Animate::create(leftWalkAnimation);
	playerSprite->runAction(RepeatForever::create(leftAnimate));
}
void Player::DownWalkAnimation()
{
	playerSprite->stopAllActions();
	Animation* downWalkAnimation = Animation::createWithSpriteFrames(downWalkFrame, PLAYER_WALK_FRAMERATE);
	downAnimate = Animate::create(downWalkAnimation);
	playerSprite->runAction(RepeatForever::create(downAnimate));
}
void Player::RightWalkAnimation()
{
	playerSprite->stopAllActions();
	Animation* rightWalkAnimation = Animation::createWithSpriteFrames(rightWalkFrame, PLAYER_WALK_FRAMERATE);
	rightAnimate = Animate::create(rightWalkAnimation);
	playerSprite->runAction(RepeatForever::create(rightAnimate));
}