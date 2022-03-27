// Standard headers
#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //time()

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
    UNUSED(attacker_spy);
    UNUSED(defender_position);
    static bool calledSRand = false;
    if (!calledSRand) {
        //Iremos chamar srand() apenas uma vez em nossa estratégia
        time_t timeSeed;
        srand((unsigned)time(&timeSeed));
        calledSRand = true;
    }
    //O defensor irá mover-se aleatoriamente para cima ou para baixo
    direction_t moveDir = ((rand() & 1) == 0 ? (direction_t)DIR_UP : (direction_t)DIR_DOWN);
    return moveDir;
}

/*----------------------------------------------------------------------------*/
