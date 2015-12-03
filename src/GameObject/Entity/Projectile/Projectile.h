//
//  Projectile.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Projectile__
#define __UltraCrateBox__Projectile__

#include "../Entity.h"
#include <stdio.h>

//Projectile will have child classes of different types of projectile, e.g. Bullets...
//Projectiles will be emitted out of different weapons. E.g Pistol will use bullets

//Projectile inherits from Entity
class Projectile: public Entity{
public:
    Projectile(ofVec2f _pos, int &_dir, int _damage);

    void sineMe(); //Moves in a sine wave
    
    int damage; //Carries damage from weapon
    int explosionRadius; //Damages enemies within explosion radius
    int sinCount; //Counts frames for a smooth sine wave
};

#endif /* defined(__UltraCrateBox__Projectile__) */
