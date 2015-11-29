//
//  Tank.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 29/11/2015.
//
//

#include "Tank.h"

Tank::Tank(ofVec2f _pos):Enemy(_pos){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/tank/");
    getSize();
    MAX_VEL.set(2, 10);
    health=10;
    type = "tank";
}