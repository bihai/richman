//
//  MenuScene.cpp
//  richman
//
//  Created by yuhan zhang on 12/24/14.
//
//

#include "MenuScene.h"

USING_NS_CC;
using namespace ui;
using namespace extension;

#define BTN_WIDTH 200
#define BTN_HEIGHT 100
#define BTN_SINGLE_GAME_TAG 1
#define BTN_MULTI_GAME_TAG 2
#define BTN_MUSIC_TAG 3
#define BTN_QUIT_TAG 4

Scene* MenuScene::createScene(){
    auto scene = Scene::create();
    
    auto layer = MenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init(){
    if(!LayerColor::initWithColor(Color4B(255,255,255,255))){
        return false;
    }
    music_on=true;
    visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    addBGSprite();
    addMenuSprite();
    
    return true;
}

void MenuScene::addBGSprite(){
    
}

void MenuScene::addMenuSprite(){
        CCLOG("add child");
    Scale9Sprite* btnNormal1 = Scale9Sprite::create("CloseNormal.png");
    Scale9Sprite* btnPress1 = Scale9Sprite::create("CloseSelected.png");
    
    LabelTTF* singleGameTTF = LabelTTF::create("single game", "Marker Felt.ttf", 30);
    ControlButton* singleGameBtn = ControlButton::create(singleGameTTF, btnNormal1);
    
    singleGameBtn->setBackgroundSpriteForState(btnPress1, Control::State::SELECTED);
    singleGameBtn->setPosition(Point(visiableSize.width/2,visiableSize.height/2 + 100));
    singleGameBtn->setPreferredSize(Size(BTN_WIDTH,BTN_HEIGHT));
    singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::MenuTouchDown), Control::EventType::TOUCH_DOWN);
    singleGameBtn->setTag(BTN_SINGLE_GAME_TAG);
    this->addChild(singleGameBtn);
    
    Scale9Sprite* btnNormal2 = Scale9Sprite::create("CloseNormal.png");
    Scale9Sprite* btnPress2 = Scale9Sprite::create("CloseSelected.png");
    
    LabelTTF* multiGameTTF = LabelTTF::create("multiple game", "Marker Felt.ttf", 30);
    ControlButton* multiGameBtn = ControlButton::create(multiGameTTF, btnNormal2);
    
    multiGameBtn->setBackgroundSpriteForState(btnPress2, Control::State::SELECTED);
    multiGameBtn->setPosition(Point(visiableSize.width/2,visiableSize.height/2));
    multiGameBtn->setPreferredSize(Size(BTN_WIDTH,BTN_HEIGHT));
    multiGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::MenuTouchDown), Control::EventType::TOUCH_DOWN);
    multiGameBtn->setTag(BTN_MULTI_GAME_TAG);
    this->addChild(multiGameBtn);
    
    
    Scale9Sprite* btnNormal3 = Scale9Sprite::create("CloseNormal.png");
    Scale9Sprite* btnPress3 = Scale9Sprite::create("CloseSelected.png");
    
    LabelTTF* settingsTTF;
    if(music_on){
        settingsTTF = LabelTTF::create("music on", "Marker Felt.ttf", 30);
    }
    else{
        settingsTTF = LabelTTF::create("music off", "Marker Felt.ttf", 30);
    }
    ControlButton* settingsBtn = ControlButton::create(settingsTTF, btnNormal3);
    
    settingsBtn->setBackgroundSpriteForState(btnPress3, Control::State::SELECTED);
    settingsBtn->setPosition(Point(visiableSize.width/2,visiableSize.height/2 - 100));
    settingsBtn->setPreferredSize(Size(BTN_WIDTH,BTN_HEIGHT));
    settingsBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::MenuTouchDown), Control::EventType::TOUCH_DOWN);
    settingsBtn->setTag(BTN_MUSIC_TAG);
    this->addChild(settingsBtn);
    
    
    Scale9Sprite* btnNormal4 = Scale9Sprite::create("CloseNormal.png");
    Scale9Sprite* btnPress4 = Scale9Sprite::create("CloseSelected.png");
    
    LabelTTF* quitGameTTF = LabelTTF::create("quit game", "Marker Felt.ttf", 30);
    ControlButton* quitGameBtn = ControlButton::create(quitGameTTF, btnNormal4);
    
    quitGameBtn->setBackgroundSpriteForState(btnPress4, Control::State::SELECTED);
    quitGameBtn->setPosition(Point(visiableSize.width/2,visiableSize.height/2 - 200));
    quitGameBtn->setPreferredSize(Size(BTN_WIDTH,BTN_HEIGHT));
    quitGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::MenuTouchDown), Control::EventType::TOUCH_DOWN);
    quitGameBtn->setTag(BTN_QUIT_TAG);
    this->addChild(quitGameBtn);
}


void MenuScene::MenuTouchDown(Object *pSender, cocos2d::extension::Control::EventType event){
    ControlButton *button = (ControlButton*) pSender;
    int tag = button->getTag();
    switch(tag){
        case BTN_SINGLE_GAME_TAG:
            break;
        case BTN_MULTI_GAME_TAG:
            break;
        case BTN_MUSIC_TAG:
        {
//            bool music_on = UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY,true);
            if(music_on){
                music_on=false;
                button->setTitleForState("music off", Control::State::NORMAL);
            }
            else{
                music_on=true;
                button->setTitleForState("music on", Control::State::NORMAL);
            }
        }
        case BTN_QUIT_TAG:
            break;
        default:
            break;
    }
}










