#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Projecter.hpp"
#include "Clipper.hpp"

// The following render code is an abtraction layer around SDL2. It is designed so the Render platfom can be swapped easily if needed.
// This, unlike GLM, is not highly intergrated into the code, so removing SDL2 should not break things as long as you replace the functions :).

namespace Croire {  
    namespace Renderer
    {
        // Globals
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        // Create Window
        void create_window(int width, int height, const char* title) {
            SDL_Init(SDL_INIT_VIDEO);
            window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }

        // Check If Window Has Been Closed
        bool is_open() {
            SDL_Event event;
            SDL_PollEvent(&event);
 
            switch (event.type)
            {
                case SDL_QUIT:
                    return false;
            }

            return true;
        }

        // Clear Window
        void clear(int r, int g, int b) {
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderClear(renderer);
        }

        // Update Window
        void update() {
            SDL_RenderPresent(renderer);
        }

        // Drawing (Only If Projected Point Is In Front Of Screen)
        void draw_line(glm::vec3 point1, glm::vec3 point2, int r, int g, int b) {
            if (Croire::Clipper::behind_screen(point1) || Croire::Clipper::behind_screen(point2)) {
                return;
            }

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawLine(renderer, (int) point1.x, (int) point1.y, (int) point2.x,  (int) point2.y);
        }

        void draw_triangle(std::vector<glm::vec3> points, int r, int g, int b) {
            draw_line(points[0], points[1], r, g, b);
            draw_line(points[1], points[2], r, g, b);
            draw_line(points[2], points[0], r, g, b);
        }
    }
}