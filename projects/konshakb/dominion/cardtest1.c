/*tration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *  *
 *   * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *    *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 *     * -----------------------------------------------------------------------
 *      */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
//    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int bug=0;
    int r;
   // int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
  //  int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
   // int coppers[MAX_HAND];

    printf ("TESTING adventure card:\n");
#if (NOISY_TEST == 1)
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

                printf("current player hand total:  %d\n", G.handCount[0]);
                maxBonus=G.handCount[0];
                updateCoins(0, &G, 0);
                r=cardEffect(adventurer, 1, 1, 1, &G, 4, 0);
                if(G.handCount[0]!=maxBonus+2)
                {
                    printf("Test failed. Hand count = %d. Should = %d\n", G.handCount[0], maxBonus+2);
                    bug=1;
                }
                
                updateCoins(0, &G, 0);
                if(G.coins!=6)
                {
                    printf("Test failed. Coins should = 6.  Coins = %d\n", G.coins);
                    bug=1;
                }
                else
                {
                    printf("Test Passed.  Coins = 6\n");
                }
                if(r!=0)
                {
                    printf("Test failed.  Game state is -1\n");
                    bug=1;
                }
                if(bug==1)
                    printf("All tests did not pass.\n");
                else
                    printf("All tests passed!\n");


                

}
