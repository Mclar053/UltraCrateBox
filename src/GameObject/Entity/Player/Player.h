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

//Including bullet type weapons
#include "../../Weapon/BulletType/Pistol/Pistol.h"
#include "../../Weapon/BulletType/Shotgun/Shotgun.h"
#include "../../Weapon/BulletType/MachineGun/MachineGun.h"
#include "../../Weapon/BulletType/SineGun/SineGun.h"

//Including explosive type weapons
#include "../../Weapon/ExplosiveType/Rocket/Rocket.h"
#include "../../Weapon/ExplosiveType/ChargeRocket/ChargeRocket.h"
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
