//
// Created by Admin on 4/2/2021.
//

#include "Ninja.h"
Ninja::Ninja(void) {
    _isAnimation = false;
}
Ninja::~Ninja(void) {
    _run->release();
    _attack->release();

}
Ninja *Ninja::create(){
    Ninja *ret = new Ninja();
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool Ninja::init(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("murom.plist");
    auto frames = getAnimation("Idle_%03d.png", 11);
//    auto frames = getAnimation("Die_%03d.png", 9);
//    auto frames = getAnimation("jump_%03d.png", 5);
    _ninja = Sprite::createWithSpriteFrame(frames.front());
//    _ninja->setPosition(visibleSize.width/2,visibleSize.height/2);
    _ninja->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height / 2));
    this->addChild(_ninja);

    auto animation = Animation::createWithSpriteFrames(frames,1.0f/8);
    _idle = RepeatForever::create(Animate::create(animation));
    _idle->retain();
    _ninja->runAction(_idle);
//    auto animation = Animation::createWithSpriteFrames(frames, 1.0f/8);
//    _ninja->runAction(RepeatForever::create(Animate::create(animation)));
//    addChild(_ninja);
    {
        auto frames = getAnimation("Attack_%03d.png", 6);
        _ninja = Sprite::createWithSpriteFrame(frames.front());
//    _ninja->setPosition(visibleSize.width/2,visibleSize.height/2);
        _ninja->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height / 2));
        auto animation = Animation::createWithSpriteFrames(frames,1.0f/8);
        _attack = RepeatForever::create(Animate::create(animation));
        _attack->retain();

    }
    {
        auto frames = getAnimation("Run_%03d.png", 7);
        _ninja = Sprite::createWithSpriteFrame(frames.front());
//    _ninja->setPosition(visibleSize.width/2,visibleSize.height/2);
        _ninja->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height / 2));
        auto animation = Animation::createWithSpriteFrames(frames,1.0f/8);
        _run = RepeatForever::create(Animate::create(animation));
        _run->retain();
    }
//    log("aaaaa");
    return true;
}

Vector<SpriteFrame *> Ninja::getAnimation(const char *format, int count){
    auto spritecache= SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> aniFrames;
    char str[100];
    for(int i=1;i<=count;i++){
        sprintf(str, format, i);
        aniFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return aniFrames;
}

void Ninja::setAnimation(int type){
    switch (type){
        case 0:
            _ninja->runAction(_idle);
            break;
        case 1:
            _ninja->runAction(_run);
            break;
        case 2:
            _ninja->runAction(_attack);
            break;
    }


}

