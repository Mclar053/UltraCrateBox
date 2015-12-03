//
//  Enemy.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Enemy.h"

Enemy::Enemy():health(10),dead(false){
}

Enemy::Enemy(ofVec2f _pos):Entity(_pos),dead(false),fallen(false){
    moving=true;
    int randomMove = floor(rand()%2);
    if(randomMove==0){
        randomMove=-1;
    }
    moveX(randomMove);
}

void Enemy::checkAlive(){
    if(health<=0){
        dead=true;
    }
}

//Changes direction of the enemy
void Enemy::changeDirection(){
    moveX(-direction);
}

/*
 If enemy has not fallen already then enemy will 'enrage' by changing game sprite and increasing velocity by a 1.5 multiplier
 */
void Enemy::enrage(){
    if(!fallen){
        gameSprite.createSprite("sprites/entities/"+type+"/enrage/");
        MAX_VEL.x*=1.5;
        fallen = true;
    }
}