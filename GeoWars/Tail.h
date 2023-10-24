/**********************************************************************************
// Green (Arquivo de Cabeçalho)
//
// Criação:     15 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#ifndef _GEOWARS_TAIL_H_
#define _GEOWARS_TAIL_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"
#include "Tail.h"

// ---------------------------------------------------------------------------------

class Tail : public Object
{
private:
    Sprite* sprite;                    // sprite do objeto
    Vector* speed;                     // velocidade e direção
    Player* player;                    // ponteiro para jogador
    Tail* tail;                    // ponteiro para jogador
    int distance;                       // mantém distância do jogador
    bool isHead;
    eDirection dirTail;

public:
    Tail(Player* p);
    ~Tail();                           // destrutor

    void OnCollision(Object* obj);      // resolução da colisão
    void Update();                      // atualização
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------

inline void Tail::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif