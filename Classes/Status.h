#ifndef __STATUS_H__
#define __STATUS_H__

#include "cocos2d.h"

class Status
{
public:
	Status(cocos2d::Layer *layer);
	void LevelUp();
	void ShowStatus(cocos2d::Layer *layer);
	void HideStatus(cocos2d::Layer *layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	int level;
	cocos2d::Label* levelTitleLabel;
	cocos2d::Label* levelLabel;
};

#endif //__STATUS_H__
