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
    int actions;
    int bug=0;
    int r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING village card:\n");
#if (NOISY_TEST == 1)
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(2, k, seed, &G); // initialize a new game

                handCount=G.handCount[0];
                actions=G.numActions;
                r=cardEffect(village, 1, 1, 1, &G, 4, 0);
                if(G.handCount[0]!=handCount)//discard bug in code
                {
                    printf("Test failed. Hand count = %d. Should = %d\n", G.handCount[0], handCount);
                    bug=1;
                }
                else
                {
                    printf("Test passed.  handCount = %d\n", handCount);
                    bug=0;
                }
                if(actions+2!=G.numActions)//discard bug in code
                {
                    printf("Test failed. Actions = %d. Should = %d\n", G.numActions, actions+2);
                    bug=1;
                }
                else
                {
                    printf("Test passed.  Actions = %d\n", actions+2);
                }
                if(r!=0)
                {
                    printf("Test failed.  Game state is -1\n");
                    bug=1;
                }
                else
                {
                    printf("Passed game state\n");
                }
                if(bug==1)
                    printf("All tests did not pass.\n");
                else
                    printf("All tests passed!\n");
                

                

}
