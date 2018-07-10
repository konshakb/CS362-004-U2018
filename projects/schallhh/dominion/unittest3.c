/**
 * Test of the function scoreFor()
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>

typedef struct testcase testcase;

int testsPassed = 1;

void testAssert(int test, char* msg)
{
    if (!test) {
        printf("TEST FAILED: %s\n", msg);
        testsPassed = 0;
    } else {
#ifdef DEBUG_TEST
        printf("TEST PASSED: %s\n", msg);
#endif
    }
}

int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G;
    int g, h, i;

    int curses[MAX_HAND];
    int estates[MAX_HAND];
    int duchys[MAX_HAND];
    int provinces[MAX_HAND];
    int great_halls[MAX_HAND];
    int gardenses[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        curses[i] = curse;
        estates[i] = estate;
        duchys[i] = duchy;
        provinces[i] = province;
        great_halls[i] = great_hall;
        gardenses[i] = gardens;
    }

    printf("Testing: scoreFor()\n");

    for (h = 0; h <= MAX_HAND; h += 25) {
        for (g = 0; g <= MAX_HAND - h; g += 25) {

            memset(&G, 23, sizeof(struct gameState));
            initializeGame(numPlayer, k, seed, &G);

            // Test hand
            G.handCount[0] = h + g;
            G.discardCount[0] = 0;
            G.deckCount[0] = 0;
            memcpy(G.hand[0] + (sizeof(int) * h), gardenses, sizeof(int) * g);

            memcpy(G.hand[0], curses, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * -1 + g * ((h + g) / 10), "Curses in hand");

            memcpy(G.hand[0], estates, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 1 + g * ((h + g) / 10), "Estates in hand");

            memcpy(G.hand[0], great_halls, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 1 + g * ((h + g) / 10), "Great Halls in hand");

            memcpy(G.hand[0], duchys, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 3 + g * ((h + g) / 10), "Duchys in hand");

            memcpy(G.hand[0], provinces, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 6 + g * ((h + g) / 10), "Provinces in hand");

            // Test discard
            G.handCount[0] = 0;
            G.discardCount[0] = h + g;
            memcpy(G.discard[0] + (sizeof(int) * h), gardenses, sizeof(int) * g);

            memcpy(G.discard[0], curses, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * -1 + g * ((h + g) / 10), "Curses in discard");

            memcpy(G.discard[0], estates, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 1 + g * ((h + g) / 10), "Estates in discard");

            memcpy(G.discard[0], great_halls, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 1 + g * ((h + g) / 10), "Great Halls in discard");

            memcpy(G.discard[0], duchys, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 3 + g * ((h + g) / 10), "Duchys in discard");

            memcpy(G.discard[0], provinces, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 6 + g * ((h + g) / 10), "Provinces in discard");

            // Test deck
            G.discardCount[0] = 0;
            G.deckCount[0] = h + g;
            memcpy(G.deck[0] + (sizeof(int) * h), gardenses, sizeof(int) * g);

            memcpy(G.deck[0], curses, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * -1 + g * ((h + g) / 10), "Curses in deck");

            memcpy(G.deck[0], estates, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 1 + g * ((h + g) / 10), "Estates in deck");

            memcpy(G.deck[0], great_halls, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 1 + g * ((h + g) / 10), "Great Halls in deck");

            memcpy(G.deck[0], duchys, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 3 + g * ((h + g) / 10), "Duchys in deck");

            memcpy(G.deck[0], provinces, sizeof(int) * h);
            testAssert(scoreFor(0, &G) == h * 6 + g * ((h + g) / 10), "Provinces in deck");
        }
    }

    printf("%s\n", testsPassed ? "All tests passed" : "1 or more tests failed");
    return 0;
}