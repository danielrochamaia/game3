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

#ifndef _GEOWARS_GREEN_H_
#define _GEOWARS_GREEN_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"
#include "Animation.h"  

// ---------------------------------------------------------------------------------

class Green : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Vector * speed;                     // velocidade e direção
    Player * player;                    // ponteiro para jogador
    int distance;                       // mantém distância do jogador
    TileSet* tileset;                // folha de sprites do personagem
    //TileSet   * player1TileSet;                // folha de sprites do personagem
    Animation* anim;                   // animação do personagem
    
public:
    Green(Player * p);                  // construtor
    ~Green();                           // destrutor
    
    void OnCollision(Object* obj);      // resolução da colisão
    void Update();                      // atualização
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------


#endif