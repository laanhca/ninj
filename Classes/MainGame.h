//
// Created by Admin on 3/28/2021.
//

#ifndef PROJ_ANDROID_MAINGAME_H
#define PROJ_ANDROID_MAINGAME_H
#include "cocos2d.h"
#include "Ninja.h"

class MainGame: public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    Ninja *_ninja;
    CREATE_FUNC(MainGame);
private:
   // void onClickMovie(Ref *object);

    //void onClickAttack(Ref *object);
};


#endif //PROJ_ANDROID_MAINGAME_H
