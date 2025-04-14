#ifndef CACHAM_H_
#define CACHAM_H_

#include"toancuc.h"

SDL_Renderer* createRenderer(SDL_Window* window);
void logErrorAndExit(const char* msg, const char* error);
SDL_Window* initSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const char* WINDOW_TITLE);
//hinh anh + backround
SDL_Texture *loadTexture(const char *filename,SDL_Renderer* renderer);
void renderTexture(SDL_Texture *texture, int x, int y, int w, int h, SDL_Renderer* renderer);

void hinh_anh_player(const char* filename , SDL_Texture**player1,int Red, int Green, int Blue);
void player_in(SDL_Renderer* renderer, SDL_Texture* player, int playerX, int playerY, const int playerW, const int playerH); 
void renderScrollingBackground(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int backgroundWidth, int* backgroundX);
void background_dung(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int backgroundWidth, int* backgroundX);
bool chuot (int mouseX, int mouseY, SDL_Rect Start);

void cot_troi(SDL_Renderer* renderer, SDL_Texture* cotTop, SDL_Texture* cotBot, int* Col_X, int* Col_H, int* Col_H1, int* Col_X1, int col_H_duoi, int gap);
void cot_dung(SDL_Renderer* renderer, SDL_Texture* cotTop, SDL_Texture* cotBot, int* Col_X, int* Col_H, int* Col_H1, int* Col_X1, int col_H_duoi, int gap);
bool vacham(int *playerX, int*playerY, int*Col_X, int*Col_H, int*Col_X1, int*Col_H1);
void reset (int* playerX, int* playerY, int* Col_X, int*Col_X1, int*backgroundX);

void hoat_anh(int vantoc, SDL_Texture**p, SDL_Texture*p1, SDL_Texture*p2);
void hanh_dong(float* playerVelocity, float gravity, int* playerY, const int playerH, const int SCREEN_HEIGHT);
void hien_menu ( SDL_Texture* menu, SDL_Texture* start, SDL_Rect startRect);
void hien_gameover(SDL_Renderer*renderer, SDL_Texture* gameover, SDL_Texture* restart, SDL_Rect restartRect);

void hien_diemso(int score, SDL_Texture* textTexture, int scoreX, int scoreY, int scoreW, int scoreH);

void exit();
#endif
