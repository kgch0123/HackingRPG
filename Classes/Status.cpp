#include "Status.h"
#include "Definition.h"

USING_NS_CC;

Status::Status(cocos2d::Layer *layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	level = 0;

	levelTitleLabel = Label::createWithTTF("Level", "UbuntuMono-B.ttf", 35);
	levelTitleLabel->setPosition(Vec2(origin.x + visibleSize.width - levelTitleLabel->getContentSize().width,
		origin.y + visibleSize.height - levelTitleLabel->getContentSize().height));
	levelTitleLabel->setColor(Color3B::BLACK);
	layer->addChild(levelTitleLabel);


	char levelString[20];
	sprintf(levelString, "%d", level);
	levelLabel = Label::createWithTTF(levelString, "HACKED.ttf", 35);
	levelLabel->setPosition(Vec2(levelTitleLabel->getPositionX(), levelTitleLabel->getPositionY()
		- levelTitleLabel->getContentSize().height));
	levelLabel->setColor(Color3B::RED);
	//levelLabel->enableGlow(Color4B::RED);
	levelLabel->enableShadow(Color4B::BLACK);
	layer->addChild(levelLabel);
}

void Status::LevelUp()
{
	level += 10000;

	char levelString[20];
	sprintf(levelString, "%d", level);
	levelLabel->setString(levelString);
}
void Status::ShowStatus(cocos2d::Layer *layer)
{
	

}

void Status::HideStatus(cocos2d::Layer *layer)
{

}

void Status::SaveAllData() {
	FILE *fo = fopen("game.sav","w");
	int save_level = level ^ 12345678;
	fprintf(fo,"%d\n", save_level);
	fclose(fo);
}