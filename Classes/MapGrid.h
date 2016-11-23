#ifndef __MAPGRID_H__
#define __MAPGRID_H__

#include "cocos2d.h"
#include "Definition.h"

class MapGrid
{
public:
	MapGrid();
	void MakeMap(cocos2d::Layer *layer);
	void getMap(int map[][MAP_HEIGHT]);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* mapSprite[200];
	int MAP[MAP_WIDTH][MAP_HEIGHT];
};

#endif //__MAPGRID_H__
