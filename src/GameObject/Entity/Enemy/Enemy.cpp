//
//  Enemy.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Enemy.h"

Enemy::Enemy():health(10),dead(false){
    moving=true;
    moveX(1);
}

Enemy::Enemy(ofVec2f _pos):Entity(_pos),dead(false),fallen(false){
    moving=true;
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

void Enemy::enrage(){
    if(!fallen){
        gameSprite.createSprite("sprites/entities/"+type+"/enrage/");
        MAX_VEL.x*=1.5;
        fallen = true;
    }
}