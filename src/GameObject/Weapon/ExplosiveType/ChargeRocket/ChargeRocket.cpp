//
//  ChargeRocket.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 02/12/2015.
//
//

#include "ChargeRocket.h"

ChargeRocket::ChargeRocket():ExplosiveType("ChargeRocket", 100, 250, true){
    gameSprite = Sprite("sprites/weapons/rocket");
    getSize();
}

void ChargeRocket::fire(Entity &_entity){
    for(int i=0; i<3; i++){
         ammo.push_back(Explosive(_entity.pos,_entity.direction,damage));
        ammo[ammo.size()-1].MAX_VEL.set((i+1)*5,0);
    }
}