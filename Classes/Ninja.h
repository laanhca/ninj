//
// Created by Admin on 4/2/2021.
//

#ifndef PROJ_ANDROID_NINJA_H
#define PROJ_ANDROID_NINJA_H
#include "cocos2d.h"
USING_NS_CC;
class Ninja: public Layer {
public:
    Ninja();
    ~Ninja();
    static Ninja *create();
    bool init();
    Sprite *_ninja;
    Action *_attack;
    Action *_die;
    Action *_dizzy;
    Action *_fly;
    Action *_jump;
    Action *_run;
    Action *_sliding;
     Action *_idle;
    Action *_throwing;
    Action *_walk;
    bool _isAnimation;


    void setAnimation(int type);

private:
    cocos2d::Vector<cocos2d::SpriteFrame *> getAnimation(const char *format, int count);

};


#endif //PROJ_ANDROID_NINJA_H
