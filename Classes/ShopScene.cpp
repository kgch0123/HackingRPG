#include "ShopScene.h"
#include "Definition.h"

USING_NS_CC;

Scene* Shop::createScene()
{
    auto scene = Scene::create();
    auto layer = Shop::create();
    scene->addChild(layer);
    return scene;
}

bool Shop::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	money = 10000;
	exchangeLottery();

	auto backItem = MenuItemFont::create("X", CC_CALLBACK_1(Shop::BackToScene, this));
	backItem->setPosition(Vec2(origin.x + visibleSize.width - 20, origin.y + visibleSize.height - 20));

	auto enterItem = MenuItemFont::create("enter", CC_CALLBACK_1(Shop::enterMessage, this));
	enterItem->setPosition(Vec2(origin.x + visibleSize.width - 40, origin.y + 80));

	auto randomLotteryItem = MenuItemFont::create("Exchange\nLottery", CC_CALLBACK_1(Shop::MexchangeLottery, this));
	randomLotteryItem->setPosition(Vec2(origin.x + visibleSize.width - 70, origin.y + 160));

	auto openLotteryItem = MenuItemFont::create("open\nLottery", CC_CALLBACK_1(Shop::MopenLottery, this));
	openLotteryItem->setPosition(Vec2(origin.x + visibleSize.width - 70, origin.y + 240));

	auto menu = Menu::create(backItem, enterItem, randomLotteryItem, openLotteryItem, NULL);
	menu->setPosition(origin);
	this->addChild(menu);

	moneyLabel = Label::createWithTTF("Money", "HACKED.ttf", 20);
	moneyLabel->setPosition(Vec2(origin.x + visibleSize.width - 70, origin.y + 300));
	moneyLabel->setColor(Color3B::RED);
	this->addChild(moneyLabel);

	__String *moneyString = __String::createWithFormat("%d", money);
	moneyNumberLabel = Label::createWithTTF(moneyString->getCString(), "HACKED.ttf", 20);
	moneyNumberLabel->setPosition(Vec2(moneyLabel->getPositionX(), moneyLabel->getPositionY() - 20));
	moneyNumberLabel->setColor(Color3B::RED);
	this->addChild(moneyNumberLabel);

	itemLabelName[0] = "POTION";
	itemLabelName[1] = "LOTTERY";
	itemLabelName[2] = "SWORD";

	for (int i = 0; i < 3; i++)
	{
		itemLabel[i] = Label::createWithTTF(itemLabelName[i], "HACKED.ttf", 35);
		itemLabel[i]->setPosition(Vec2(origin.x + 20 + itemLabel[i]->getContentSize().width / 2,
			origin.y - 30 + visibleSize.height - i * (itemLabel[i]->getContentSize().height)));
		itemLabel[i]->setColor(Color3B::RED);
		this->addChild(itemLabel[i]);

		__String *tempString = __String::createWithFormat("%d", number[i]);
		numberLabel[i] = Label::createWithTTF(tempString->getCString(), "HACKED.ttf", 35);
		numberLabel[i]->setPosition(Vec2(visibleSize.width / 2, itemLabel[i]->getPositionY()));
		numberLabel[i]->setColor(Color3B::RED);
		this->addChild(numberLabel[i]);
	}

	editbox = EditBox::create(Size(visibleSize.width, 50), Scale9Sprite::create("MagentaSquare.png"));
	editbox->setPosition(Vec2(origin.x + editbox->getContentSize().width / 2, origin.y + editbox->getContentSize().height / 2));
	editbox->setPlaceHolder("Enter in HERE : ");
	editbox->setMaxLength(20);
	editbox->setPlaceholderFontColor(Color3B::GREEN);
	editbox->setFontColor(Color3B::BLUE);

	editbox->setReturnType(EditBox::KeyboardReturnType::SEARCH);
	editbox->setInputMode(EditBox::InputMode::ANY);
	this->addChild(editbox);

    return true;
}

void Shop::BackToScene(cocos2d::Ref *pSender)
{
	Director::getInstance()->popScene();
}

void Shop::enterMessage(cocos2d::Ref *pSender)
{
	char* tmpString = (char*)editbox->getText();
	CCLOG("tmpString %s", tmpString);
	char* message[3];

	//" "문자열이 나오면 자른다
	//strtok_s를 쓰는 걸 권장(strtok()취약할 수 있음)
	message[0] = strtok(tmpString, " ,");
	message[1] = strtok(NULL, " ,");
	message[2] = strtok(NULL, " ,");
	CCLOG("message0 %s", message[0]);
	CCLOG("message1 %s", message[1]);
	CCLOG("message2 %s", message[2]);

	//type0 type1 type2 
	//buy potion 3
	int type0 = -1, type1 = -1, type2 = -1;

	if ( message[0] && message[1] && message[2])
	{
		//strcmp취약할 수 있음
		//type0
		if (!strcmp("BUY", message[0]))
		{
			type0 = BUY;
		}
		else if (!strcmp("SELL", message[0]))
		{
			type0 = SELL;
		}

		//type1
		for (int i = 0; i < 3; i++)
		{
			if (!strcmp(itemLabelName[i], message[1]))
			{
				type1 = i;
				break;
			}
		}

		//atoi
		//type2
		type2 = atoi(message[2]);

		//오류 있으면 -1
		CCLOG("type0 %d", type0);
		CCLOG("type1 %d", type1);
		CCLOG("type2 %d", type2);
		//money가 지불해야 할 양보다 적은지 판단
		if (type0 == BUY && type1 >= 0 && type2 >= 0 && money - itemPrice[type1] * type2 >= 0)
		{
			money -= itemPrice[type1] * type2;
			number[type1] += type2;
		}
		else if (type0 == SELL && type1 >= 0 && type2 >= 0)
		{
			money += itemPrice[type1] * type2;
			number[type1] -= type2;
		}
		ShowItemList();
	}
}

//아이템 개수 갱신
void Shop::ShowItemList()
{
	__String *moneyString = __String::createWithFormat("%d", money);
	moneyNumberLabel->setString(moneyString->getCString());
	for (int i = 0; i < 3; i++)
	{
		__String *tempString = __String::createWithFormat("%d", number[i]);
		numberLabel[i]->setString(tempString->getCString());
	}
}

void Shop::MexchangeLottery(cocos2d::Ref *pSender)
{
	exchangeLottery();
}


void Shop::MopenLottery(cocos2d::Ref *pSender)
{
	openLottery();
}

void Shop::exchangeLottery()
{
	if (number[1] > 0)
	{
		float randomValue = CCRANDOM_0_1();
		if (randomValue > 0.9)
			lotteryMoney = 100000;
		else if (randomValue > 0.7)
			lotteryMoney = 10000;
		else if (randomValue > 0.5)
			lotteryMoney = 1000;
		else
			lotteryMoney = 5;
		//랜덤값 확인
		CCLOG("lotteryMoney : %d", lotteryMoney);
	}
	else
		CCLOG("lotteryMoney : %d not changed", lotteryMoney);
}
void Shop::openLottery()
{
	if (number[1] > 0)
	{
		money += lotteryMoney;
		number[1]--;
		ShowItemList();
		exchangeLottery();
	}
}