#ifndef __MAPGRID_H__
#define __MAPGRID_H__

#include "cocos2d.h"

class MapGrid
{
public:
	MapGrid();
	void MakeMap(cocos2d::Layer *layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* mapSprite[200];
};

#endif //__MAPGRID_H__
