/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "GeoWars.h"
#include "Start.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    background = new Sprite("Resources/home.png");
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete background;
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // passa ao primeiro nível com ENTER
    if (window->KeyPress(VK_RETURN))
        Start::NextLevel<GeoWars>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------