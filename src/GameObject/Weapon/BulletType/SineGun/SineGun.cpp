//
//  SineGun.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/12/2015.
//
//

#include "SineGun.h"

SineGun::SineGun():BulletType("SineGun", 1, 1, true){
    gameSprite = Sprite("sprites/weapons/pistol");
    getSize();
}