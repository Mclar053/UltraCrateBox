//
//  Rocket.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "Rocket.h"

Rocket::Rocket():ExplosiveType("Rocket", 100, 120, true){
    gameSprite = Sprite("sprites/weapons/rocket");
    getSize();
}

void Rocket::fire(Entity &_entity){
    ammo.push_back(Explosive(_entity.pos,_entity.direction,damage));
}