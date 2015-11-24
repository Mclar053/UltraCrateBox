//
//  Player.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Player__
#define __UltraCrateBox__Player__

#include "../Entity.h"
//#include "../../Weapon/Weapon.h"
#include "../../Weapon/BulletType/Pistol/Pistol.h"
#include <stdio.h>

//Player inherits Entity
class Player: public Entity{
public:
    //Constructors
    Player();
    Player(ofVec2f _pos);
    
    //Methods
    void jump();
    void display();
    
    //Properties
    bool right;
    vector<Weapon*> weapons; //Vector of weapons
    int currentWeapon;
};

#endif /* defined(__UltraCrateBox__Player__) */
