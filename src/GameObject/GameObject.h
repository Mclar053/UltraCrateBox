//
//  GameObject.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__GameObject__
#define __UltraCrateBox__GameObject__

#include "../ofMain.h"
#include "../Sprite/Sprite.h"
#include <stdio.h>

class GameObject{
    
public:
    GameObject();
    GameObject(ofVec2f _pos);
    //Methods
    virtual void display(); //Virtual to allow other child classes to overwrite it
    void getSize(); //Gets size of the gameSprite
    
    //Properties
    Sprite gameSprite;
    ofVec2f pos;
    ofVec2f size;
    
};

#endif /* defined(__UltraCrateBox__GameObject__) */
