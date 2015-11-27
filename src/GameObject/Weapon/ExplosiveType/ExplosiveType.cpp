//
//  ExplosiveType.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "ExplosiveType.h"

ExplosiveType::ExplosiveType(string _name, int _damage, int _reload, bool _holdFire):Weapon(_name, _damage, _reload, _holdFire){
    
}

void ExplosiveType::fire(Entity &_entity){
    ammo.push_back(Explosive(_entity.pos,_entity.direction,damage));
}