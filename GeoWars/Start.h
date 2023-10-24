/**********************************************************************************
// GravityGuy (Arquivo de Cabeçalho)
//
// Criação:     05 Out 2011
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
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
    static Game* level;            // nível atual do jogo

public:
    static Hud* hud;
    static float pontos;
    static Audio* audio;
    static bool gameover;
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
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