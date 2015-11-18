//
//  Enemy.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Enemy.h"

Enemy::Enemy(){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/drone/");
    getSize();
    moving=true;
    MAX_VEL.set(2, 10);
}

Enemy::Enemy(ofVec2f _pos):Entity(_pos){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/drone/");
    getSize();
    moving=true;
    MAX_VEL.set(2, 10);
}