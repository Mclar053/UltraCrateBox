//
//  BulletType.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "BulletType.h"

BulletType::BulletType(string _name, int _damage, int _reload, bool _holdFire):Weapon(_name, _damage, _reload, _holdFire){
    
}

void BulletType::fire(Entity &_entity){
    ammo.push_back(Bullet(_entity.pos,_entity.direction,damage));
}