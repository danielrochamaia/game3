/**********************************************************************************
// Home (Arquivo de Cabe�alho)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#ifndef _POKEMONRUN_HOME_H_
#define _POKEMONRUN_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite* background = nullptr;       // pano de fundo

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif