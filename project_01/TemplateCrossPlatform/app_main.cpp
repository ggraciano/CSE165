#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 600, 1200, "Space Invaders Clone");

    app->run();
}
