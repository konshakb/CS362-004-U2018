/**
 * Test of the function isGameOver()
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int seed = 1000;
    int numPlayer = 2;

    int p, a, c, f;
    int maxProvince, maxAdventurer, maxCouncil, maxFeast;
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G;

    printf("Testing: isGameOver()\n");

    memset(&G, 23, sizeof(struct gameState)); // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    maxProvince = G.supplyCount[province];
    maxAdventurer = G.supplyCount[adventurer];
    maxCouncil = G.supplyCount[council_room];
    maxFeast = G.supplyCount[feast];

    for (p = 0; p < maxProvince; p++) {
        for (a = 0; a <= maxAdventurer; a++) {
            for (c = 0; c <= maxCouncil; c++) {
                for (f = 0; f <= maxFeast; f++) {

#ifdef DEBUG_TESTS
                    printf("Pile count:\n - Province: %d\n - Adventure: %d\n - Council Room: %d\n - Feast: %d\n - All Others: MAX\n", p, a, c, f);
#endif

                    G.supplyCount[province] = p;
                    G.supplyCount[adventurer] = a;
                    G.supplyCount[council_room] = c;
                    G.supplyCount[feast] = f;

                    if (p == 0) {
#ifdef DEBUG_TESTS
                        printf("TEST: isGameOver() = %d, expected = %d\n", isGameOver(&G), 1);
#endif
                        assert(isGameOver(&G) == 1);
                    } else if (a == 0 && c == 0 && f == 0) {
#ifdef DEBUG_TESTS
                        printf("TEST: isGameOver() = %d, expected = %d\n", isGameOver(&G), 1);
#endif
                        assert(isGameOver(&G) == 1);
                    } else {
#ifdef DEBUG_TESTS
                        printf("TEST: isGameOver() = %d, expected = %d\n", isGameOver(&G), 0);
#endif
                        assert(isGameOver(&G) == 0);
                    }
                }
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}