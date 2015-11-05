//
//  Sprite.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Sprite.h"

Sprite::Sprite(){
    
}

//Constructor for stationary sprites (Tiles, Weapons)
Sprite::Sprite(string _folderPath):currentFrame(0),actionFrame(0){
    createSprite(_folderPath);
}

//Constructor for animated sprites (Entity)
Sprite::Sprite(int _action,int _startRun, int _endRun,int _stationary,string _folderPath):currentFrame(_startRun),actionFrame(_action),startRunningFrame(_startRun),endRunningFrame(_endRun),stationaryFrame(_stationary){
    createSprite(_folderPath);
}

//Create sprite from folder location provided
void Sprite::createSprite(string _folderPath){
    //Load all images from folder path requested
    ofDirectory dir(_folderPath);
    dir.allowExt("png");
    dir.listDir();
    
    //Temporary image variable
    ofImage img;
    
    //Load all images into the sprite array
    for(int i = 0; i < dir.numFiles(); i++){
        img.loadImage(dir.getPath(i));
        sprite.push_back(img);
    }
}

//Display current frame of animation
void Sprite::display(){
    sprite[currentFrame].draw(-sprite[currentFrame].getWidth()/2, -sprite[currentFrame].getHeight()/2, sprite[currentFrame].getWidth(), sprite[currentFrame].getHeight());
}

//Moves to next frame every 6 frames and loops the animation
void Sprite::moveNextFrame(){
    if(ofGetFrameNum()%5==0){
        currentFrame++;
        if(currentFrame>endRunningFrame){
            currentFrame=startRunningFrame;
        }
    }
}