//
//  Button.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 30/11/2015.
//
//

#include "Button.h"

Button::Button(ofVec2f _pos, ofVec2f _size):pos(_pos),size(_size){
    setFont(20);
    setText("");
}

Button::Button(ofVec2f _pos, ofVec2f _size, string _text, int _fontSize):pos(_pos),size(_size){
    setFont(_fontSize);
    setText(_text);
}

void Button::display(){
    ofPushMatrix();
        ofDrawRectangle(pos.x, pos.y, size.x, size.y);
        font.drawString(text, pos.x, pos.y);
    ofPopMatrix();
}

void Button::setText(string _text){
    text = _text;
}

void Button::setFont(int _size){
    font.load(OF_TTF_SANS, _size);
}

bool Button::clicked(float _mouseX, float _mouseY){
    if(_mouseX-pos.x<size.x &&
       _mouseX-pos.x>0 &&
       _mouseY-pos.y<size.y &&
       _mouseY-pos.y>0){
        return true;
    }
    return false;
}