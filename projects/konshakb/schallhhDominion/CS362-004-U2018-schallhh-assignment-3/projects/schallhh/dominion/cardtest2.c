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
    int seed = 1000;
//    int maxBonus = 10;
    int bug=0;
    int r, handCount, discard;
   // int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING council card:\n");
#if (NOISY_TEST == 1)
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(2, k, seed, &G); // initialize a new game

                printf("current player hand total:  %d\n", G.handCount[0]);
                handCount=G.handCount[0];
                discard=G.playedCardCount;
                r=cardEffect(council_room, 1, 1, 1, &G, feast, 0);
                if(G.handCount[0]!=handCount+3)
                {
                    printf("Test failed. Hand count = %d. Should = %d\n", G.handCount[0], handCount);
                    bug=1;
                }
                else
                {
                    if(bug==1)
                    {
                        bug=1;
                    }
                    else bug=0;
                    printf("Test passed.  Hand Count = %d\n", handCount+3);
                }
                if(discard+1!=G.playedCardCount)
                {
                    printf("Test failed. Discard count = %d. Should = %d\n", G.playedCardCount, discard+1);
                    bug=1;
                }
                else
                {
                    printf("Test passed.  Discard = %d\n", discard+1);
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
