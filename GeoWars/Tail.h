/**********************************************************************************
// Green (Arquivo de Cabe�alho)
//
// Cria��o:     15 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma fuga suavizada
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
    Vector* speed;                     // velocidade e dire��o
    Player* player;                    // ponteiro para jogador
    Tail* tail;                    // ponteiro para jogador
    int distance;                       // mant�m dist�ncia do jogador
    bool isHead;
    eDirection dirTail;

public:
    Tail(Player* p);
    ~Tail();                           // destrutor

    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------

inline void Tail::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif