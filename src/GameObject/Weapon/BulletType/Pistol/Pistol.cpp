//
//  Pistol.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "Pistol.h"

Pistol::Pistol(string _name, char _type, int _damage, int _reload, bool _holdFire):BulletType(_name, _type, _damage, _reload, _holdFire){
    gameSprite = Sprite("sprites/weapons/pistol");
    getSize();
}