#include "toancuc.h"
#include "cacham.h"
#include "code.h"

void nhap_du_lieu(){
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = createRenderer(window);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer Error: %s\n", Mix_GetError());
        exit(1);
    }
    if (TTF_Init() == -1) {
        SDL_Log("Không thể khởi tạo SDL_ttf: %s", TTF_GetError());
        exit(1);
    }
    diemso = TTF_OpenFont("C:/Users/User/Desktop/game1/src/chu/Washington.ttf", 24);
    nhay = Mix_LoadWAV("C:/Users/User/Desktop/game1/src/amthanh/nhay.wav");
    va   = Mix_LoadWAV("C:/Users/User/Desktop/game1/src/amthanh/va.wav");
    congdiem = Mix_LoadWAV("C:/Users/User/Desktop/game1/src/amthanh/congdiem.wav");
    nen_nhac = Mix_LoadMUS("C:/Users/User/Desktop/game1/src/amthanh/nen.mp3");
    background = loadTexture("C:/Users/User/Desktop/game1/src/image/backround1.png", renderer);
    SDL_QueryTexture(background, NULL, NULL, &backgroundWidth, &backgroundHeight);
    menu = loadTexture("C:/Users/User/Desktop/game1/src/image/22.png", renderer);
    start = loadTexture("C:/Users/User/Desktop/game1/src/image/start.png", renderer);

    cotTop = loadTexture("C:/Users/User/Desktop/game1/src/image/cot12.jpg", renderer);
    cotBot = loadTexture("C:/Users/User/Desktop/game1/src/image/cot123.jpg", renderer);
    hinh_anh_player("C:/Users/User/Desktop/game1/src/image/player1.png" , &player1 , Red, Green, Blue);
    hinh_anh_player("C:/Users/User/Desktop/game1/src/image/player2.png" , &player2 , Red, Green, Blue);

    hinh_anh_player("C:/Users/User/Desktop/game1/src/image/gameover.png", &gameover, Red1, Green1, Blue1 );
    restart = loadTexture("C:/Users/User/Desktop/game1/src/image/restart.png", renderer);
    scoreMax = loadHighestScore();
    player = player1;
    startRect = {startX , startY, startW, startH };
    restartRect = {restartX, restartY, restartW, restartH};
    chuyen_canh = menu;
    return;
}
void chuongtrinh(){
    srand(std::time(0));
    //Điều khiển
    
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                if (chuot(mouseX, mouseY, startRect)) {
                    if (chuyen_canh == menu) {
                        chuyen_canh = background;
                        Col_H = Min + rand() % Max/2;
                        Col_H1 = Min + rand() % Max/2;
                        Mix_PlayMusic(nen_nhac, -1);
                    }
                }
                if (chuot(mouseX, mouseY, restartRect) && xoa) {
                    again = true;
                    reset(&playerX, &playerY, &Col_X, &Col_X1, &backgroundX);
                    xoa = false;
                    va_amthanh = true;
                    Col_H = Min + rand() % Max/2;
                    Col_H1 = Min + rand() % Max/2;
                    Mix_PlayMusic(nen_nhac, -1);
                    if(score > scoreMax) scoreMax = score;
                    score = 0 ;
                }
                if (again && chuyen_canh == background) {
                    playerVelocity = jumpForce;
                    Mix_PlayChannel(-1, nhay, 0);
                }
            } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                if (chuyen_canh == menu) {
                    chuyen_canh = background;
                    Col_H = Min + rand() % Max/2;
                    Col_H1 = Min + rand() % Max/2;
                    Mix_PlayMusic(nen_nhac, -1);
                }
                if (again)
                    playerVelocity = jumpForce;
                    if(va_amthanh)
                    Mix_PlayChannel(-1, nhay, 0);
            }
        }
        if (vacham(&playerX, &playerY, &Col_X, &Col_H, &Col_X1, &Col_H1)) {
            if(va_amthanh){
                Mix_PlayChannel(-1, va, 0);
            }
            va_amthanh = false;
            again = false;
            xoa = true;
            Mix_HaltMusic();
            if (score > scoreMax) {
                scoreMax = score;
                saveHighestScore(scoreMax); // Save the new highest score to the file
            }
        }
        if(playerX + playerW >= Col_X && playerX <= Col_X + Col_W){
            if(!vacham(&playerX, &playerY, &Col_X, &Col_H, &Col_X1, &Col_H1) && cd1 )
                score++;
                if(cd1){Mix_PlayChannel(-1, congdiem, 0);}
                cd1 = false;
        }else cd1 = true;
        if(playerX + playerW >= Col_X1 && playerX <= Col_X1 + Col_W){
            if(!vacham(&playerX, &playerY, &Col_X, &Col_H, &Col_X1, &Col_H1) && cd2)
                score++;
                if(cd2){Mix_PlayChannel(-1, congdiem, 0);}
                cd2 = false;
        }else cd2 = true;
        SDL_RenderClear(renderer);
        if (chuyen_canh == menu) {
            hien_menu( menu, start, startRect);
        }
        if (chuyen_canh == background) {
            if (!again) {
                background_dung(renderer, background, backgroundWidth, &backgroundX);
                cot_dung(renderer, cotTop, cotBot, &Col_X, &Col_H, &Col_H1, &Col_X1, col_H_duoi, gap);
                player_in(renderer, player, playerX, playerY, playerW, playerH);
                hien_gameover(renderer, gameover, restart, restartRect);
                hien_diemso(score, textTexture , scoreX, scoreY, scoreW, scoreH);
                hien_diemso(scoreMax, textTexture1, scoreMX, scoreMY, scoreMW, scoreMH);
            } else {
                hanh_dong(&playerVelocity, gravity, &playerY, playerH, SCREEN_HEIGHT);
                hoat_anh(playerVelocity, &player, player1, player2);
                renderScrollingBackground(renderer, background, backgroundWidth, &backgroundX);
                player_in(renderer, player, playerX, playerY, playerW, playerH);
                cot_troi(renderer, cotTop, cotBot, &Col_X, &Col_H, &Col_H1, &Col_X1, col_H_duoi, gap);
                hien_diemso(score, textTexture, scoreX, scoreY, scoreW, scoreH);
                hien_diemso(scoreMax, textTexture1, scoreMX, scoreMY, scoreMW, scoreMH);
                SDL_Delay(delay);
            }
        }
        SDL_RenderPresent(renderer);
    }
    
    void exit();
}