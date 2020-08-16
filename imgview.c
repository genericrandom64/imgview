#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 
  
int w = 500;
int h = 500;
int ww = 500;
int wh = 500;
int xbound;
int ybound;
char* title;

int main(int argc, char *argv[]) 
{ 

if(argc <= 1) {
printf("\033[1;31mNot enough args!\033[0m\n\n\033[1mCorrect Usage \033[0m(\033[1;31m[required] \033[1;32m<optional>\033[0m): \n\033[1mimgview \033[1;31m[image-path] \033[1;32m<display-height display-width> <window-height window-width>\n\n\033[0m");
exit(0);
}
if(argc >= 4) { 
    w = atoi(argv[2]);
    h = atoi(argv[3]);
}
if(argc >= 6) {
ww = atoi(argv[4]);
wh = atoi(argv[5]);
}

title = argv[1];
xbound = ww + (ww / 2);
ybound = wh + (wh / 2);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    }

    SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ww, wh, 0); 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags); 
    SDL_Surface* surface; 
    surface = IMG_Load(argv[1]); 
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface); 
    SDL_FreeSurface(surface); 
    SDL_Rect dest; 
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); 
    dest.w = w; 
    dest.h = h; 
    dest.x = (ww - dest.w) / 2; 
    dest.y = (wh - dest.h) / 2; 
    int close = 0; 
    int speed = 300; 

    while (!close) { 
        SDL_Event event; 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
            case SDL_QUIT: 
                close = 1; 
                break; 
            case SDL_KEYDOWN: 
                switch (event.key.keysym.scancode) { 
                case SDL_SCANCODE_W: 
                case SDL_SCANCODE_UP: 
                    dest.y -= speed / 30; 
                    break; 
                case SDL_SCANCODE_A: 
                case SDL_SCANCODE_LEFT: 
                    dest.x -= speed / 30; 
                    break; 
                case SDL_SCANCODE_S: 
                case SDL_SCANCODE_DOWN: 
                    dest.y += speed / 30; 
                    break; 
                case SDL_SCANCODE_D: 
                case SDL_SCANCODE_RIGHT: 
                    dest.x += speed / 30; 
                    break; 
                } 
            } 
        } 
  
        if (dest.x + dest.w > xbound) 
            dest.x = xbound - dest.w; 
        if (dest.x < 0 - (ww / 2)) 
            dest.x = 0 - (ww / 2); 
        if (dest.y + dest.h > ybound) 
            dest.y = ybound - dest.h; 
        if (dest.y < 0 - (wh / 2)) 
            dest.y = 0 - (wh / 2); 

        SDL_RenderClear(rend); 
        SDL_RenderCopy(rend, tex, NULL, &dest); 
        SDL_RenderPresent(rend); 
        SDL_Delay(ww / 30); 
    } 
  
    SDL_DestroyTexture(tex); 
    SDL_DestroyRenderer(rend); 
    SDL_DestroyWindow(win); 
return 0;
} 


