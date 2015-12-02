#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    music.load("music/music.mp3");
    music.setLoop(true);
    music.play();
    
    optionsText.loadFont(OF_TTF_SANS,15); //Loads font to text variable
    scoreText.loadFont(OF_TTF_SANS,30); //Loads font to text variable
    font = new ofTrueTypeFont();
    font->loadFont(OF_TTF_SANS, 20);
    
    buttons = {
        {
            Button(ofVec2f(ofGetWidth()/2-100,270),ofVec2f(200,60),"Play"),
            Button(ofVec2f(ofGetWidth()/2-100,350),ofVec2f(200,60),"Controls"),
            Button(ofVec2f(ofGetWidth()/2-100,430),ofVec2f(200,60),"Exit")
        },
        {
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-30),ofVec2f(200,60),"Main Menu"),
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-130),ofVec2f(200,60),"PAUSED",ofColor(235, 71, 71))
        },
        {
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-30),ofVec2f(200,60),"Main Menu"),
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-100),ofVec2f(200,60),"Reset")
        },
        {
            Button(ofVec2f(20,ofGetHeight()-150),ofVec2f(200,60),"Main Menu")
        }
    };
    

    
    //Creates level from Level object
    reset();
    state = 0;
    posOffset.set(52,44);
}

//--------------------------------------------------------------
void ofApp::update(){
    switch (state) {
        case 1:
            if(!pause){
                if(ofGetFrameNum()%150==0){
                    int randomNo = floor(rand()%7);
                    ofVec2f randomPos;
                    switch (randomNo) {
                        case 1:
                            for(int i=0; i<3; i++)
                                randomPos = ofVec2f(rand()%20,0);
                                enemies.push_back(new Drone(enemySpawn+randomPos));
                            break;

                        case 2:
                            enemies.push_back(new Drone(enemySpawn));
                            enemies.push_back(new Tank(enemySpawn));
                            break;
                        case 3:
                            enemies.push_back(new Tank(enemySpawn));
                            break;
                        case 4:
                            for(int i=0; i<2; i++)
                                randomPos = ofVec2f(rand()%20,0);
                                enemies.push_back(new Tank(enemySpawn+randomPos));
                            break;
                        default:
                            enemies.push_back(new Drone(enemySpawn));
                            break;
                    }
                }
                
                entityControls();
                collisions();
                player.move(); //Same as previous comment but with player
                if(gameOver){
                    state=2;
                }
            }
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    switch(state){
        case 1:
            glPushMatrix();
            glTranslated(posOffset.x, posOffset.y, 0);
            //Displays all platforms, player and enemy
            for(auto _platform: platforms){
                _platform->display();
            }
        
            pickup.display();
        
            for(int i=0; i<player.weapons.size(); i++){
                for(auto &_projectile: player.weapons[i]->ammo){
                    _projectile.display();
                }
            }
            
            for(int i=0; i<enemies.size(); i++){
                enemies[i]->display();
            }
            player.display();
        
            glPopMatrix();
        
            if(pause){
                drawButtons(1);
            }
        
            ofPushStyle();
                ofSetColor(0);
                scoreText.drawString(to_string(score), ofGetWidth()/2, 30);
            ofPopStyle();
            break;
        
        case 2:
            ofPushStyle();
                ofSetColor(0);
                scoreText.drawString("Game Over", ofGetWidth()/2-100, 140);
            optionsText.drawString("Score: "+to_string(score), ofGetWidth()/2-30, 180);
            ofPopStyle();
        drawButtons(2);
            break;
        case 3:
            drawButtons(3);
            drawOptions();
            break;
        default:
            ofPushStyle();
            ofSetColor(0);
            scoreText.drawString("Ultra Crate Box", ofGetWidth()/2-130, 150);
            ofPopStyle();
            drawButtons(0);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (state) {
        case 1:
            if(key == OF_KEY_RIGHT){
                player.right = true;
                player.moving = true;
            }
            if(key == OF_KEY_LEFT){
                player.right = false;
                player.moving = true;
            }
            if(key == OF_KEY_UP || key == 'z'){
                up = true;
            }
            if(int(key)>=48 && int(key)<57){player.currentWeapon = int(key)-48;}
            if(key=='x'){
                player.weapons[player.currentWeapon]->checkHoldFire(player);
            }
            if(key=='r'){
                reset();
            }
            if(key=='p'){
                pause = !pause;
            }
            break;
        case 2:
            if(key=='r'){
                reset();
            }
            break;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (state) {
        case 1:
            if(key == OF_KEY_UP || key == 'z'){
                up = false;
            }
            if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
                player.moving = false;
            }
            if(key=='x'){
                player.weapons[player.currentWeapon]->resetWeapon();
            }
            break;
        case 2:
            
            break;
        default:
            break;
    }
}

void ofApp::drawButtons(int _buttonPos){
    ofPushMatrix();
    for(Button &_button : buttons[_buttonPos]){
        _button.display(font);
    }
    ofPopMatrix();
}

void ofApp::drawOptions(){
    ofPushMatrix();
        vector<ofImage> images;
        images.push_back(getImage("sprites/entities/player/sprite1.png"));
        images.push_back(getImage("sprites/entities/drone/sprite1.png"));
        images.push_back(getImage("sprites/entities/drone/enrage/sprite1.png"));
        images.push_back(getImage("sprites/entities/tank/sprite1.png"));
        images.push_back(getImage("sprites/entities/tank/enrage/sprite1.png"));
        images.push_back(getImage("sprites/tiles/platform/platform3.png"));
        images.push_back(getImage("sprites/misc/pickup.png"));
        images.push_back(getImage("sprites/tiles/fire/1fire.png"));
    
    for(int i=0; i<images.size(); i++){
        images[i].draw(60, i*45+175);
    }
    ofPushStyle();
        ofSetColor(0);
    scoreText.drawString("In-Game Objects", 50, 140);
        optionsText.drawString("Player", 100, 195);
        optionsText.drawString("Drone - normal", 100, 240);
        optionsText.drawString("Drone - enraged", 100, 285);
        optionsText.drawString("Tank - normal", 100, 330);
        optionsText.drawString("Tank - enraged", 100, 375);
        optionsText.drawString("Platform", 100, 420);
        optionsText.drawString("Crate", 100, 465);
        optionsText.drawString("Fire", 100, 510);
    
        scoreText.drawString("Rules", 500, 140);
        optionsText.drawString("-Collect crates to gain score", 500, 175);
        optionsText.drawString("-Hitting enemies and fire will cause a Game Over", 500, 200);
        optionsText.drawString("-Collecting crates changes your weapon", 500, 225);
        optionsText.drawString("-Enemies will become enraged when they touch the fire.", 500, 250);
    
        scoreText.drawString("Controls", 500, 400);
        optionsText.drawString("Up Arrow or 'z' = Jump", 500, 435);
        optionsText.drawString("Left Arrow = Move Left", 500, 460);
        optionsText.drawString("Right Arrow = Move Right", 500, 485);
        optionsText.drawString("'x' = Fire Weapon", 500, 510);
        optionsText.drawString("'p' = Pause", 500, 535);
        optionsText.drawString("'r' = Reset", 500, 560);
        ofPopStyle();
    ofPopMatrix();
}

ofImage ofApp::getImage(string filepath){
    ofImage img;
    img.load(filepath);
    return img;
}

/*--------Entity Controls--------*/

void ofApp::entityControls(){
    //Player controls
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
    
    pickup.move();
    
    for(int i=0; i<enemies.size(); i++){
        enemies[i]->move();
        enemies[i]->checkAlive();
        if(enemies[i]->checkEntity(player)){
            gameOver=true;
        }
        for(int j=0; j<player.weapons.size(); j++){
            for(int k=0; k<player.weapons[j]->ammo.size(); k++){
                if(enemies[i]->checkEntity(player.weapons[j]->ammo[k])){
                    damageEnemies(player.weapons[j]->ammo[k]);
                    player.weapons[j]->ammo.erase(player.weapons[j]->ammo.begin()+k);
                }
            }
        }
        if(enemies[i]->dead){
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
        }
    }
    player.weapons[player.currentWeapon]->fireWeapon(player);
}

/*--------Entity Collisions--------*/

void ofApp::collisions(){
    //Tile collision routine
    for(auto &_enemy: enemies){
        _enemy->onPlatform = false;//Sets entities 'onPlatform' bool to false
    }
    player.onPlatform=false;
    pickup.onPlatform=false;
    
    //For each platform checks if the player is colliding with an entity and changes the onPlatform to true accordingly
    for(auto _platform: platforms){
        if(Platform* derived = dynamic_cast<Platform*>(_platform)){
            checkCollisions(_platform,&player);
            for(auto _enemy: enemies){
                if(_platform->detectLeft(_enemy)){
                    _enemy->vel.x=-0.1;
                    _enemy->moveX(-1);
                    _enemy->pos.x-=20;
                }
                if(_platform->detectRight(_enemy)){
                    _enemy->vel.x=0.1;
                    _enemy->moveX(1);
                    _enemy->pos.x+=20;
                }
                checkCollisions(_platform,_enemy);
            }
            checkCollisions(_platform, &pickup);
        }
        if(Fire* derived = dynamic_cast<Fire*>(_platform)){
            for(auto _enemy: enemies){
                if(_platform->detectBottom(_enemy)){
                    _enemy->enrage();
                    _enemy->pos.set(enemySpawn);
                }
            }
            if(_platform->detectBottom(&player)){
                gameOver=true;
            }
        }
    }
    
    if(player.checkEntity(pickup)){
        pickup.pos = ofVec2f(rand()%ofGetWidth(),rand()%ofGetHeight());
        
        int newWeapon = floor(rand()%player.weapons.size());
        while(player.currentWeapon == newWeapon){
            newWeapon = floor(rand()%player.weapons.size());
        }
        player.currentWeapon = newWeapon;
        player.weapons[player.currentWeapon]->resetWeapon();
        player.weapons[player.currentWeapon]->counter=0;
        score++;
    }
    
    if(pickup.checkWall()){
        pickup.pos = ofVec2f(rand()%ofGetWidth(),rand()%ofGetHeight());
    }
    
    for(int i=0; i<player.weapons.size(); i++){
        player.weapons[i]->checkBullets();
    }
}

/*--------Checks for Tile-Entity collisions--------*/

void ofApp::checkCollisions(Tile *_platform, Entity *_entity){
    
    //Checks around the entity and only executes collision checks if entity is within 30 pixels in any direction of a platform
    if(abs(_platform->pos.x-_entity->pos.x)<30 && abs(_platform->pos.y-_entity->pos.y)<30){
    
        //Detect if left of tile is colliding with the entity
        if(_platform->detectLeft(_entity)){
            _entity->pos.x=_platform->pos.x-_platform->size.x/2-_entity->size.x/2-3; //Changes position of entity to side of tile thus not making the entity clip through the tile
        }
        
        //Checks if entity is jumping into a tile from below
        else if(_platform->detectBottom(_entity)){
            _entity->pos.y=_platform->pos.y+_platform->size.y/2+_entity->size.y/2+1; //Changes position of entity so it is below the tile and cannot clip through
            _entity->vel.y=0;
            _entity->acc.y=0;
        }
        
        //Same but with the right of the tile
        if(_platform->detectRight(_entity)){
            _entity->pos.x=_platform->pos.x+_platform->size.x/2+_entity->size.x/2+3; //Changes position of entity to side of tile thus not making the entity clip through the tile
        }
        
        //Detects the top of the tile
        else if(_platform->detectTop(_entity)){
            _entity->action = false; //Entities can now jump
            _entity->vel.y=0; //Velocity set to 0, prevent clipping
            _entity->acc.y=0; //Acceleration set to 0, prevent clipping
            _entity->pos.y=_platform->pos.y-_platform->size.y/2-_entity->size.y/2;
            //Changes position of entity to above the top of the tile so the entity is in a 'buffer zone' meaning that the entity is not falling due to gravity but can still run and jump
        }

        
        //Checks if entity is in buffer zone and stops entity from falling through tile
        if(_platform->detectAboveTop(_entity)){
            if(_entity->vel.y>0){ //If entity is falling downward
                _entity->vel.y=0; //velocity stops to prevent clipping
            }
            _entity->onPlatform=true;
            _entity->action = false; //Entity can jump
        }
    }
}

/*--------Builds level from level array--------*/

void ofApp::createLevel(){
    
    /*
     Number meanings
     0=air
     1=platform
     2=player spawn
     3=enemy Spawner
     4=fire
     */

    
    for(int j=0; j<level.layout[0].size(); j++)
    {
        for(int i=0; i<level.layout.size(); i++)
        {
            switch(level.layout[i][j])
            {
                case 1:
                    platforms.push_back(new Platform(ofVec2f(i*20,j*20)));
                    break;
                case 2:
                    player = Player(ofVec2f(i*20,j*20));
                    break;
                case 3:
                    enemySpawn.set(i*20, j*20);
                    break;
                case 4:
                    platforms.push_back(new Fire(ofVec2f(i*20,j*20)));
                    break;
                default:
                    break;
            }
        }
    }
}

/*--------Damages enemies within radius of projectile--------*/

void ofApp::damageEnemies(Projectile &_projectile){
    for(auto &_enemy: enemies){
        if(abs(_projectile.pos.x-_enemy->pos.x)<_projectile.explosionRadius+_projectile.size.x && abs(_projectile.pos.y-_enemy->pos.y)<_projectile.explosionRadius+_projectile.size.y){
            _enemy->health-=_projectile.damage;
        }
    }
}

void ofApp::reset(){
    pause = false;
    state = 1;
    score = 0;
    for(int i=platforms.size()-1; i>=0; i--){
        delete platforms[i];
        platforms.erase(platforms.begin()+i);
    }
    createLevel();
    player.currentWeapon = 0;
    gameOver = false;
    pickup = Pickup();
    for(int i=enemies.size()-1; i>=0; i--){
        delete enemies[i];
        enemies.erase(enemies.begin()+i);
    }
    up = false;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    switch (state) {
            
        case 1:
            if(buttons[1][0].clicked(x, y) && pause){
                state=0;
            }
            break;
        case 2:
            if(buttons[2][0].clicked(x,y)){
                state=0;
            }
            else if(buttons[2][1].clicked(x, y)){
                reset();
            }
            break;
            
        case 3:
            if(buttons[3][0].clicked(x, y)){
                state=0;
            }
            break;
        default:
            if(buttons[0][0].clicked(x, y)){
                reset();
            }
            else if (buttons[0][1].clicked(x, y)){
                state=3;
            }
            else if(buttons[0][2].clicked(x, y)){
                ofExit();
            }
            break;
    }
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseEntered(int x, int y){
    
}
void ofApp::mouseExited(int x, int y){
    
}
void ofApp::windowResized(int w, int h){
    
}
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
void ofApp::gotMessage(ofMessage msg){
    
}