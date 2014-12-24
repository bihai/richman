//
//  MenuScene.h
//  richman
//
//  Created by yuhan zhang on 12/24/14.
//
//

#ifndef __richman__MenuScene__
#define __richman__MenuScene__

#include <cocos2d.h>
#include "extensions/cocos-ext.h" 

USING_NS_CC;

class MenuScene : public LayerColor
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
private:
    cocos2d::Size visiableSize;
    LabelTTF* settingsGameTTF;
    bool music_on;
    void MenuTouchDown(Object* pSender, cocos2d::extension::Control::EventType event);
    void addBGSprite();
    void addMenuSprite();
};

#endif /* defined(__richman__MenuScene__) */
