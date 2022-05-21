#include "Image.h"
using namespace std;

Image :: Image()
{
    for (int i=0;i <3; i++) {
        for (int j=0; j < 3;j++) {
        mouse[i][j] = nullptr;
        }
    }
}
Image ::~Image()
{
    for (int i=0; i <3; i++){
            for (int j=0; j < 3;j++){
            if(mouse[i][j] != nullptr)
            {
            SDL_DestroyTexture(mouse[i][j]);
            mouse[i][j] = nullptr;
            }
            }
    }
}


SDL_Texture* Image::loadImage(SDL_Renderer* renderer, const std::string path)
{
    SDL_Surface* image = IMG_Load(path.c_str());
    SDL_Texture* loadTexture = SDL_CreateTextureFromSurface(renderer,image);
    SDL_FreeSurface(image);
    return loadTexture;
}

void Image::renderText(SDL_Renderer* renderer, std::string text, SDL_Color color, int posX, int posY)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("x.ttf",20);
    SDL_Surface* textSurface = TTF_RenderText_Blended(font,text.c_str(),color);
    SDL_Rect dsRect = {posX ,posY , textSurface->w, textSurface->h};
    SDL_Texture* textTure = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer,textTure, nullptr, &dsRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTure);
    TTF_CloseFont(font);
}
void Image::renderMedia(SDL_Renderer* renderer,int Time,int Score, int a,int b)
{
    backgroundInGame = loadImage(renderer,"ass/images/background.png");
    SDL_RenderCopy(renderer, backgroundInGame, NULL, NULL);
    for (int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            SDL_Rect dsRect;
            mouse[i][j] = loadImage(renderer,"ass/images/mouse.png");
            dsRect = {100+315*i, -5 + 160*j, 80, 90};
            if( (i == a)  && (j == b))
            {
                SDL_RenderCopy(renderer, mouse[i][j], nullptr, &dsRect);
            }
        }
    }
    renderText(renderer, "Time: " + to_string(Time) +" s", {255, 126, 0, 255}, 0,0 );
    renderText(renderer, "Score: " + to_string(Score), {255, 126, 0, 255}, 0,30 );
}
void Image::renderMedia2(SDL_Renderer* renderer,int Time,int Score, int a,int b)
{
    backgroundInGame = loadImage(renderer,"ass/images/background.png");
    SDL_RenderCopy(renderer, backgroundInGame, NULL, NULL);
    for (int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            SDL_Rect dsRect;
            mouse[i][j] = loadImage(renderer,"ass/images/mouse2.png");
            dsRect = {100+315*i, -5 + 160*j, 80, 90};
            if( (i == a)  && (j == b))
            {
                SDL_RenderCopy(renderer, mouse[i][j], nullptr, &dsRect);
            }
        }
    }
    renderText(renderer, "Time: " + to_string(Time) + " s", {255, 126, 0, 255}, 0,0 );
    renderText(renderer, "Score: " + to_string(Score), {255, 126, 0, 255}, 0,30 );
}
void Image::renderMenu(SDL_Renderer* renderer) {
    backgroundMenu = loadImage(renderer,"ass/images/menu.jpg");
    SDL_RenderCopy(renderer, backgroundMenu,NULL ,NULL );
    renderText(renderer,"PLAY GAME",{0,126,0,255},425,370);
}
void Image::renderEndGame(SDL_Renderer* renderer,int Score) {
    backgroundEndGame = loadImage(renderer,"ass/images/Endgame.jpg");
    SDL_RenderCopy(renderer,backgroundEndGame,NULL,NULL);
    renderText(renderer,"SCORE: " + to_string(Score) ,{0,126,0,255},450,350);
    renderText(renderer,"QUIT",{0,126,0,255},450,370);
}
