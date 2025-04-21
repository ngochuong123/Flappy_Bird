#ifndef TOANCUC_H_
#define TOANCUC_H_
// Khai báo thư viện
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <fstream> 

using namespace std;
// Các thông số cửa sổổ
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
extern const char* WINDOW_TITLE;
extern const int nen;
extern const int delay;
extern const int Min;
extern const int Max;
extern int score;
extern int scoreMax;
extern int volume;
// các thông số của cột
extern const int Col_W;
extern int Col_X;
extern const int Col_startX;
extern const int kc_col;
extern int Col_X1;
extern const int Col_startX1;
extern int Col_Y;
extern int Col_H;
extern int Col_H1;
extern const int gap;
extern int col_H_duoi;
//cac thong so player
extern int playerX;
extern const int playerstartX;
extern int playerY;
extern const int playerstartY;

extern const int playerW;
extern const int playerH;
extern float playerVelocity;
extern const float gravity;
extern const float jumpForce; 
extern bool running ;
extern bool again;
extern bool xoa;
extern bool va_amthanh;
extern bool cd1;
extern bool cd2;
extern const int startX;
extern const int startY;
extern const int startW;
extern const int startH;

extern const int restartX ;
extern const int restartY ;
extern const int restartW ;
extern const int restartH ;

extern const int gameoverX ;
extern const int gameoverY ;
extern const int gameoverW ;
extern const int gameoverH ;

extern const int scoreX;
extern const int scoreY;
extern const int scoreW;
extern const int scoreH;

extern const int scoreMX;
extern const int scoreMY;
extern const int scoreMW;
extern const int scoreMH;
//xóa nền = RGB
extern const int Red;
extern const int Green;
extern const int Blue;

extern const int Red1;
extern const int Green1;
extern const int Blue1;
//các thông số backgroundbackground
extern const int SCROLL_SPEED;
extern int backgroundX;
extern const int backgroundstart;
extern int backgroundWidth;
extern int backgroundHeight;

extern const int k_t_chu;
extern const Uint8 RedC;
extern const Uint8 GreenC;
extern const Uint8 BlueC;
extern const Uint8 bongC;
// Các biến toàn cục khác
extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern SDL_Texture* texture;
extern SDL_Texture* player1;
extern SDL_Texture* player2;
extern SDL_Texture* player;
extern SDL_Event e;
extern SDL_Texture* background;
extern SDL_Texture* menu;
extern SDL_Texture* start;
extern SDL_Texture* chuyen_canh;
extern SDL_Texture* cotTop;
extern SDL_Texture* cotBot;
extern SDL_Texture* gameover;
extern SDL_Texture* restart;
// Các biến hình chữ nhật 
extern SDL_Rect startRect;
extern SDL_Rect gameoverRect;
extern SDL_Rect restartRect;
//âm thanh
extern Mix_Chunk* nhay; 
extern Mix_Chunk* va;
extern Mix_Music* nen_nhac;
extern Mix_Chunk* congdiem;
//phông chữ
extern TTF_Font* diemso;
extern SDL_Color diemsoColor;
extern SDL_Texture* textTexture;
extern SDL_Texture* textTexture1;
#endif // TOANCUC_H_