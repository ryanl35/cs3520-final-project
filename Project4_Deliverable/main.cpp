#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <sstream>
#include <stdio.h> 
#include <cmath>
#include <stdlib.h> 
#include <deque>

class Object {
protected:
    int x;
    int y;
public:
    virtual int getX() const { return x; }
    virtual int getY() const { return y; };
    virtual void setX(int x) { this->x = x; };
    virtual void setY(int y) { this->y = y; };
};

class Monster : public Object {
public:
    Monster(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


class Platform : public Object {
private:

    bool isGone; // field to determine if platform should disappear

public:
    Platform(int x, int y) {
        this->x = x;
        this->y = y;
        this->isGone = false;
    };

    bool getIsGone() const { return this->isGone; }
    void disappear() { this->isGone = true; }
};


class Bullet : public Object {
public:
    Bullet(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Hole : public Object {
public:
    Hole(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


//////////////////////////////////////////////////////////
/////////////////////  TEST SUITE ////////////////////////
//////////////////////////////////////////////////////////

void assertEquals(bool value, const char * test){
    if ( value ){
        std::cout << "Passed: " << test << std::endl;
    }
    else{
        std::cout << "--FAILED--" << test << std::endl;
    }
}

void testGetX(int getX, int expectedX) {
    assertEquals(getX == expectedX, __FUNCTION__);
}

void testGetY(int getY, int expectedY) {
    assertEquals(getY == expectedY, __FUNCTION__);
}

void testGetIsGone(bool getIsGone, bool expectedBool) {
    assertEquals(getIsGone == expectedBool, __FUNCTION__);
}

void testSetX(int setXValue, int getXValue) {
    assertEquals(setXValue == getXValue, __FUNCTION__);
}

void testSetY(int setYValue, int getYValue) {
    assertEquals(setYValue == getYValue, __FUNCTION__);
}

void testDisappear(bool curr, bool newBool) {
    assertEquals(curr == newBool, __FUNCTION__);
}

int main()
{
    //////////////////////////////////////////////////////////
    /////////////////////  TEST SUITE ////////////////////////
    //////////////////////////////////////////////////////////
    Monster * monsterTest = new Monster(5, 5);
    Platform * platformTest = new Platform(10, 5);
    Bullet * bulletTest = new Bullet(50, 50);
    Hole * holeTest = new Hole(20, 50);

    // TESTING: getX() on each type of Object
    testGetX(monsterTest->getX(), 5);
    testGetX(platformTest->getX(), 10);
    testGetX(bulletTest->getX(), 50);
    testGetX(holeTest->getX(), 20);

    // TESTING: getY() on each type of Object
    testGetY(monsterTest->getY(), 5);
    testGetY(platformTest->getY(), 5);
    testGetY(bulletTest->getY(), 50);
    testGetY(holeTest->getY(), 50);

    // TESTING: getY() on each type of Object
    testGetIsGone(platformTest->getIsGone(), false); // test to make sure a Platform is initalized with false value

    // TESTING: setX() to see if the values were changed
    monsterTest->setX(10);
    testSetX(10, monsterTest->getX());
    platformTest->setX(100);
    testSetX(100, platformTest->getX());
    bulletTest->setX(255);
    testSetX(255, bulletTest->getX());
    holeTest->setX(90);
    testSetX(90, holeTest->getX());

    // TESTING: setY() to see if the values were changed
    monsterTest->setY(9232);
    testSetY(9232, monsterTest->getY());
    platformTest->setY(23);
    testSetY(23, platformTest->getY());
    bulletTest->setY(5);
    testSetY(5, bulletTest->getY());
    holeTest->setY(34);
    testSetY(34, holeTest->getY());

    // TESTING: isGone field of Platform
    testDisappear(platformTest->getIsGone(), false); // test to make sure a Platform is initalized with false value
    platformTest->disappear();
    testDisappear(true, platformTest->getIsGone());

    // DELETEING TESTS FOR MEMORY
    delete monsterTest;
    delete platformTest;
    delete bulletTest;
    delete holeTest;



    // define constants
    const int height = 850;
    const int width = 500;
    const double doodleScaleFactor = 0.5;
    const double platformScaleFactor = 0.275;
    const int positionFactor = 6;
    const int normalVolumeLevel = 30;
    const float gravity = 0.2;
    const int offscreen = -1000;

    // CREATING TEXTURES

    // creates the background texture to be used for the Sprite
    sf::Texture backgroundTxt;
    backgroundTxt.loadFromFile("media/images/doodleJumpBackground.png");

    // creates the Doodle Jump character texture to be used for the Sprite
    sf::Texture doodleTxt;
    doodleTxt.loadFromFile("media/images/doodleJumpCharacter.png");

    // creates an empty texture (transparent)
    sf::Texture emptyTxt;
    emptyTxt.loadFromFile("media/images/Empty.png");

    // the following textures to be used for the Sprites for the platforms
    sf::Texture brownTxt;
    brownTxt.loadFromFile("media/images/brown.png");

    sf::Texture greenTxt;
    greenTxt.loadFromFile("media/images/green.png");

    sf::Texture blueTxt;
    blueTxt.loadFromFile("media/images/blue.png");

    sf::Texture greenSpringTxt;
    greenSpringTxt.loadFromFile("media/images/greenWithSpring.png");

    // the following textures to be used for the Sprites for the Monsters
    sf::Texture blueFlyTxt;
    blueFlyTxt.loadFromFile("media/images/BlueFly.png");

    sf::Texture ninjaTxt;
    ninjaTxt.loadFromFile("media/images/Ninja.png");

    sf::Texture wideBlueTxt;
    wideBlueTxt.loadFromFile("media/images/WideBlue.png");

    sf::Texture wideGreenTxt;
    wideGreenTxt.loadFromFile("media/images/WideGreen.png");

    sf::Texture robotTxt;
    robotTxt.loadFromFile("media/images/Robot.png");

    sf::Texture bulletTxt;
    bulletTxt.loadFromFile("media/images/bullet.png");

    // initalize the hole texture 
    sf::Texture holeTxt;
    holeTxt.loadFromFile("media/images/hole.png");

    // initalize the lose textures
    sf::Texture lostTxt;
    lostTxt.loadFromFile("media/images/youLose.png");

    sf::Texture playAgainTxt;
    playAgainTxt.loadFromFile("media/images/playAgain.png");


    // CREATING SPRITES

    // creates the Sprite for the Doodle Jump background
    sf::Sprite backgroundSpr;
    backgroundSpr.setTexture(backgroundTxt);

    // creates the Sprite for the Doodle Jump character
    sf::Sprite doodleSpr;
    doodleSpr.setTexture(doodleTxt);

    // the following three Sprites to be used for the platforms
    sf::Sprite brownSpr;
    brownSpr.setTexture(brownTxt);

    sf::Sprite greenSpr;
    greenSpr.setTexture(greenTxt);

    sf::Sprite blueSpr;
    blueSpr.setTexture(blueTxt);

    sf::Sprite greenSpringSpr;
    greenSpringSpr.setTexture(greenSpringTxt);

    // deque to hold all of the monster sprites
    std::deque<sf::Sprite> monstersSprite;

    // creates an empty Sprite
    sf::Sprite emptySpr;
    emptySpr.setTexture(emptyTxt);
    monstersSprite.push_front(emptySpr);

    // the following  Sprites to be used for the Monsters
    sf::Sprite blueFlySpr;
    blueFlySpr.setTexture(blueFlyTxt);
    monstersSprite.push_back(blueFlySpr);

    sf::Sprite ninjaSpr;
    ninjaSpr.setTexture(ninjaTxt);
    monstersSprite.push_back(ninjaSpr);

    sf::Sprite wideBlueSpr;
    wideBlueSpr.setTexture(wideBlueTxt);
    monstersSprite.push_back(wideBlueSpr);

    sf::Sprite wideGreenSpr;
    wideGreenSpr.setTexture(wideGreenTxt);
    monstersSprite.push_back(wideGreenSpr);

    sf::Sprite robotSpr;
    robotSpr.setTexture(robotTxt);
    monstersSprite.push_back(robotSpr);

    sf::Sprite bulletSpr;
    bulletSpr.setTexture(bulletTxt);

    sf::Sprite loseSpr;
    loseSpr.setTexture(lostTxt);

    sf::Sprite playAgainSpr;
    playAgainSpr.setTexture(playAgainTxt);

    sf::Sprite holeSpr;
    holeSpr.setTexture(holeTxt);


    // RESETTING ALL ORIGINS TO BE IN CENTER OF SPRITE
    doodleSpr.setOrigin(doodleSpr.getGlobalBounds().height / 2, doodleSpr.getGlobalBounds().width / 2);
    greenSpr.setOrigin(greenSpr.getGlobalBounds().height / 2, greenSpr.getGlobalBounds().width / 2);
    brownSpr.setOrigin(brownSpr.getGlobalBounds().height / 2, brownSpr.getGlobalBounds().width / 2);
    blueSpr.setOrigin(blueSpr.getGlobalBounds().height / 2, blueSpr.getGlobalBounds().width / 2);
    greenSpringSpr.setOrigin(greenSpringSpr.getGlobalBounds().height / 2, greenSpringSpr.getGlobalBounds().width / 2);
    blueFlySpr.setOrigin(blueFlySpr.getGlobalBounds().height / 2, blueFlySpr.getGlobalBounds().width / 2);
    ninjaSpr.setOrigin(ninjaSpr.getGlobalBounds().height / 2, ninjaSpr.getGlobalBounds().width / 2);
    wideGreenSpr.setOrigin(wideGreenSpr.getGlobalBounds().height / 2, wideGreenSpr.getGlobalBounds().width / 2);
    wideBlueSpr.setOrigin(wideBlueSpr.getGlobalBounds().height / 2, wideBlueSpr.getGlobalBounds().width / 2);
    robotSpr.setOrigin(robotSpr.getGlobalBounds().height / 2, robotSpr.getGlobalBounds().width / 2);
    bulletSpr.setOrigin(bulletSpr.getGlobalBounds().height / 2, bulletSpr.getGlobalBounds().width / 2);
    playAgainSpr.setOrigin(playAgainSpr.getGlobalBounds().height / 2, playAgainSpr.getGlobalBounds().width / 2);
    holeSpr.setOrigin(holeSpr.getGlobalBounds().height / 2, holeSpr.getGlobalBounds().width / 2);



    // CREATING THE WINDOW

    // Renders a window with a specified size, titles it "Doodle Jump v2.0!"
    sf::RenderWindow window(sf::VideoMode(width, height), "Doodle Jump v2.0!");
    // controls movement so it's not too fast and erratic
    window.setFramerateLimit(60);


    // GAME MUSIC + SOUNDS

    // Uses the Music feature of SFML by opening a specific file
    sf::Music music;
    if (!music.openFromFile("media/music/Electro music for Doodle Jump.wav"))
    {
        return EXIT_FAILURE;
    }
    // Play the music
    music.play();
    // sets a loop for the music so the music continues playing for the duration of the game
    music.setLoop(true);
   // turn down the music volume to half
    music.setVolume(normalVolumeLevel); 

    // sets the buffer for the Monster sound
    sf::SoundBuffer monsterBuffer;
    monsterBuffer.loadFromFile("media/music/monster-sound.wav");

    // sets the buffer for the jumping sound
    sf::SoundBuffer jumpingBuffer;
    jumpingBuffer.loadFromFile("media/music/jump.wav");

    // sets the buffer for the shooting sound
    sf::SoundBuffer shootingBuffer;
    shootingBuffer.loadFromFile("media/music/shoot.wav");

    // sets the buffer for the breaking brown platform sound
    sf::SoundBuffer breakingBuffer;
    breakingBuffer.loadFromFile("media/music/breaking.wav");

    sf::SoundBuffer losingBuffer;
    losingBuffer.loadFromFile("media/music/lose.wav");

    sf::SoundBuffer shootBuffer;
    shootBuffer.loadFromFile("media/music/shoot.wav");

    sf::SoundBuffer springBuffer;
    springBuffer.loadFromFile("media/music/spring.wav");

    // creates an instance of the Monster Sound
    sf::Sound monsterSound;
    monsterSound.setBuffer(monsterBuffer);

    // creates an instance of the jumping sound
    sf::Sound jumpingSound;
    jumpingSound.setBuffer(jumpingBuffer);

    // creates an instance of the shooting sound
    sf::Sound shootingSound;
    shootingSound.setBuffer(shootingBuffer); 

    // creates an instance of the breaking brown platform sound
    sf::Sound breakingSound;
    breakingSound.setBuffer(breakingBuffer);

    // creates an instance of the losing sound
    sf::Sound losingSound;
    losingSound.setBuffer(losingBuffer);

    sf::Sound shootSound;
    shootSound.setBuffer(shootBuffer);

    sf::Sound springSound;
    springSound.setBuffer(springBuffer);

    // MISC

    // creating a clock for the game
    sf::Clock clock;

    // ENVIRONMENT VARIABLES

    // initializes an empty deque to contain all the platforms
    std::deque<Platform *> greenPlatforms;
    std::deque<Platform *> brownPlatforms;
    std::deque<Platform *> bluePlatforms;
    std::deque<Platform *> greenSpringPlatforms;

    // a deque of all the Monster objects
    std::deque<Monster *> monsters;

    // creates instances of Green Platforms to add onto the Deque to be rendered
    for (int i = 0; i < 15; i++) 
    {
        Platform * platform = new Platform(rand() % 250, rand() % 650);
        greenPlatforms.push_back(platform);
    }

    // creates instances of Brown Platforms to add onto the Deque to be rendered
    for (int i = 0; i < 5; i++) 
    {
        Platform * platform = new Platform(rand() % 250, rand() % 750);
        brownPlatforms.push_back(platform);
    }

    // creates instances of Blue Platforms to add onto the Deque to be rendered
    for (int i = 0; i < 3; i++) 
    {
        Platform * platform = new Platform(rand() % 250, rand() % 750);
        bluePlatforms.push_back(platform);
    }

    // creates instances of Green Spring Platforms to add onto the Deque to be rendered
    for (int i = 0; i < 1; i++) 
    {
        Platform * platform = new Platform(rand() % 250, rand() % 750);
        greenSpringPlatforms.push_back(platform);
    }

    // creates instances of Monsters to add onto the Deque to be rendered 
    for (int i = 0; i < 5; i++) 
    {
        if (i == 0)
        {
            Monster * monster = new Monster(offscreen, offscreen); // instance of no Monster, generate off screen so impossible to run into him
            monsters.push_front(monster);
        }
        else 
        {
            Monster * monster = new Monster(rand() % width, height - 1100);
            monsters.push_back(monster);
        }
    }

    // variables to keep track of inside of game
    int x = height - doodleSpr.getGlobalBounds().height;
    int y = width / 2;
    int ceiling = 200;
    int timeToGenerateMonster = 20;
    int timeToGenerateHole = 15;
    int monsterToGenerate = 0;
    int monstersOnScreen = 0;
    bool isGameOver = false;
    bool holeOnScreen = false;
    int points = 0;
    float dx = 0;
    float dy = 0;

    int playAgainX = 250;
    int playAgainY = 600;

    // a deque of all the bullets in the game currently
    std::deque<Bullet *> bullets;

    // first monster is empty!
    sf::Sprite monsterToRender = monstersSprite[monsterToGenerate];
    Hole * holeToRender = new Hole(offscreen, offscreen);

    // MAIN FUNCTION:

    // a while loop while the window / game is in session
    while (window.isOpen())
    {
        
        // instantiates an instance of what's known as an "Event"
        // an Event can be a mouse pressed, moved, key pressed, etc. anything that makes the game interactive
        sf::Event event;

        // while loop .. while there are events left to do... essentially allows Events to be made
        while (window.pollEvent(event))
        {
            // what to do if the user closes the window ... the window closes
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            else if (isGameOver && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                
                // if the user presses the play again button
                if ((sf::Mouse::getPosition(window).x < (playAgainX + playAgainSpr.getGlobalBounds().width / 2))
                    && (sf::Mouse::getPosition(window).x > (playAgainX - playAgainSpr.getGlobalBounds().width / 2))
                    && (sf::Mouse::getPosition(window).y > (playAgainY - playAgainSpr.getGlobalBounds().height / 2))
                    && (sf::Mouse::getPosition(window).y < (playAgainY + playAgainSpr.getGlobalBounds().height / 2))
                    )
                {
                    // restart the game by resetting the variables
                    x = height - doodleSpr.getGlobalBounds().height;
                    y = width / 2;
                    monstersOnScreen = 0;
                    monsterToGenerate = 0;
                    isGameOver = false;
                    points = 0;
                    music.play();
                    dx = 0;
                    dy = 0;

                    // restart the time to 0
                    clock.restart();
                }

            }

            // what to do when the mouse is moved within the window
            else if (event.type == sf::Event::MouseMoved)
            {
                // moves the x position so it follows the mouse wherever it goes
                // does NOT follow it's y position (keeps the current y position by using getPosition())
                // keeps y position because in Doodle Jump the player CANNOT control the y position of the player
                // doodleSpr.setPosition(event.mouseMove.x, doodleSpr.getPosition().y);
                x = event.mouseMove.x;
            }

            // if the user shoots then push a new bullet onto the bullets deque
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                Bullet * bullet = new Bullet(x, y);
                bullets.push_front(bullet);
                shootSound.play();
            }

        }

        // GENERAL 

        // for when I need to access the time elapsed
        sf::Time time1 = clock.getElapsedTime();


        // DIFFICULTY


        // SCORE

        if (!isGameOver && (int) time1.asSeconds() % 5 == 0) 
        {
            points += 10;
        }

        // MONSTER HANDLING

        // make sure the empty monster doesn't enter the screen
        if (monsters[0]->getX() != offscreen 
            || monsters[0]->getY() != offscreen) 
        {
            monsters[0]->setX(offscreen);
            monsters[0]->setY(offscreen);
        }

        // chooses which monster to generate
        if ( (int) time1.asSeconds() % timeToGenerateMonster == 0 && (int) time1.asSeconds() * 1 != 0 && monstersOnScreen == 0)
        {

            // there is a monster on the screen
            monstersOnScreen++;

            // play the monster sound
            monsterSound.play();
            monsterSound.setLoop(true);

            // generate a new monster skin
            monsterToGenerate = rand() % monsters.size();
            // choose a random skin for the monster if the random generated 0 (we don't want an empty monster)
            while (monsterToGenerate == 0) {
                monsterToGenerate = rand() % monsters.size();
            }
            monsterToRender = monstersSprite[monsterToGenerate];
            // set the position of the Sprite from the monsters Deque
            monsters[monsterToGenerate]->setX(monsters[monsterToGenerate]->getX());
            monsters[monsterToGenerate]->setY(monsters[monsterToGenerate]->getY());

        }

        // HOLE GENERATION
        if ( (int) time1.asSeconds() % timeToGenerateHole == 0 && (int) time1.asSeconds() * 1 != 0 && !holeOnScreen)
        {
            holeToRender->setX(100);
            holeToRender->setY(-1000);
            holeOnScreen = true;
        }

        // HANDLING SCROLLING AND MOVEMENT

        // if the user wants to use the keys instead of the mouse
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { x = x - 5; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { x = x + 5; }

        // handle gravity
        dy += gravity;
        y += dy;

        // HANDLES LOSING THE GAME

        if ((((x + 25 > monsters[monsterToGenerate]->getX()) 
                && (x < monsters[monsterToGenerate]->getX() + 100)
                && (y + 64 > monsters[monsterToGenerate]->getY()) 
                && (y < monsters[monsterToGenerate]->getY() + 90))
            || (y > height - 37.5)
            || ((x + 10 > holeToRender->getX()) 
                && (x < holeToRender->getX() + 40)
                && (y + 50 > holeToRender->getY()) 
                && (y < holeToRender->getY() + 60))) 
            && (!isGameOver))
        {
            isGameOver = true;
            losingSound.play();
            monsterSound.stop();
        }
        // what to do when the user reaches a certain height (generate new stuff)
        else if (y < ceiling) 
        {

            y = ceiling;

            // generate new green platforms when doodle reaches certain height
            for (int i = 0; i < greenPlatforms.size(); i++) 
            {
                greenPlatforms[i]->setY(greenPlatforms[i]->getY() - dy);

                if (greenPlatforms[i]->getY() > height) 
                {
                    greenPlatforms[i]->setX(rand() % width);
                    greenPlatforms[i]->setY(0);
                }

            }

            // generate new brown platforms when doodle reaches certain height
            for (int i = 0; i < brownPlatforms.size(); i++) 
            {
                brownPlatforms[i]->setY(brownPlatforms[i]->getY() - dy);

                if (brownPlatforms[i]->getY() > height) 
                {
                    brownPlatforms[i]->setX(rand() % width);
                    brownPlatforms[i]->setY(0);
                }
            }

            // generate new brown platforms when doodle reaches certain height
            for (int i = 0; i < bluePlatforms.size(); i++) 
            {
                bluePlatforms[i]->setY(bluePlatforms[i]->getY() - dy);

                if (bluePlatforms[i]->getY() > height) 
                {
                    bluePlatforms[i]->setX(rand() % width);
                    bluePlatforms[i]->setY(0);
                }
            }

            // generate new green spring platforms when doodle reaches certain height
            for (int i = 0; i < greenSpringPlatforms.size(); i++) 
            {
                greenSpringPlatforms[i]->setY(greenSpringPlatforms[i]->getY() - dy);

                if (greenSpringPlatforms[i]->getY() > height) 
                {
                    greenSpringPlatforms[i]->setX(rand() % width);
                    greenSpringPlatforms[i]->setY(0);
                }
            }

            // monster generation to scroll with the screen
            monsters[monsterToGenerate]->setY(monsters[monsterToGenerate]->getY() - dy);

            // if the monster leaves the screen
            if (monsters[monsterToGenerate]->getY() > height)
            {
                // render an empty monster
                monsterToRender = emptySpr;
                monsterToRender.setPosition(0,0);
                // reset that monster's position back to regular position
                monsters[monsterToGenerate]->setX(100);
                monsters[monsterToGenerate]->setY(height - 1100);
                // make sure that monstersOnScreen can't be negative
                if (monstersOnScreen > 0) {
                    monstersOnScreen = 0;
                }
                // stop the monster sound
                monsterSound.stop();
            }

            // scroll with the screen
            holeToRender->setY(holeToRender->getY() - dy);

            // if the hole leaves the screen
            if (holeToRender->getY() > height)
            {
                holeOnScreen = false;
            }

        }

        // shooting bullets
        else if (!bullets.empty()) 
        {
            for (int i = 0; i < bullets.size(); i++) {

                // set the bullets to go up from the doodle character
                // bullets[i].setX(bullets[i]->getX() + 1);
                bullets[i]->setY(bullets[i]->getY() - 20);

                // if a bullet hits a monster!
                if ((bullets[i]->getX() + 25 > monsters[monsterToGenerate]->getX())
                    && (bullets[i]->getX() < monsters[monsterToGenerate]->getX() + 100)
                    && (bullets[i]->getY()+ 64 > monsters[monsterToGenerate]->getY()) 
                    && (bullets[i]->getY() < monsters[monsterToGenerate]->getY() + 90))
                    {
                        points += 250;
                        // render an empty monster
                        monsterToRender = emptySpr;
                        monsterToRender.setPosition(0,0);
                        // reset that monster's position back to regular position
                        monsters[monsterToGenerate]->setX(100);
                        monsters[monsterToGenerate]->setY(height - 1100);
                        // make sure that monstersOnScreen can't be negative
                        if (monstersOnScreen > 0) {
                            monstersOnScreen = 0;
                        }
                        // stop the monster sound
                        monsterSound.stop();
                    }

                if (bullets[i]->getY() < 0) 
                {
                    bullets.pop_back();
                }
            }
        }

        // collision handling for green platforms
        for (int i = 0; i < greenPlatforms.size(); i++) 
        {
            if ((x + 17 > greenPlatforms[i]->getX()) 
                && (x < greenPlatforms[i]->getX() + 80)
                && (y + 50 > greenPlatforms[i]->getY()) 
                && (y < greenPlatforms[i]->getY()) 
                && (dy > 0))
                {
                    dy = -10;
                    jumpingSound.play();
                }
        }

        // collision handling for brown platforms
        for (int i = 0; i < brownPlatforms.size(); i++) 
        {
            if ((x + 17 > brownPlatforms[i]->getX()) 
                && (x < brownPlatforms[i]->getX() + 80)
                && (y + 50 > brownPlatforms[i]->getY()) 
                && (y < brownPlatforms[i]->getY()) 
                && (dy > 0))
                {
                    brownPlatforms[i]->disappear();
                    breakingSound.play();
                }
        }

        // collision handling for brown platforms
        for (int i = 0; i < bluePlatforms.size(); i++) 
        {
            if ((x + 17 > bluePlatforms[i]->getX()) 
                && (x < bluePlatforms[i]->getX() + 80)
                && (y + 50 > bluePlatforms[i]->getY()) 
                && (y < bluePlatforms[i]->getY()) 
                && (dy > 0))
                {
                    dy = -10;
                    jumpingSound.play();
                }
        }

        // collision handling for brown platforms
        for (int i = 0; i < greenSpringPlatforms.size(); i++) 
        {
            if ((x + 17 > greenSpringPlatforms[i]->getX()) 
                && (x < greenSpringPlatforms[i]->getX() + 80)
                && (y + 50 > greenSpringPlatforms[i]->getY()) 
                && (y < greenSpringPlatforms[i]->getY()) 
                && (dy > 0))
                {
                    dy = -20;
                    springSound.play();
                }
        }

        // SETTING INITIAL POSITION
        if (time1.asSeconds() < 3) 
        {
            doodleSpr.setPosition(width / 2, height - 250);
            dy = -5;
        } 
        else 
        {
            doodleSpr.setPosition(x, y);
        }

        // RENDERING SPRITES AND THE GAME

        window.clear();
        window.draw(backgroundSpr);
       
        if (isGameOver) {

            sf::Font font;
            font.loadFromFile("media/fonts/DoodleJump.ttf");

            sf::Text scoreText;
            scoreText.setFont(font);

            std::stringstream ss;
            ss << "Score: ";
            ss << points;

            scoreText.setString( ss.str().c_str() );
            scoreText.setCharacterSize(75);
            scoreText.setFillColor(sf::Color::Green);
            scoreText.setPosition(75, 250);

            // stop the music
            music.stop();
            // set the positions of the buttons
            loseSpr.setPosition(50, 300);
            playAgainSpr.setPosition(playAgainX, playAgainY);
            // draws the necessary sprites
            window.draw(loseSpr);
            window.draw(playAgainSpr);
            window.draw(scoreText);

            dy = 10;
        } 
        else 
        {
            // rendering all of the green platforms
            for (int i = 0; i < greenPlatforms.size(); i++) 
            {
                greenSpr.setPosition(greenPlatforms[i]->getX(), greenPlatforms[i]->getY());
                window.draw(greenSpr);
            }
            // rendering all of the brown platforms
            for (int i = 0; i < brownPlatforms.size(); i++) 
            {
                if (!brownPlatforms[i]->getIsGone()) {
                    brownSpr.setPosition(brownPlatforms[i]->getX(), brownPlatforms[i]->getY());
                    window.draw(brownSpr);
                }
            }
            // rendering all of the blue platforms
            for (int i = 0; i < bluePlatforms.size(); i++) 
            {
                int blueMoveFactor;

                if (bluePlatforms[i]->getX() < 0 + 34)
                { 
                    blueMoveFactor = 3;
                }
                else if (bluePlatforms[i]->getX() > width - 34)
                {
                    blueMoveFactor = -3;
                }

                bluePlatforms[i]->setX(bluePlatforms[i]->getX() + blueMoveFactor);
                blueSpr.setPosition(bluePlatforms[i]->getX(), bluePlatforms[i]->getY());

                window.draw(blueSpr);
            }
            // rendering all of the green spring platforms
            for (int i = 0; i < greenSpringPlatforms.size(); i++) 
            {
                greenSpringSpr.setPosition(greenSpringPlatforms[i]->getX(), greenSpringPlatforms[i]->getY());
                window.draw(greenSpringSpr);
            }
            // rendering all of the bullets
            for (int i = 0; i < bullets.size(); i++)
            {
                bulletSpr.setPosition(bullets[i]->getX(), bullets[i]->getY());
                window.draw(bulletSpr);
            }
            if (holeOnScreen)
            {
                holeSpr.setPosition(holeToRender->getX(), holeToRender->getY());
                window.draw(holeSpr);
            } 
            else if (!holeOnScreen)
            {
                holeSpr.setPosition(offscreen, offscreen);
                window.draw(emptySpr);
            }
            // sets the position of the monster at its current position
            monsterToRender.setPosition(monsters[monsterToGenerate]->getX(), monsters[monsterToGenerate]->getY());
            // renders the monster
            window.draw(monsterToRender);
            window.draw(doodleSpr);
        }

        window.display();
    
    }

    // CLEANING UP MEMORY LEAKS

    for (int i = 0; i < greenPlatforms.size(); i++) 
    {
        delete greenPlatforms[i];
    }
    // delete[] greenPlatforms;

    for (int i = 0; i < brownPlatforms.size(); i++) 
    {
        delete brownPlatforms[i];
    }
    // delete[] brownPlatforms;

    for (int i = 0; i < bluePlatforms.size(); i++) 
    {
        delete bluePlatforms[i];
    }
    // delete[] bluePlatforms;

    for (int i = 0; i < greenSpringPlatforms.size(); i++) 
    {
        delete greenSpringPlatforms[i];
    }
    // delete[] greenSpringPlatforms;

    for (int i = 0; i < monsters.size(); i++) 
    {
        delete monsters[i];
    }
    // delete[] monsters;

    for (int i = 0; i < bullets.size(); i++)
    {
        delete bullets[i];
    }
    // delete[] bullets;

    delete holeToRender;

    return 0;
}