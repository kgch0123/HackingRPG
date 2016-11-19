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

	auto backItem = MenuItemFont::create("X", CC_CALLBACK_1(Shop::BackToScene, this));
	backItem->setPosition(Vec2(origin.x + visibleSize.width - 20, origin.y + visibleSize.height - 20));

	auto enterItem = MenuItemFont::create("enter", CC_CALLBACK_1(Shop::enterMessage, this));
	enterItem->setPosition(Vec2(origin.x + visibleSize.width - 40, origin.y + 80));

	auto menu = Menu::create(backItem, enterItem, NULL);
	menu->setPosition(origin);
	this->addChild(menu);

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
		if (type0 == BUY && type1 >= 0 && type2 >= 0)
		{
			number[type1] += type2;
		}
		else if (type0 == SELL && type1 >= 0 && type2 >= 0)
		{
			number[type1] -= type2;
		}
		ShowItemList();
	}
}

//아이템 개수 갱신
void Shop::ShowItemList()
{
	for (int i = 0; i < 3; i++)
	{
		__String *tempString = __String::createWithFormat("%d", number[i]);
		numberLabel[i]->setString(tempString->getCString());
	}
}