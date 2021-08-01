#include "Game.h"
#include "Vector2d.h"

#include "Random.h"

#include <SDL2/SDL.h>

#include <iostream>

int main(int, char**) 
{

    // Vector2d<int> vec(1, 1);
    // Vector2d<int> vec2(2, 2);
    // vec = vec + vec2;
    // vec += vec2;
    // vec2.x = 2;
    // vec2.y = 2;
    // vec = vec * vec2;

    Random::init();

    Game game(1920, 1080, "Hello");
    game.mainLoop();


    return 0;
}
