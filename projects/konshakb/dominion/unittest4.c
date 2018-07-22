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
    int r;
    int bug=0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING gaincard():\n");
#if (NOISY_TEST == 1)
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(2, k, seed, &G); // initialize a new game
                r=G.supplyCount[adventurer];
                printf("Adventurer totals %d\n", r);
                r =gainCard(sea_hag, &G, 1, 1);
                if(r==-1)
                {
                    printf("Passed: sea hag not found\n");
                    bug=0;
                }
                else
                {
                    printf("Test failed sea hag not in deck but return 0\n");
                    bug=1;
                }
                printf("Player 1 deck count = %d\n", G.deckCount[1]);
                printf("Player 1 hand count = %d\n", G.handCount[1]);
                printf("Player 1 discard count = %d\n", G.discardCount[1]);
                r =gainCard(adventurer, &G, 1, 1);
                r=G.supplyCount[adventurer];
                printf("Adventurer totals %d\n", r);
                printf("Player 1 deck count = %d\n", G.deckCount[1]);
                printf("Player 1 hand count = %d\n", G.handCount[1]);
                printf("Player 1 discard count = %d\n", G.discardCount[1]);
                printf("Adventurer found 0 %d \n", r);
                r =gainCard(adventurer, &G, 2, 1);
                r=G.supplyCount[adventurer];
                printf("Adventurer totals %d\n", r);
                printf("Player 1 deck count = %d\n", G.deckCount[1]);
                printf("Player 1 hand count = %d\n", G.handCount[1]);
                printf("Player 1 discard count = %d\n", G.discardCount[1]);
                r =gainCard(adventurer, &G, 0, 1);
                r=G.supplyCount[adventurer];
                printf("Adventurer totals %d\n", r);
                printf("Player 1 deck count = %d\n", G.deckCount[1]);
                printf("Player 1 hand count = %d\n", G.handCount[1]);
                printf("Player 1 discard count = %d\n", G.discardCount[1]);
                G.supplyCount[adventurer]=0;
                r =gainCard(adventurer, &G, 0, 1);
                printf("No more adventure should be -1 %d\n", r);
                if(bug==0)
                printf("All tests passed\n");

                

}
