//
//  MachineGun.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 27/11/2015.
//
//

#include "MachineGun.h"

MachineGun::MachineGun():BulletType("Machine Gun", 3, 5, true){
    gameSprite = Sprite("sprites/weapons/pistol");
    getSize();
}