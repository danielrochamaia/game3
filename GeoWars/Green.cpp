/**********************************************************************************
// Green (C�digo Fonte)
// 
// Cria��o:     15 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#include "Green.h"
#include "GeoWars.h"
#include "Random.h" 
#include "Tail.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------

Green::Green(Player * p): player(p)
{
    tileset = new TileSet("Resources/apple.png",9,8,1,2);
    anim = new Animation(tileset, 0.120f, true);
    uint seq[2] = { 0, 1 };
    anim->Add(200, seq, 2);

    sprite = new Sprite("Resources/apple.png");
    speed  = new Vector(0, 2.0f);
    BBox(new Circle(20.0f));

    // mant�m certa dist�ncia do jogador
    RandI dist{ 300, 400 };
    distance = dist.Rand();

    // nasce em uma posi��o aleat�ria (canto inferior direito)
    RandF posX{ 0, window->Width() };
    RandF posY{ 0, window->Height() };
    MoveTo(posX.Rand(), posY.Rand());

    type = GREEN;
}

// ---------------------------------------------------------------------------------

Green::~Green()
{
    delete anim;
    delete tileset;
    delete sprite;
    delete speed;
}

// -------------------------------------------------------------------------------

void Green::OnCollision(Object * obj)
{
    //if (obj->Type() == MISSILE)
    //    GeoWars::scene->Delete(this, MOVING);

    if (obj->Type() == PLAYER) {
        GeoWars::scene->Delete(this, MOVING);
    }
}

// -------------------------------------------------------------------------------

void Green::Update()
{
    anim->Select(200);
    anim->NextFrame();
    // a magnitude do vetor target controla qu�o 
    // r�pido o objeto converge para a dire��o do alvo
    float angle = Line::Angle(Point(x, y), Point(player->X(), player->Y()));
    float magnitude = 10.0f * gameTime;
    Vector target = Vector(angle, magnitude);
    
    // fugir se o player chegar muito perto
    if (Point::Distance(Point(x, y), Point(player->X(), player->Y())) < distance)
    {
        target.Rotate(180.0f);
        target.ScaleTo(20.0f * gameTime);
    }

    // ajusta velocidade atual na dire��o do alvo
    speed->Add(target);
    
    // limita a magnitude da velocidade para impedir 
    // seu crescimento indefinido na soma vetorial
    if (speed->Magnitude() > 3)
        speed->ScaleTo(3.0f);


    // move o objeto pelo seu vetor velocidade
    Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);
    Rotate(50 * gameTime);

    // mant�m o objeto dentro do mundo do jogo
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);
}

void Green::Draw()
{
    anim->Draw(x, y, Layer::MIDDLE, 5.0f, 0);
}

// -------------------------------------------------------------------------------