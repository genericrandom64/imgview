/*
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 
  
int main(int argc, char *argv[]) 
{ 
  
    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    } 
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       768, 768, 0); 
  
    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; 
  
    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags); 
  
    // creates a surface to load an image into the main memory 
    SDL_Surface* surface;
    SDL_Surface* surface2; 
    SDL_Surface* bgsurf; 
  
    // please provide a path for your image 
    surface = IMG_Load(argv[2]); 
    surface2 = IMG_Load(argv[1]);
    // loads image to our graphics hardware memory. 
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface); 
    SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    // clears main-memory 
    SDL_FreeSurface(surface); 
    SDL_FreeSurface(surface2);  

    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest; 
    SDL_Rect dest2;
    SDL_Rect bg;
    // connects our texture with dest to control position 
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); 
    SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);
    int dw = atoi(argv[3]);
    int dh = atoi(argv[4]);
    // adjust height and width of our image box. 
    dest.w /= dw; 
    dest.h /= dh; 
  
    // sets initial x-position of object 
    dest.x = (768 - dest.w) / 2; 
  
    // sets initial y-position of object 
    dest2.x = (768 - dest2.w);

    // sets initial y-position of object
    dest2.y = (768 - dest2.h);


    dest.y = (768 - dest.h) / 2; 
  
    // controls annimation loop 
    int close = 0; 
  
    // speed of box 
    int speed = 400; 
  
    // annimation loop 
    while (!close) { 
        SDL_Event event; 
  
        // Events mangement 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
  
            case SDL_QUIT: 
                // handling of close button 
                close = 1; 
                break; 
  
            case SDL_KEYDOWN: 
                // keyboard API for key pressed 
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
                case SDL_SCANCODE_ESCAPE:
                    printf("play time is over, go to your terminal\n");
                    exit(0);
                } 
            } 
        } 
  
        // right boundary 
        if (dest.x + dest.w > 768) 
            dest.x = 768 - dest.w; 
  
        // left boundary 
        if (dest.x < 0) 
            dest.x = 0; 
  
        // bottom boundary 
        if (dest.y + dest.h > 768) 
            dest.y = 768 - dest.h; 
  
        // upper boundary 
        if (dest.y < 0) 
            dest.y = 0; 
  
        // clears the screen 
        SDL_RenderClear(rend); 
        SDL_RenderCopy(rend, tex, NULL, &dest); 
        SDL_RenderCopy(rend, tex2, NULL, &dest2);
        SDL_FillRect(bgsurf, NULL, 0xFFFFFF);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend); 
  
        // calculates to 60 fps 
        SDL_Delay(768 / 60); 
    } 
  
    // destroy texture 
    SDL_DestroyTexture(tex); 
    SDL_DestroyTexture(tex2);
    // destroy renderer 
    SDL_DestroyRenderer(rend); 
  
    // destroy window 
    SDL_DestroyWindow(win); 
    return 0; 
} */

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


