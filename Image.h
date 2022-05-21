#ifndef Image__H
#define Image__H

#include <SDL.h>
#include <SDl_image.h>
#include <SDL_ttf.h>
#include <string>

class Image
{
private :
    SDL_Texture* backgroundInGame;
    SDL_Texture* mouse[3][3];
    SDL_Texture* backgroundMenu;
    SDL_Texture* backgroundEndGame;
    SDL_Texture* loadImage(SDL_Renderer* renderer, const std::string path);
public :
    Image();
    ~Image();

    void renderText(SDL_Renderer* renderer, std::string text, SDL_Color color, int posX, int posY);
    void renderMedia(SDL_Renderer* renderer,int Time,int Score,int a,int b);
    void renderMedia2(SDL_Renderer* renderer,int Time,int Score, int a,int b);
    void renderMenu(SDL_Renderer* renderer);
    void renderEndGame(SDL_Renderer* renderer,int Time);
};
#endif // Image__H
