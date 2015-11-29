//
//  Shotgun.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "Shotgun.h"

Shotgun::Shotgun():BulletType("Shotgun", 2, 60, true){
    gameSprite = Sprite("sprites/weapons/pistol");
    getSize();
}

void Shotgun::fire(Entity &_entity){
    for(int i=0; i<5; i++){
        ammo.push_back(Bullet(ofVec2f(_entity.pos.x+ofRandom(10),_entity.pos.y+ofRandom(10)),_entity.direction,damage));
    }
}