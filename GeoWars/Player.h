/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#ifndef _GEOWARS_PLAYER_H_
#define _GEOWARS_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                        // objetos do jogo
#include "Sprite.h"                        // desenho de sprites
#include "Vector.h"                        // representa��o de vetores
#include "Particles.h"                    // sistema de part�culas
#include "Controller.h"                 // entrada pelo controle

// ---------------------------------------------------------------------------------
enum eDirection { STOP, LEFT, RIGHT, UP, DOWN };
class Player : public Object
{
private:

    Particles * tail;                   // calda do jogador

    Controller* gamepad;               // leitura do controle
    bool gamepadOn;                     // controle est� ligado

public:
    Vector * speed;                     // velocidade e dire��o
    Sprite* sprite;                    // sprite do objeto
    eDirection dir;
    float vel;

    Player();                           // construtor
    ~Player();                          // destrutor
    
    void Move(Vector && v);             // movimenta jogador
    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

#endif