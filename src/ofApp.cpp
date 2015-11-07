#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    text.loadFont(OF_TTF_SANS,20);
    
    for(int i=0; i<10;i++){
        platforms.push_back(Platform(ofVec2f(i*30, 100)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(player.moving){
        if(player.right){
            player.moveX(1);
        }
        else{
            player.moveX(-1);
        }
    }
    else{
        player.friction();
    }
    
    if(up){
        player.jump();
    }
    
    ene.moveX(1);
    ene.move();
    player.move();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.display();
    ene.display();
    for(auto &_platform: platforms){
        _platform.display();
    }
    text.drawString("VelX:"+to_string(player.vel.x) +"\nVelY:"+ to_string(player.vel.y) +"\nAccX:"+ to_string(player.acc.x)+"\nPosX:"+ to_string(player.pos.x)+"\nPosY:"+ to_string(player.pos.y),100,100);
    
    text.drawString("VelX:"+to_string(ene.vel.x) +"\nVelY:"+ to_string(ene.vel.y) +"\nAccX:"+ to_string(ene.acc.x)+"\nPosX:"+ to_string(ene.pos.x)+"\nPosY:"+ to_string(ene.pos.y),400,100);
    
    text.drawString("SizeX:"+to_string(player.size.x) +"\nSizeY:"+to_string(player.size.y),700,100);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT){
        player.right = true;
        player.moving = true;
    }
    else if(key == OF_KEY_LEFT){
        player.right = false;
        player.moving = true;
    }
    if(key == OF_KEY_UP || key == 'z'){
        up = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_UP || key == 'z'){
        up = false;
    }
    if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
        player.moving = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
