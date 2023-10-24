/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
//
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "GameOver.h"
#include "GeoWars.h"
#include "Home.h"
#include "Start.h"

// ----------------------------------------------------------------------

void GameOver::Init()
{
    title = new Sprite("Resources/gameover2.png");
}

// ----------------------------------------------------------------------

void GameOver::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN)) {
        //Home::audio->Stop(OVER);
        //GravityGuy::NextLevel<Home>();
        Start::NextLevel<Start>();
    }
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
    title->Draw(window->CenterX(), window->CenterY()+10, Layer::BACK, 1);
    Start::hud->Draw(window->CenterX(), window->CenterY());
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete title;
}

// ----------------------------------------------------------------------

