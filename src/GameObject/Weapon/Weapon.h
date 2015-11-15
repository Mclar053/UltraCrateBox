//
//  Weapon.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#ifndef __UltraCrateBox__Weapon__
#define __UltraCrateBox__Weapon__

#include "../GameObject.h"
#include <stdio.h>

//This is a placeholder. Will work on later

//Weapons will emit projectiles when used.
//Base class for all types of weapons. E.g. Pistol, Sword, Laser Rifle etc...

//Weapons inherits from GameObject
class Weapon: public GameObject{
public:
    /*Constructors*/
    Weapon();
};

#endif /* defined(__UltraCrateBox__Weapon__) */
