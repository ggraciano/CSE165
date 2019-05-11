#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 400, 800, "Exploding Shroom");

    app->run();
}
