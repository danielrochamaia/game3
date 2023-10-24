#include "Engine.h"
#include "Resources.h"
#include "Home.h"
#include "Start.h"
#include "Audio.h"
#include "Hud.h"
#include "GameOver.h"

// inicializa membros estáticos da classe
Game* Start::level = nullptr;
Audio* Start::audio = nullptr;
Hud* Start::hud = nullptr;
float Start::pontos = 0.0f;
bool Start::gameover = false;

void Start::Init()
{
    audio = new Audio();
    audio->Add(MUSIC1, "Resources/music1.wav");
    audio->Add(COMER, "Resources/comer.wav");

    //// bounding box não visível
    //viewBBox = false;

    //// cria jogador
    //twoPlayers = false;
    //player1 = new Player("Resources/bat-flow-2.png");
    //player2 = new Player("Resources/robin-flow-2.png");
    //redBall = new Image("Resources/bola-g.png");
    //hud = new Hud();
    // 
    // inicializa nível de abertura do jogo
    hud = new Hud();
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void Start::Update()
{
    if (gameover)
    {
        NextLevel<GameOver>();
        gameover = false;
    }

    //if (hud->Time() == 0) {
    //    gameover = true;
    //}

    //// habilita/desabilita visualização da bounding box
    //if (window->KeyPress('B'))
    //    viewBBox = !viewBBox;

    // atualiza nível
    level->Update();
    hud->Update();
    //hud->Update();
}

// ------------------------------------------------------------------------------

void Start::Draw()
{
    // desenha nível
    level->Draw();
}

// ------------------------------------------------------------------------------

void Start::Finalize()
{
    level->Finalize();
    delete level;
    //delete Home::audio;
    //delete redBall;
}
// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor do jogo
    Engine* engine = new Engine();

    // configura motor
    //engine->window->Mode(WINDOWED);
    engine->window->Size(1920, 1080);
    engine->window->Mode(BORDERLESS);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Snake Game");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(true);
    //engine->graphics->VSync(true);

    // cria o jogo
    Game* game = new Start();

    // configura o jogo
    //game->Size(1920, 1080);

    // inicia execução
    int status = engine->Start(game);

    // destrói motor e encerra jogo
    delete engine;
    return status;
}