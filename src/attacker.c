// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

//Verifica se duas dire��es s�o iguais
bool equal_directions(direction_t d1, direction_t d2) {
    return d1.i == d2.i && d1.j == d2.j;
}

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
    UNUSED(defender_spy);
    static position_t prevPos = INVALID_POSITION; //�ltima posi��o do atacante
    static direction_t nextDetour = DIR_UP; //Pr�xima dire��o a tomar ao bater numa barreira por tentar ir para a direita
    static direction_t prevDir = DIR_STAY; //�ltima dire��o escolhida pelo atacante
    direction_t moveDir = DIR_RIGHT;
    if (equal_positions(attacker_position, prevPos)) {
        //Batemos em uma barreira
        if (equal_directions(prevDir, nextDetour)) {
            /*Al�m disso, batemos por tentar desviar de uma barreira.
            Vamos alternar a dire��o de desvio entre ir para cima ou para baixo*/
            if (equal_directions(prevDir, (direction_t)DIR_UP)) {
                moveDir = nextDetour = (direction_t)DIR_DOWN;
            }
            else {
                moveDir = nextDetour = (direction_t)DIR_UP;
            }
        }
        else {
            //Tentaremos simplesmente desviar da barreira
            moveDir = nextDetour;
        }
    }
    prevPos = attacker_position;
    prevDir = moveDir;
    return moveDir;
}

/*----------------------------------------------------------------------------*/
