#include <iostream>
#include "App.h"

App* singleton;

void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    
    // If you want to manipulate the app in here
    // do it through the singleton pointer
    
    if (singleton->up){
        float ypos = singleton->projectile->getY();
        ypos +=0.05;
        singleton->projectile->setY(ypos);
        singleton->redraw();

        if (singleton->mushroom->contains(0, ypos-0.05)) {
            singleton->up = false;
            singleton->mushroomVisible = false;
            singleton->projectileVisible = false;
            singleton->explosion->playOnce();
        }
    }
    
    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    mushroom = new TexRect("mushroom.png", -0.25, 0.9, 0.5, 0.5);
    projectile = new Rect(-0.05, -0.8, 0.1, 0.1);
    explosion = new AnimatedRect("fireball.bmp", 6, 6, 50, false, false, -0.25, 0.9, 0.5, 0.5);
    up = false;
    
    mushroomVisible = true;
    projectileVisible = true;
    singleton = this;
    
    timer(1);
}

void App::draw() {
    if (mushroomVisible) {
        mushroom->draw(0.1);
    }
    if (mushroomVisible) {
    projectile->draw();
    }
    explosion->draw(0.1);
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    if (key == ' '){
        up = true;
    }
}

App::~App(){
    delete mushroom;
    delete projectile;
    delete explosion;
    std::cout << "Exiting..." << std::endl;
}
