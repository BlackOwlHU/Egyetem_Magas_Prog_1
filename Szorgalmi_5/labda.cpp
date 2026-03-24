#include <SDL2/SDL.h>
#include <iostream>

//LInux Mint -en tesztelve
//sudo apt install libsdl2-dev
//fordítás: g++ main.cpp -o dvd -lSDL2
//fuittatás: ./dvd

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init error\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Pattogó labda",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Labda adatok
    int x = 100, y = 100;
    int size = 50;
    int dx = 5, dy = 5;

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = false;
        }

        // Mozgás
        x += dx;
        y += dy;

        // Ütközés falakkal
        if (x <= 0 || x + size >= SCREEN_WIDTH)
            dx = -dx;

        if (y <= 0 || y + size >= SCREEN_HEIGHT)
            dy = -dy;

        // Törlés
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Labda kirajzolása (négyzet)
        SDL_Rect rect = {x, y, size, size};
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
