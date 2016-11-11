#include "MapGrid.h"
#include "Definition.h"
#include <stdio.h>

USING_NS_CC;

MapGrid::MapGrid()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}

void MapGrid::MakeMap(cocos2d::Layer *layer)
{	
	char buf[MAP_WIDTH*MAP_HEIGHT*2 + 1] = { 0 };

	FILE *fp = fopen("./MapData", "r");

	if (!fp)
	{
		CCLOG("can not open file %s", "MapData");
		return;
	}

	fgets(buf, MAP_WIDTH*MAP_HEIGHT*2 + 1, fp);
	//CCLOG("read content %s", buf);

	fclose(fp);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			mapSprite[i*MAP_WIDTH + j] = Sprite::create("MapTiles.png",
				Rect((buf[(i*MAP_WIDTH + j)*2] - '0') * GRID_SIZE, (buf[(i*MAP_WIDTH + j)*2+1] - '0') * GRID_SIZE, GRID_SIZE, GRID_SIZE));
			mapSprite[i*MAP_WIDTH + j]->setPosition(Vec2(origin.x + j*GRID_SIZE + GRID_SIZE / 2, origin.y + i*GRID_SIZE + GRID_SIZE / 2));
			layer->addChild(mapSprite[i*MAP_WIDTH + j]);
			CCLOG("i : %d j : %d buf1: %d buf2: %d", i, j, buf[(i*MAP_WIDTH + j) * 2], buf[(i*MAP_WIDTH + j) * 2 + 1]);
		}
	}
}