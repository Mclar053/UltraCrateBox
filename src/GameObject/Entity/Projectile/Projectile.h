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

//This is a placeholder. Will work on later

//Projectile will have child classes of different types of projectile, e.g. Bullets...
//Projectiles will be emitted out of different weapons. E.g Pistol will use bullets

//Projectile inherits from Entity
class Projectile: public Entity{
public:
    Projectile(ofVec2f _pos, int &_dir, int _damage);

    void sineMe();
    int checkExplodeRadius(string _type);
    
    int damage;
    int explosionRadius;
};

#endif /* defined(__UltraCrateBox__Projectile__) */
