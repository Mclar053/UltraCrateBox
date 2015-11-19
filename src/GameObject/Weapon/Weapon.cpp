//
//  Weapon.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Weapon.h"

Weapon::Weapon(){
    pos = ofVec2f(5,0);
}

void Weapon::checkBullets(){
    for (int i=0; i<ammo.size(); i++){
        ammo[i].move();
        if(ammo[i].checkWall()){
            ammo.erase(ammo.begin()+i, ammo.begin()+i+1);
        }
    }
}

void Weapon::fire(Entity &_entity){
    ammo.push_back(Bullet(_entity.pos,_entity.direction));
}