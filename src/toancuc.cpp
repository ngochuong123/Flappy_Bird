#include "toancuc.h"

//cac thong so
const int SCREEN_WIDTH = 500 ;
const int SCREEN_HEIGHT = 700 ;
const char* WINDOW_TITLE = "Flappy_bird";
const int nen = 110;
const int delay = 16;
const int Min = 80;
const int Max = 300;
int score = 0;
int scoreMax = 0;
int volume = MIX_MAX_VOLUME / 2;
//cột
    const int Col_W = 70;
    int Col_X = SCREEN_WIDTH - Col_W;
    const int Col_startX = SCREEN_WIDTH - Col_W;
    const int kc_col = SCREEN_WIDTH/2 + Col_W - delay; 
    int Col_X1 = Col_X + kc_col;
    const int Col_startX1 = Col_X + kc_col;
    int Col_Y = 0;
    int Col_H ;
    int Col_H1;
    const int gap = 200;
    int col_H_duoi = SCREEN_HEIGHT - nen - gap;
//player
int playerX = 70;
const int playerstartX = 70;
int playerY = 250;
const int playerstartY = 250;
const int playerW = 50;
const int playerH = 50;
float playerVelocity = 0;
const float gravity = 0.3f;
const float jumpForce = -8.0f;
bool running = true;
bool again = true ; 
bool xoa = true ;
bool va_amthanh = true;
bool cd1 = true;
bool cd2 = true;
const int startX = 150;
const int startY = 500;
const int startW = 200;
const int startH = 100;

const int restartX = 150;
const int restartY = 500;
const int restartW = 200;
const int restartH = 100;

const int gameoverX = 100;
const int gameoverY = 100;
const int gameoverW = 300;
const int gameoverH = 100;

const int scoreX = SCREEN_WIDTH/2 - 50;
const int scoreY = 50;
const int scoreW = 100;
const int scoreH = 50;

const int scoreMX = SCREEN_WIDTH - 50;
const int scoreMY = 20;
const int scoreMW = 20;
const int scoreMH = 20;

const int Red = 230;
const int Green = 230;
const int Blue = 230;

const int Red1 = 98;
const int Green1 = 200;
const int Blue1 = 223;
const int SCROLL_SPEED = 4;
int backgroundX = 0;
const int backgroundstart = 0;
int backgroundWidth = 0;
int backgroundHeight = 0;

const int k_t_chu = 24;
const Uint8 RedC = 0;
const Uint8 GreenC = 0;
const Uint8 BlueC = 0;
const Uint8 bongC = 0;
// Định nghĩa các biến toàn cục
SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
SDL_Texture* texture = NULL;
SDL_Texture* player1 = NULL;
SDL_Texture* player2 = NULL;
SDL_Texture* player = NULL ;
SDL_Texture* background = NULL;
SDL_Texture* menu = NULL;
SDL_Texture* start = NULL;
SDL_Texture* chuyen_canh = NULL;
SDL_Texture* cotTop = NULL;
SDL_Texture* cotBot = NULL; 
SDL_Texture* gameover = NULL;
SDL_Texture* restart = NULL;
SDL_Event e;

SDL_Rect startRect = {0, 0 ,0 ,0};
SDL_Rect restartRect = {0, 0, 0, 0};

Mix_Chunk* nhay = NULL;
Mix_Chunk* va = NULL;
Mix_Music* nen_nhac = NULL;
Mix_Chunk* congdiem = NULL;

TTF_Font* diemso = NULL;
SDL_Color diemsoColor = {RedC, GreenC, BlueC, bongC};
SDL_Texture* textTexture = NULL;
SDL_Texture* textTexture1 = NULL;