#ifndef __SHOP_SCENE_H__
#define __SHOP_SCENE_H__

#include "cocos2d.h"
#include "UI\UIEditBox\UIEditBox.h"

USING_NS_CC;
using namespace ui;

class Shop : public Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(Shop);
	void ShowItemList();

private:
	Size visibleSize;
	Vec2 origin;

	void BackToScene(cocos2d::Ref *pSender);
	void enterMessage(cocos2d::Ref *pSender);

	void MexchangeLottery(cocos2d::Ref *pSender);
	void MopenLottery(cocos2d::Ref *pSender);
	void exchangeLottery();
	void openLottery();
	int lotteryMoney;

	Label* itemLabel[10] = { 0, };
	char* itemLabelName[10] = { 0, };//아이템 이름
	int number[10] = { 0, };//아이템 개수
	int money;//돈
	Label* moneyLabel;
	Label* moneyNumberLabel;//돈 표시
	int itemPrice[10] = {100, 1000, 300,};
	Label* numberLabel[10] = { 0, };
	EditBox* editbox;
};

#endif // __HELLOWORLD_SCENE_H__
