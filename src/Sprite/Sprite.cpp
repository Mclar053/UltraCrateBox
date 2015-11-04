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

Sprite::Sprite(string _folderPath):currentFrame(0),actionFrame(0){
    createSprite(_folderPath);
}

Sprite::Sprite(int _action,int _startRun, int _endRun,string _folderPath):currentFrame(_startRun),actionFrame(_action),startRunningFrame(_startRun),endRunningFrame(_endRun){
    createSprite(_folderPath);
}

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
    cout<<"Created";
}

void Sprite::display(){
    sprite[currentFrame].draw(-sprite[currentFrame].getWidth()/2, -sprite[currentFrame].getHeight()/2, sprite[currentFrame].getWidth(), sprite[currentFrame].getHeight());
}

void Sprite::moveNextFrame(){
    if(ofGetFrameNum()%6==0){
        currentFrame++;
        if(currentFrame>endRunningFrame){
            currentFrame=startRunningFrame;
        }
    }
}