//
//  Sprite.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Sprite__
#define __UltraCrateBox__Sprite__

#include <stdio.h>
#include "../ofMain.h"

class Sprite{
    
public:
    //Constructors
    Sprite();
    Sprite(string _folderPath);
    Sprite(int _action,int _startRun, int _endRun,int _stationary,string _folderPath);
    
    //Methods
    void createSprite(string _folderPath);
    void display();
    void moveNextFrame(); //Moves sprite to the next frame
    
    //Properties
    vector<ofImage> sprite;
    int currentFrame; //Current frame that is displayed on the screen
    int startRunningFrame;
    int endRunningFrame;
    int stationaryFrame;
    int actionFrame; //frame where game object has a single action e.g. jumping
};

#endif /* defined(__UltraCrateBox__Sprite__) */
