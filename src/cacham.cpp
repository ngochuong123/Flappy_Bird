#include"toancuc.h"
#include"cacham.h"

void logErrorAndExit(const char* msg, const char* error) {
    printf("%s %s\n", msg, error);
    exit(1);
}

SDL_Window* initSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const char* WINDOW_TITLE) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        logErrorAndExit("SDL could not initialize! SDL_Error:", SDL_GetError());
    }
    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow(
        WINDOW_TITLE,                      
        SDL_WINDOWPOS_UNDEFINED,    
        SDL_WINDOWPOS_UNDEFINED,    
        SCREEN_WIDTH,                     
        SCREEN_HEIGHT,                     
        SDL_WINDOW_SHOWN            
    );
    if (window == NULL) {
        logErrorAndExit("Window could not be created! SDL_Error:", SDL_GetError());
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        logErrorAndExit("SDL_image could not initialize! SDL_image Error:", IMG_GetError());
    }
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    return renderer;
}
//xu ly hinh anh
SDL_Texture *loadTexture(const char *filename,SDL_Renderer*renderer)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    SDL_Texture*texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
    }
    return texture;    
}
// backround trôi
void renderScrollingBackground(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int backgroundWidth, int* backgroundX) {
    *backgroundX -= SCROLL_SPEED;
    if (*backgroundX < -backgroundWidth) {
        *backgroundX = 0; 
    }
    background_dung( renderer, backgroundTexture, backgroundWidth, backgroundX);
}
void background_dung(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int backgroundWidth, int* backgroundX){
    SDL_Rect destRect1 = {*backgroundX, 0, backgroundWidth, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &destRect1);
    SDL_Rect destRect2 = {*backgroundX + backgroundWidth, 0, backgroundWidth, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &destRect2);
}


void hinh_anh_player(const char* filename , SDL_Texture**player1,int Red, int Green, int Blue){
    SDL_Surface* surface = IMG_Load(filename);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, Red, Green, Blue)); 
    *player1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}
void player_in(SDL_Renderer* renderer, SDL_Texture* player, int playerX, int playerY, const int playerW, const int playerH){
    SDL_Rect playerRect = {playerX, playerY, playerW, playerH};
        SDL_RenderCopy(renderer, player, NULL, &playerRect);
}
bool chuot (int mouseX, int mouseY, SDL_Rect Start){
    return (mouseX >= Start.x && mouseX <= Start.x + Start.w &&
            mouseY >= Start.y && mouseY <= Start.y + Start.h);
}

void cot_troi(SDL_Renderer* renderer, SDL_Texture* cotTop, SDL_Texture* cotBot, int* Col_X, int* Col_H, int* Col_H1, int* Col_X1, int col_H_duoi, int gap) {
    *Col_X -= SCROLL_SPEED;
    *Col_X1 -= SCROLL_SPEED;
    if (*Col_X <= -Col_W && *Col_X1 <= SCREEN_WIDTH - kc_col - Col_W ) {
        *Col_X = SCREEN_WIDTH ; 
        *Col_H = Min + rand() % Max;    
        while (col_H_duoi - *Col_H <= 0) {
            *Col_H = Min + rand() % Max;
        }
    }
    if (*Col_X1 <= -Col_W && *Col_X <= SCREEN_WIDTH - kc_col - Col_W) {
        *Col_X1 = SCREEN_WIDTH ;
        *Col_H1 = Min + rand() % Max;
        while (col_H_duoi - *Col_H1 <= 0) {
            *Col_H1 = Min + rand() % Max;
        }
    }
    cot_dung( renderer,  cotTop, cotBot, Col_X, Col_H, Col_H1, Col_X1, col_H_duoi, gap);
}
void cot_dung(SDL_Renderer* renderer, SDL_Texture* cotTop, SDL_Texture* cotBot, int* Col_X, int* Col_H, int* Col_H1, int* Col_X1, int col_H_duoi, int gap){
    SDL_Rect cotRectTop = { *Col_X, 0, Col_W, *Col_H };
    SDL_Point xoay = {Col_W / 2, *Col_H / 2};
    SDL_RenderCopyEx(renderer, cotTop, NULL, &cotRectTop, 180, &xoay , SDL_FLIP_NONE);
    // SDL_RenderCopy(renderer, cotTop, NULL, &cotRectTop);
    SDL_Rect cotRectBot = { *Col_X, gap + *Col_H, Col_W, col_H_duoi - *Col_H };
    SDL_RenderCopy(renderer, cotBot, NULL, &cotRectBot);

    SDL_Rect cotRectTop1 = { *Col_X1, 0, Col_W, *Col_H1 };
    SDL_Point xoay1 = {Col_W / 2, *Col_H1 / 2};
    SDL_RenderCopyEx(renderer, cotTop, NULL, &cotRectTop1, 180, &xoay1 , SDL_FLIP_NONE);
    // SDL_RenderCopy(renderer, cotTop, NULL, &cotRectTop1);
    SDL_Rect cotRectBot1 = { *Col_X1, gap + *Col_H1, Col_W, col_H_duoi - *Col_H1 };
    SDL_RenderCopy(renderer, cotBot, NULL, &cotRectBot1);
}
bool vacham(int *playerX, int*playerY, int*Col_X, int*Col_H, int*Col_X1, int*Col_H1){
    if(*playerY + playerH >= SCREEN_HEIGHT - nen) return true;
    if(*playerX + playerW >= *Col_X && *playerX <= *Col_X +  Col_W){
        if(*playerY <= *Col_H || *playerY + playerH >= gap + *Col_H ) return true;
    }
    if(*playerX + playerW >= *Col_X1 && *playerX <= *Col_X1 +  Col_W){
        if(*playerY <= *Col_H1  || *playerY + playerH >= gap + *Col_H1 ) return true;
    }
    return false ;
}

void reset(int* playerX, int* playerY, int* Col_X, int*Col_X1, int*backgroundX){
    *playerX = playerstartX;
    *playerY = playerstartY;
    *Col_X   = Col_startX;
    *Col_X1  = Col_startX1;
    *backgroundX = backgroundstart;
}

void hoat_anh(int vantoc, SDL_Texture**p, SDL_Texture*p1, SDL_Texture*p2){
    if (vantoc < 0) {
        *p = p2; 
    } else if (vantoc > 0) {
        *p = p1; 
    }
}
void hanh_dong(float* playerVelocity, float gravity, int* playerY, const int playerH, const int SCREEN_HEIGHT){
    *playerVelocity += gravity; 
    *playerY += *playerVelocity; 
    if (*playerY < 0) {
        *playerY = 0;
    }
    if (*playerY + playerH > SCREEN_HEIGHT) {
        *playerY = SCREEN_HEIGHT - playerH;
    }
}
void hien_menu (SDL_Texture* menu, SDL_Texture* start, SDL_Rect startRect){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer ,menu ,NULL ,NULL);
    SDL_RenderCopy(renderer ,start ,NULL ,&startRect);
    SDL_RenderPresent(renderer);
}
void hien_gameover(SDL_Renderer* renderer ,SDL_Texture*gameover, SDL_Texture*restart, SDL_Rect restartRect){
    SDL_Rect gameoverRect = {gameoverX, gameoverY, gameoverW, gameoverH};
    SDL_RenderCopy(renderer ,gameover ,NULL ,&gameoverRect);
    SDL_RenderCopy(renderer ,restart ,NULL , &restartRect);
}

void hien_diemso(int score, SDL_Texture* textTexture, int scoreX, int scoreY, int scoreW, int scoreH){
    string diem = to_string(score);
    SDL_Surface* textSurface = TTF_RenderText_Solid(diemso, diem.c_str(), diemsoColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect textRect = {scoreX, scoreY, scoreW, scoreH}; 
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}
int loadHighestScore() {
    ifstream file("highest_score.txt");
    int highestScore = 0;
    if (file.is_open()) {
        file >> highestScore;
        file.close();
    }
    return highestScore;
}
void saveHighestScore(int score) {
    ofstream file("highest_score.txt");
    if (file.is_open()) {
        file << score;
        file.close();
    }
}
void hien_settings(SDL_Renderer* renderer, SDL_Texture* settingsTexture, SDL_Rect settingsRect, SDL_Rect volumeUpRect, SDL_Rect volumeDownRect) {
    SDL_RenderCopy(renderer, settingsTexture, NULL, &settingsRect);
    SDL_RenderCopy(renderer, settingsTexture, NULL, &volumeUpRect);
    SDL_RenderCopy(renderer, settingsTexture, NULL, &volumeDownRect);
}
void exit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(menu);
    SDL_DestroyTexture(start);
    SDL_DestroyTexture(player1);
    SDL_DestroyTexture(player2);
    SDL_DestroyTexture(player);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(cotTop);
    SDL_DestroyTexture(cotBot);
    SDL_DestroyTexture(gameover);
    SDL_DestroyTexture(restart);
    SDL_DestroyTexture(textTexture);
    Mix_FreeChunk(nhay);
    Mix_FreeChunk(va);
    Mix_FreeMusic(nen_nhac);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


    