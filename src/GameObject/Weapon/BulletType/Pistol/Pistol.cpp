//
//  Pistol.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "Pistol.h"

Pistol::Pistol():BulletType("Pistol", 2, -1, false){
    gameSprite = Sprite("sprites/weapons/pistol");
    getSize();
}