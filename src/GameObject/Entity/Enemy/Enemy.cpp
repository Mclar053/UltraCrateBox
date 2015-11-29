//
//  Enemy.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Enemy.h"

Enemy::Enemy():health(10),dead(false){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/drone/");
    getSize();
    moving=true;
    MAX_VEL.set(2, 10);
    moveX(1);
}

Enemy::Enemy(ofVec2f _pos):Entity(_pos),health(10),dead(false){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/drone/");
    getSize();
    moving=true;
    MAX_VEL.set(2, 10);
    moveX(1);
}

void Enemy::checkAlive(){
    if(health<=0){
        dead=true;
    }
}

void Enemy::changeDirection(){
    moveX(-direction);
}