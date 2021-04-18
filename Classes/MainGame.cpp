//
// Created by Admin on 3/28/2021.
//
#include <cocos/ui/UIButton.h>
#include "MainGame.h"
#include "Ninja.h"
#include "cocos2d.h"
USING_NS_CC;

Scene *MainGame::createScene() {
    auto scene= Scene::create();
    auto layer= MainGame::create();
    scene->addChild(layer);

    return scene;

}

bool MainGame::init() {
    if (!Scene::init()) { return false; }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    _ninja = Ninja::create();
    _ninja->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(_ninja);


    auto button = cocos2d::ui::Button::create("leftBtn.png","leftBtn_ok.png","leftBtn.png");
    button->setPosition (Vec2 ( 100 , 100 ));
    button->setScale(5);
    button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                //_ninja->stopAllActions();
                log("vao day k");
                _ninja->setAnimation(1);
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                log("vao day k");
//                _ninja->stopAllActions();
                _ninja->setAnimation(0);
                break;
            default:
                break;
        }
    });
    this->addChild(button);

    log("vao day k");




    return true;
}
//void MainGame::onClickMovie(Ref* object){
//    log("movie");
//}
//void MainGame::onClickAttack(Ref* object){
//
//}


