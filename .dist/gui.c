#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv){
    SDL_Window *window=NULL;


    if (SDL_Init(SDL_INIT_VIDEO)!=0){
        SDL_Log("Erreur initialisation SDL >%s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    window=SDL_CreateWindow("first window sdl 2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);

    if(window==NULL){
        SDL_Log("Erreur initialisation SDL >%s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Delay(1000000000);



    SDL_Quit();
}