/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "GeoWars.h"
#include "Tail.h"                    // sistema de partículas
#include <stack>
#include "Green.h"
#include "Start.h"

// -------------------------------------------------------------------------------
//std::vector<Player*> meuVetor;

Player::Player()
{
    // inicializa controle
    gamepad = new Controller();
    gamepadOn = gamepad->Initialize();

    // configuração do objeto
    sprite = new Sprite("Resources/cobra-Sprite-1.png");
    speed  = new Vector(90.0f, 0.0f);
    BBox(new Rect(-25.0f, -25.0f, 25.0f, 25.0f));
    MoveTo(game->CenterX(), game->CenterY());
    type = PLAYER;

    // configuração do gerador de partículas
    Generator emitter;
    emitter.imgFile = "Resources/Spark.png";    // arquivo de imagem
    emitter.angle = 270.0f;                     // ângulo base do emissor
    emitter.spread = 50;                        // espalhamento em graus
    emitter.lifetime = 0.3f;                    // tempo de vida em segundos
    emitter.frequency = 0.010f;                 // tempo entre geração de novas partículas
    emitter.percentToDim = 0.6f;                // desaparece após 60% da vida
    emitter.minSpeed = 50.0f;                   // velocidade mínima das partículas
    emitter.maxSpeed = 100.0f;                  // velocidade máxima das partículas
    emitter.color.r = 1.0f;                     // componente Red da partícula 
    emitter.color.g = 1.0f;                     // componente Green da partícula 
    emitter.color.b = 1.0f;                     // componente Blue da partícula 
    emitter.color.a = 1.0f;                     // transparência da partícula

    // cria sistema de partículas
    tail = new Particles(emitter);
    dir = STOP;
    vel = 3;
}

// -------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
    delete speed;
    delete tail;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector && v)
{
    speed->Add(v);

    // limita velocidade máxima
    if (speed->Magnitude() > 10.0f)
        speed->ScaleTo(10.0f);

}

// -------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    if (type == PLAYER && obj->Type() == GREEN) {
        //Player* ultimoBloco = GeoWars::meuVetor[GeoWars::meuVetor.size() - 1];
        //Player* novoBloco = new Player();

        //switch (ultimoBloco->dir)
        //{
        //case LEFT:
        //    novoBloco->MoveTo(ultimoBloco->X() + ultimoBloco->sprite->Width(), ultimoBloco->Y());
        //    break;
        //case RIGHT:
        //    novoBloco->MoveTo(ultimoBloco->X() - ultimoBloco->sprite->Width(), ultimoBloco->Y());
        //    break;
        //case UP:
        //    novoBloco->MoveTo(ultimoBloco->X(), ultimoBloco->Y() + ultimoBloco->sprite->Width());
        //    break;
        //case DOWN:
        //    novoBloco->MoveTo(ultimoBloco->X(), ultimoBloco->Y() - ultimoBloco->sprite->Width());
        //    break;
        //default:
        //    break;
        //}
        //novoBloco->type = TAIL;
        //novoBloco->dir = ultimoBloco->dir;
        //GeoWars::meuVetor.push_back(novoBloco);
        //GeoWars::scene->Add(novoBloco, STATIC);
        Start::audio->Play(COMER, false);
        Start::pontos += 1;
        vel = vel + 0.8;
        GeoWars::scene->Add(new Green(GeoWars::meuVetor[0]), MOVING);
    }
}

void Player::Update()
{

    if (gamepadOn) {
        gamepad->UpdateState();
    }

    if (window->KeyDown(VK_RIGHT) || gamepad->ButtonDown(2))
        GeoWars::meuVetor[0]->dir = RIGHT;
    else if (window->KeyDown(VK_LEFT) || gamepad->ButtonDown(0))
        GeoWars::meuVetor[0]->dir = LEFT;
    else if (window->KeyDown(VK_UP) || gamepad->ButtonDown(3))
        GeoWars::meuVetor[0]->dir = UP;
    else if (window->KeyDown(VK_DOWN) || gamepad->ButtonDown(1))
        GeoWars::meuVetor[0]->dir = DOWN;

    switch (GeoWars::meuVetor[0]->dir)
    {
    case LEFT:
        GeoWars::meuVetor[0]->MoveTo(GeoWars::meuVetor[0]->x - vel, GeoWars::meuVetor[0]->y);
        break;
    case RIGHT:
        GeoWars::meuVetor[0]->MoveTo(GeoWars::meuVetor[0]->x + vel, GeoWars::meuVetor[0]->y);
        break;
    case UP:
        GeoWars::meuVetor[0]->MoveTo(GeoWars::meuVetor[0]->x, GeoWars::meuVetor[0]->y - vel);
        break;
    case DOWN:
        GeoWars::meuVetor[0]->MoveTo(GeoWars::meuVetor[0]->x, GeoWars::meuVetor[0]->y + vel);
        break;
    default:
        break;
    }


    for (int i = GeoWars::meuVetor.size()-1; i > 0; i--) {
        switch (GeoWars::meuVetor[i-1]->dir)
        {
        case LEFT:
            GeoWars::meuVetor[i]->MoveTo(GeoWars::meuVetor[i-1]->x + sprite->Width(), GeoWars::meuVetor[i - 1]->y);
            break;
        case RIGHT:
            GeoWars::meuVetor[i]->MoveTo(GeoWars::meuVetor[i-1]->x - sprite->Width(), GeoWars::meuVetor[i - 1]->y);
            break;
        case UP:
            GeoWars::meuVetor[i]->MoveTo(GeoWars::meuVetor[i - 1]->x, GeoWars::meuVetor[i - 1]->y + sprite->Width());
            break;
        case DOWN:
            GeoWars::meuVetor[i]->MoveTo(GeoWars::meuVetor[i - 1]->x, GeoWars::meuVetor[i - 1]->y - sprite->Width());
            break;
        default:
            break;
        }
    }


    //// dispara míssil
    //if (window->KeyPress(VK_SPACE))
    //{
    //    GeoWars::audio->Play(FIRE);
    //    GeoWars::scene->Add(new Missile(), STATIC);
    //}

    // atualiza calda do jogador
    tail->Config().angle = speed->Angle() + 180;
    tail->Generate(x - 10 * cos(speed->Radians()), y + 10 * sin(speed->Radians()));
    tail->Update(gameTime);

    //if (x >= window->Width() - 50) MoveTo(50, y);  else if (x < 50) MoveTo(game->Width() - 50, y);
    //if (y >= window->Height() - 50) MoveTo(x, 50); else if (y < 0) MoveTo(x, game->Height() - 50);

    if ((x >= window->Width() - 50) || (x < 50) || (y >= window->Height() - 50) || (y < 0)) {
        Start::gameover = true;
        GeoWars::meuVetor.clear();
    }
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed->Angle() + 90.0f);
    tail->Draw(Layer::LOWER, 1.0f);
}


// -------------------------------------------------------------------------------
