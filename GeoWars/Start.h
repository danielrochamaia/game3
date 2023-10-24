/**********************************************************************************
// GravityGuy (Arquivo de Cabe�alho)
//
// Cria��o:     05 Out 2011
// Atualiza��o: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _START_H_
#define _START_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Player.h"
#include "Resources.h"
#include "Audio.h"
#include "Hud.h"


// ------------------------------------------------------------------------------
enum Sounds { MUSIC1, COMER };
class Start : public Game
{
private:
    static Game* level;            // n�vel atual do jogo

public:
    static Hud* hud;
    static float pontos;
    static Audio* audio;
    static bool gameover;
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif