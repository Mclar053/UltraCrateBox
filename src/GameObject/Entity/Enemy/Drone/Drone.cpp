//
//  Drone.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 29/11/2015.
//
//

#include "Drone.h"

Drone::Drone(ofVec2f _pos):Enemy(_pos){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/drone/");
    getSize();
    MAX_VEL.set(4, 10);
    health=5;
    type = "drone";
}