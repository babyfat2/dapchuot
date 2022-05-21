#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL_mixer.h>
#include "Image.h"
#include "ClickMouse.h"
using namespace std;
int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("dap chuot",
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          993, 500,
                          SDL_WINDOW_SHOWN
                          );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Image setmenu;
    setmenu.renderMenu(renderer);
    SDL_RenderPresent(renderer);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music* music;
    music = Mix_LoadMUS("ass/music/vonguoita.mp3");
    Mix_PlayMusic(music, 0);
    Mix_Chunk* ClickMusic;
    ClickMusic = Mix_LoadWAV("ass/music/hammering.wav");
    if( ClickMouse(420,370,560,390) )
    {
        int score = 0;
        Image setmap;
        int thoigian = 60;
        int time = SDL_GetTicks();
        do {
                int a = rand()%3;
                int b = rand()%3;
                setmap.renderMedia(renderer,thoigian,score,a,b);
                SDL_RenderPresent(renderer);
                SDL_Event event;
                SDL_Delay(1000);
                while(SDL_PollEvent(&event)) {
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    if(event.type == SDL_MOUSEBUTTONDOWN) {
                            if ((100+315*a<x)&&(x<180+315*a)&&(-5+160*b<y)&&(y<85+160*b))
                                 {
                                   Mix_PlayChannel(-1, ClickMusic, 0);
                                   score ++;
                                   Image setPlay;
                                   setPlay.renderMedia2(renderer,thoigian,score,a,b);
                                   SDL_RenderPresent(renderer);
                                   SDL_Delay(100);
                                 }
                         }
                }
                thoigian = 60 - (SDL_GetTicks()-time)/1000;
                setmap.renderText(renderer,"TIME: "+ to_string(thoigian)+ " s",{255,0,126,255},0,0);
        } while(thoigian > 0);
        Image setEndGame;
        setEndGame.renderEndGame(renderer,score);
        SDL_RenderPresent(renderer);
        if(ClickMouse(450,370,510,390)){
           Mix_CloseAudio();
           SDL_DestroyWindow(window);
           SDL_DestroyRenderer(renderer);
           SDL_Quit();
           return 0;
           }
    }
}
