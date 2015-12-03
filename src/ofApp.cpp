#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    music.load("music/music.mp3"); //Loads music from file
    music.setLoop(true); //Loops the music
    music.play(); //Plays the music
    
    optionsText.loadFont(OF_TTF_SANS,15); //Loads font for options menu text
    scoreText.loadFont(OF_TTF_SANS,30); //Loads font for the score text
    font = new ofTrueTypeFont(); //Creates a new pointer font for button text in the heap
    font->loadFont(OF_TTF_SANS, 20); //Loads the font for the font pointer
    
    //All buttons in the game
    buttons = {
        {
            //Buttons for main menu
            Button(ofVec2f(ofGetWidth()/2-100,270),ofVec2f(200,60),"Play"),
            Button(ofVec2f(ofGetWidth()/2-100,350),ofVec2f(200,60),"Controls"),
            Button(ofVec2f(ofGetWidth()/2-100,430),ofVec2f(200,60),"Exit")
        },
        {
            //Buttons for in game screen, displayed when game is paused
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2+30),ofVec2f(200,60),"Main Menu"),
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-50),ofVec2f(200,60),"Reset"),
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-130),ofVec2f(200,60),"PAUSED",ofColor(235, 71, 71))
        },
        {
            //Buttons for Game over screen
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-30),ofVec2f(200,60),"Main Menu"),
            Button(ofVec2f(ofGetWidth()/2-100,ofGetHeight()/2-100),ofVec2f(200,60),"Reset")
        },
        {
            //Buttons for options menu
            Button(ofVec2f(20,ofGetHeight()-150),ofVec2f(200,60),"Main Menu")
        },
        {
            //Buttons for level select menu
            Button(ofVec2f(150,ofGetHeight()/2-100),ofVec2f(200,60),"Level 1"),
            Button(ofVec2f(400,ofGetHeight()/2-100),ofVec2f(200,60),"Level 2"),
            Button(ofVec2f(650,ofGetHeight()/2-100),ofVec2f(200,60),"Level 3"),
            Button(ofVec2f(400,ofGetHeight()/2+50),ofVec2f(200,60),"Main Menu")
        }
    };
    

    state = 0; //Sets state to 0 for main menu
    posOffset.set(52,44); //posOffset translates all in game tiles and player position from edge to centre for better viewing
}

//--------------------------------------------------------------
void ofApp::update(){
    //Switches game states
    switch (state) {
        case 1:
            /*
            Main game screen
            */
            if(!pause){
                if(ofGetFrameNum()%150==0){
                    /*
                     -Every 150 frames a set of enemies will spawn
                     -To spawn a random enemy set, a random number is generated between 0 and 7
                     -For enemy sets that spawn multiples of the same type of enemy, a random position ofVec2f will be added which will add up to 20 pixels to the enemies spawning position.
                     Reasoning for this is due to how enemies of the same type will have the same speed and will overlapped each other, meaning that the player will not be able to see those enemies.
                     */
                    
                    
                    int randomNo = floor(rand()%7); //Creates a random number to choose random set of enemies
                    ofVec2f randomPos; //Random position vector so enemies do not spawn on top of each other
                    switch (randomNo) {
                        case 1:
                            /*
                             Creates 3 drones with up to 20 pixels random positioning from each other
                             at enemyspawn
                             */
                            for(int i=0; i<3; i++)
                                randomPos = ofVec2f(rand()%20,0);
                                enemies.push_back(new Drone(enemySpawn+randomPos));
                            break;

                        case 2:
                            /*
                             Creates a drone and a tank at enemyspawn
                             */
                            enemies.push_back(new Drone(enemySpawn));
                            enemies.push_back(new Tank(enemySpawn));
                            break;
                            
                        case 3:
                            /*
                             Creates a tank at enemyspawn
                             */
                            enemies.push_back(new Tank(enemySpawn));
                            break;
                            
                        case 4:
                            /*
                             Creates 2 tanks at enemyspawn with up to 20 pixels random positioning from each other
                             */
                            for(int i=0; i<2; i++)
                                randomPos = ofVec2f(rand()%20,0);
                                enemies.push_back(new Tank(enemySpawn+randomPos));
                            break;
                            
                        default:
                            /*
                             3/7 chance to spawn just a single drone
                             */
                            enemies.push_back(new Drone(enemySpawn));
                            break;
                    }
                }
                
                entityControls(); //All entity control based functions in here E.g. Entity movement
                collisions(); //All collision based functions in here E.g. Tile-Entity collision
                player.move(); //Allows physics to act of player

                if(gameOver){ //Changes screen to game over state
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
    ofBackground(225); //Draws white background
    
    switch(state){
        case 1:
            /*
             Main Game Screen
             */
            glPushMatrix();
            glTranslated(posOffset.x, posOffset.y, 0);
            
            //Displays all platforms, projectiles, player and enemy
            
            for(auto _platform: platforms){
                _platform->display();
            }
        
            pickup.display();
        
            //Displays all projectiles from all the players weapons
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
        
            if(pause){ //If the user has paused the screen, draw all the buttons for this state
                drawButtons(1);
            }
        
            //Displays the score of the player to the top of the screen
            ofPushStyle();
                ofSetColor(0);
                scoreText.drawString(to_string(score), ofGetWidth()/2, 30);
            ofPopStyle();
            break;
        
        case 2:
            /*
             Game Over Screen
             
             -Displays Game over with the players score
             -Draws all buttons for this state
             */
            ofPushStyle();
                ofSetColor(0);
                scoreText.drawString("Game Over", ofGetWidth()/2-100, 140);
            optionsText.drawString("Score: "+to_string(score), ofGetWidth()/2-30, 180);
            ofPopStyle();
        drawButtons(2);
            break;
            
        case 3:
            /*
             Options Menu
             
             -Draws all buttons for this state
             -Draws all controls and options to screen
             */
            drawButtons(3);
            drawOptions();
            break;
            
        case 4:
            /*
             Level Select Screen
             
             -Displays Level Select text to screen
             -Draws all buttons for this state
             */
            ofPushStyle();
                ofSetColor(0);
                scoreText.drawString("Level Select", ofGetWidth()/2-100, 100);
            ofPopStyle();
            drawButtons(4);
            break;
            
        default:
            /*
             Main Menu Screen
             
             -Displays Main Menu text to screen
             -Draws all buttons for this state
             */
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
            /*
             Main Game Screen
             */
            
            if(key == OF_KEY_RIGHT){
                //Moves player to the right and allows player to move
                player.right = true;
                player.moving = true;
            }
            if(key == OF_KEY_LEFT){
                //Moves player to the left and allows player to move
                player.right = false;
                player.moving = true;
            }
            if(key == OF_KEY_UP || key == 'z'){
                //Allows player to jump
                up = true;
            }
            
            if(key=='x'){
                //Checks if player can fire
                player.weapons[player.currentWeapon]->checkHoldFire(player);
            }
            if(key=='r'){
                //Allows player to reset the level
                reset();
            }
            if(key=='p'){
                //Allows player to pause/unpause the game
                pause = !pause;
            }
            break;
            
        case 2:
            /*
             Game Over Screen
             */
            if(key=='r'){
                //Allows player to reset the level
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
            /*
             Main Game Screen
             */
            if(key == OF_KEY_UP || key == 'z'){
                //Player is not jumping anymore
                up = false;
            }
            if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
                //Player is not moving anymore. Does cause keys sticking meaning player stops when changing direction sometimes
                player.moving = false;
            }
            if(key=='x'){
                //Resets the weapon so it can fire again
                player.weapons[player.currentWeapon]->resetWeapon();
            }
            break;
            
        default:
            break;
    }
}


/*
 Function to draw buttons onto screen from buttons 2D vector.
 -Takes in 1 parameter that draws all buttons from the specified part of the 2D vector
 */
void ofApp::drawButtons(int _buttonPos){
    ofPushMatrix();
    for(Button &_button : buttons[_buttonPos]){
        _button.display(font); //Passes in font pointer so button can contain text
    }
    ofPopMatrix();
}


/*
 Function that draws the options menu
 */
void ofApp::drawOptions(){
    ofPushMatrix();
    
    /*
     Create image vector and add all images needed for the options menu
     */
        vector<ofImage> images;
        images.push_back(getImage("sprites/entities/player/sprite1.png")); //Player sprite
        images.push_back(getImage("sprites/entities/drone/sprite1.png")); //Normal drone sprite
        images.push_back(getImage("sprites/entities/drone/enrage/sprite1.png")); //Enraged drone sprite
        images.push_back(getImage("sprites/entities/tank/sprite1.png")); //Normal tank sprite
        images.push_back(getImage("sprites/entities/tank/enrage/sprite1.png")); //Enraged tank sprite
        images.push_back(getImage("sprites/tiles/platform/platform3.png")); //Platform sprite
        images.push_back(getImage("sprites/misc/pickup.png")); //Pickup crate sprite
        images.push_back(getImage("sprites/tiles/fire/1fire.png")); //Fire sprite
    
    //Draw all images to the screen
    for(int i=0; i<images.size(); i++){
        images[i].draw(60, i*45+175);
    }
    
    /*
     Draw all options text to screen
     */
    ofPushStyle();
        ofSetColor(0);
    /*
     Describe all in game sprites
     */
    scoreText.drawString("In-Game Objects", 50, 140);
        optionsText.drawString("Player", 100, 195);
        optionsText.drawString("Drone - normal", 100, 240);
        optionsText.drawString("Drone - enraged", 100, 285);
        optionsText.drawString("Tank - normal", 100, 330);
        optionsText.drawString("Tank - enraged", 100, 375);
        optionsText.drawString("Platform", 100, 420);
        optionsText.drawString("Crate", 100, 465);
        optionsText.drawString("Fire", 100, 510);

    /*
     Describe rules of the game
     */
        scoreText.drawString("Rules", 500, 140);
        optionsText.drawString("-Collect crates to gain score", 500, 175);
        optionsText.drawString("-Hitting enemies and fire will cause a Game Over", 500, 200);
        optionsText.drawString("-Collecting crates changes your weapon", 500, 225);
        optionsText.drawString("-Enemies will become enraged when they touch the fire.", 500, 250);
    
    /*
     Describe controls to play the game
     */
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

/*
 Function created to easily load images
 -Only used for options menu when describing all game sprites
 */
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
            player.moveX(1); //Player moves to the right
        }
        else{
            player.moveX(-1); //Player moves to the left
        }
    }
    else{
        player.friction(); //If player is not moving apply friction to stop player moving endlessly
    }
    
    if(up){
        player.jump(); //Allow player to jump if up key is pressed
    }
    
    pickup.move(); //Apply physics to pickup crate
    
    /*
     Although part of this for loop contains collision detection between projectile and enemies, this is part of the entity controls function because recreating this nested for loop would be inefficient compared to here.
     */
    for(int i=0; i<enemies.size(); i++){
        enemies[i]->move(); //Applies physics to each enemy
        enemies[i]->checkAlive(); //Checks if the enemy is alive or dead

        if(enemies[i]->checkEntity(player)){ //If player has touched the enemy then the game is over
            gameOver=true;
        }
        
        /*
        For each projectile in every weapon the player has:
         -If the enemy has been hit with a projectile then enemies within the projectiles explosion radius will be damaged
         -The projectile will then be removed from that particular weapons ammo vector
         */
        for(int j=0; j<player.weapons.size(); j++){
            for(int k=0; k<player.weapons[j]->ammo.size(); k++){
                if(enemies[i]->checkEntity(player.weapons[j]->ammo[k])){
                    damageEnemies(player.weapons[j]->ammo[k]);
                    player.weapons[j]->ammo.erase(player.weapons[j]->ammo.begin()+k);
                }
            }
        }
        
        //Checks if the enemy is dead
        if(enemies[i]->dead){
            delete enemies[i]; //Removes the memory from the heap
            enemies.erase(enemies.begin()+i); //Deletes the pointer
        }
    }
    
    player.weapons[player.currentWeapon]->fireWeapon(player); //Checks if the player can fire their current weapon
}

/*--------Entity Collisions--------*/

void ofApp::collisions(){
    //Tile collision routine
    
    /*
     Sets entities 'onPlatform' bool to false
     */
    for(auto &_enemy: enemies){
        _enemy->onPlatform = false;
    }
    player.onPlatform=false;
    pickup.onPlatform=false;
    
    //For each platform checks if the player is colliding with an entity and changes the onPlatform to true accordingly
    for(auto _platform: platforms){
        
        if(Platform* derived = dynamic_cast<Platform*>(_platform)){ //Check if tile is of Platform type
            checkCollisions(_platform,&player); //Check collisions between player and platform
            
            for(auto _enemy: enemies){ //For each enemy
                if(_platform->detectLeft(_enemy)){ //Check if enemy has hit the left of a platform
                    /*
                     This is to move enemy is opposite direction and prevent clipping
                     */
                    _enemy->vel.x=-0.1;
                    _enemy->moveX(-1);
                    _enemy->pos.x-=20;
                }
                if(_platform->detectRight(_enemy)){ //Check if enemy has hit the right of a platform
                    /*
                     This is to move enemy is opposite direction and prevent clipping
                     */
                    _enemy->vel.x=0.1;
                    _enemy->moveX(1);
                    _enemy->pos.x+=20;
                }
                checkCollisions(_platform,_enemy); //Checks all collisions between platform and enemy
            }
            checkCollisions(_platform, &pickup); //Checks all collisions between platform and enemy
        }
        
        
        if(Fire* derived = dynamic_cast<Fire*>(_platform)){ //Check if tile is of Fire type
            
            for(auto _enemy: enemies){ //Loops through all enemies
                if(_platform->detectBottom(_enemy)){ //If the enemy collides with the bottom of a fire tile
                    _enemy->enrage(); //Enemy will become enraged
                    _enemy->pos.set(enemySpawn); //Enemy will spawn back at the enemy spawn
                }
            }
            if(_platform->detectBottom(&player)){ //If the player collides with the bottom of a fire tile
                gameOver=true; //The game will end
            }
        }
    }
    
    /*
     Pickup detection
     */
    if(player.checkEntity(pickup)){ //If player collides with a pickup
        pickup.pos = ofVec2f(rand()%ofGetWidth(),rand()%ofGetHeight()); //The pickup will teleport to a new location
        
        /*
         -A random weapon is selected that is not the current weapon of the player
         -The chosen weapon is then reset so the player can use it instantly
         -Score is increased by 1
         */
        
        int newWeapon = floor(rand()%player.weapons.size());
        while(player.currentWeapon == newWeapon){
            newWeapon = floor(rand()%player.weapons.size());
        }
        player.currentWeapon = newWeapon;
        player.weapons[player.currentWeapon]->resetWeapon();
        player.weapons[player.currentWeapon]->counter=0;
        score++;
    }
    
    //If player fall through or climbs above level
    if(player.checkWallY()){
        gameOver=true; //The game is over
    }
    
    //If a pickup is outside of the map
    if(pickup.checkWallX() || pickup.checkWallY()){
        pickup.pos = ofVec2f(rand()%ofGetWidth(),rand()%ofGetHeight()); //The pickup teleports to a new location
    }
    
    //For each weapon the player has
    for(int i=0; i<player.weapons.size(); i++){
        player.weapons[i]->checkBullets(); //Check if the bullets have gone offscreen so they can be deleted
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

    /*
     -Creates the level from the 2D vector the level object has
     */
    for(int j=0; j<level.layout[0].size(); j++)
    {
        for(int i=0; i<level.layout.size(); i++)
        {
            switch(level.layout[i][j])
            {
                case 1:
                    platforms.push_back(new Platform(ofVec2f(i*20,j*20))); //Create Platform tile
                    break;
                case 2:
                    player = Player(ofVec2f(i*20,j*20)); //Set player spawn
                    break;
                case 3:
                    enemySpawn.set(i*20, j*20); //Set enemy spawn
                    break;
                case 4:
                    platforms.push_back(new Fire(ofVec2f(i*20,j*20))); //Create fire tile
                    break;
                default:
                    break;
            }
        }
    }
}

/*--------Damages enemies within radius of projectile--------*/

void ofApp::damageEnemies(Projectile &_projectile){
    //For every enemy
    for(auto &_enemy: enemies){
        //If the enemy is within the size of the projectile + the explosion radius then that enemy will recieve damage from the projectile
        if(abs(_projectile.pos.x-_enemy->pos.x)<_projectile.explosionRadius+_projectile.size.x && abs(_projectile.pos.y-_enemy->pos.y)<_projectile.explosionRadius+_projectile.size.y){
            _enemy->health-=_projectile.damage;
        }
    }
}


/*
 Function to reset the game when either:
 -Level is selected
 -Game is reset
 */
void ofApp::reset(){
    pause = false; //Unpause the game
    state = 1; //Set to main game screen
    score = 0; //Score is set 0
    
    //for every platform
    for(int i=platforms.size()-1; i>=0; i--){
        delete platforms[i]; //Delete the current platforms from the heap
        platforms.erase(platforms.begin()+i); //Remove the pointers that were pointer to the memory on the heap
    }

    createLevel();//Create the new level
    player.currentWeapon = 0; //Set the players current weapon to the pistol
    gameOver = false; //Set the game to not be over
    pickup = Pickup(); //Create a new pickup object
    
    //Repeat the process to delete the platforms with the enemies
    //Removed each current enemy from the heap then remove the pointers pointing the the memory on the heap
    for(int i=enemies.size()-1; i>=0; i--){
        delete enemies[i];
        enemies.erase(enemies.begin()+i);
    }
    up = false; //Player does start jumping
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
            /*
             Main Game Screen
             */
            if(buttons[1][0].clicked(x, y) && pause){ //Main menu button
                state=0;
            }
            else if (buttons[1][1].clicked(x, y) && pause){ //Reset button
                reset();
            }
            break;
            
        case 2:
            /*
             Game over screen
             */
            if(buttons[2][0].clicked(x,y)){ //Main menu button
                state=0;
            }
            else if(buttons[2][1].clicked(x, y)){ //Reset Button
                reset();
            }
            break;
            
        case 3:
            /*
             Options menu
             */
            if(buttons[3][0].clicked(x, y)){ //Main Menu button
                state=0;
            }
            break;
            
        case 4:
            /*
             Level select
             */
            if(buttons[4][0].clicked(x, y)){ //Load level 1
                level.loadLevel("level1.txt");
                reset();
            }
            else if(buttons[4][1].clicked(x, y)){ //Load level 2
                level.loadLevel("level2.txt");
                reset();
            }
            else if(buttons[4][2].clicked(x, y)){ //Load level 3
                level.loadLevel("level3.txt");
                reset();
            }
            else if(buttons[4][3].clicked(x, y)){ //Main menu button
                state=0;
            }
            break;
            
        default:
            /*
             Main menu
             */
            if(buttons[0][0].clicked(x, y)){ //Play button (Goes to level select)
                state=4;
            }
            else if (buttons[0][1].clicked(x, y)){ //Options menu button (Named "Controls")
                state=3;
            }
            else if(buttons[0][2].clicked(x, y)){ //Exit button to leave game
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