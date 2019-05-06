#include <iostream>
#include "App.h"

App* singleton;

void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    
    // If you want to manipulate the app in here
    // do it through the singleton pointer

    singleton->bg1->setX(singleton->bg1->getX() - singleton->speed);
    singleton->bg2->setX(singleton->bg2->getX() - singleton->speed);

    if (singleton->bg1->getX() < -6) {
        singleton->bg1->setX(2);
    } else if (singleton->bg2->getX() < -6) {
        singleton->bg2->setX(2);
    }

    singleton->redraw();

    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    singleton = this;

    speed = 0.025;

    bg1 = new TexRect("bg.png", 2, 1, 4, 2);
    bg2 = new TexRect("bg.png", -2, 1, 4, 2);
    cat = new AnimatedRect("cat.png", 4, 2, 75, true, false, -0.5, -0.25, 1, 0.5);

}

void App::draw() {
    bg1->draw(0.0);
    bg2->draw(0.0);
    cat->draw(1.0);

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    } else if (key == ' ') {
        glutTimerFunc(16, timer, key);
        cat->playLoop();
        cat->action();
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}
