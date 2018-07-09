/**
 * Test of the function gainCard()
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
    int p, r, c;
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G;
    int maxCardNo = 9;
    int prevDeckCount, prevHandCount, prevDiscardCount, prevSupplyCount;

    printf("Testing: gainCard()\n");

    for (p = 0; p < numPlayer; p++) {
        for (c = 0; c <= maxCardNo; c++) {
#ifdef DEBUG_TESTS
            printf("Test player %d with card number %d.\n", p, k[c]);
#endif

            memset(&G, 23, sizeof(struct gameState)); // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

            prevDeckCount = G.deckCount[p];
            prevHandCount = G.handCount[p];
            prevDiscardCount = G.discardCount[p];
            prevSupplyCount = G.supplyCount[k[c]];

            // Add to discard pile
#ifdef DEBUG_TESTS
            printf("Adding card number %d to discard pile.\n", k[c]);
#endif
            gainCard(k[c], &G, 0, p);
#ifdef DEBUG_TESTS
            printf("TEST: G.discardCount = %d, expected = %d\n", G.discardCount[p], prevDiscardCount + 1);
#endif
            assert(G.discardCount[p] == prevDiscardCount + 1); // check if the number of cards in discard pile is correct
#ifdef DEBUG_TESTS
            printf("TEST: G.discard = %d, expected = %d\n", G.discard[p][prevDiscardCount], k[c]);
#endif
            assert(G.discard[p][prevDiscardCount] == k[c]); // check the discard contains the right card
#ifdef DEBUG_TESTS
            printf("TEST: G.supplyCount = %d, expected = %d\n", G.supplyCount[k[c]], prevSupplyCount - 1);
#endif
            assert(G.supplyCount[k[c]] == prevSupplyCount - 1); // check supply count decreses

            // Add to deck
#ifdef DEBUG_TESTS
            printf("Adding card number %d to deck.\n", k[c]);
#endif
            prevSupplyCount = G.supplyCount[k[c]];
            gainCard(k[c], &G, 1, p);
#ifdef DEBUG_TESTS
            printf("TEST: G.deckCount = %d, expected = %d\n", G.deckCount[p], prevDeckCount + 1);
#endif
            assert(G.deckCount[p] == prevDeckCount + 1); // check if the number of cards in deck pile is correct
#ifdef DEBUG_TESTS
            printf("TEST: G.deck = %d, expected = %d\n", G.deck[p][prevDeckCount], k[c]);
#endif
            assert(G.deck[p][prevDeckCount] == k[c]); // check the deck contains the right card
#ifdef DEBUG_TESTS
            printf("TEST: G.supplyCount = %d, expected = %d\n", G.supplyCount[k[c]], prevSupplyCount - 1);
#endif
            assert(G.supplyCount[k[c]] == prevSupplyCount - 1); // check supply count decreses

            // Add to hand
#ifdef DEBUG_TESTS
            printf("Adding card number %d to hand.\n", k[c]);
#endif
            prevSupplyCount = G.supplyCount[k[c]];
            gainCard(k[c], &G, 2, p);
#ifdef DEBUG_TESTS
            printf("TEST: G.handCount = %d, expected = %d\n", G.handCount[p], prevHandCount + 1);
#endif
            assert(G.handCount[p] == prevHandCount + 1); // check if the number of cards in hand pile is correct
#ifdef DEBUG_TESTS
            printf("TEST: G.hand = %d, expected = %d\n", G.hand[p][prevHandCount], k[c]);
#endif
            assert(G.hand[p][prevHandCount] == k[c]); // check the hand contains the right card
#ifdef DEBUG_TESTS
            printf("TEST: G.supplyCount = %d, expected = %d\n", G.supplyCount[k[c]], prevSupplyCount - 1);
#endif
            assert(G.supplyCount[k[c]] == prevSupplyCount - 1); // check supply count decreses

            // No cards left in supply
#ifdef DEBUG_TESTS
            printf("Adding depleated card number %d to discard pile.\n", k[c]);
#endif
            G.supplyCount[k[c]] = 0;
            prevDiscardCount = G.discardCount[p];
            r = gainCard(k[c], &G, 0, p);
#ifdef DEBUG_TESTS
            printf("TEST: Result = %d, expected = %d\n", r, -1);
#endif
            assert(r == -1); // GainCard failed
#ifdef DEBUG_TESTS
            printf("TEST: G.discardCount = %d, expected = %d\n", G.discardCount[p], prevDiscardCount);
#endif
            assert(G.discardCount[p] == prevDiscardCount); // check the discard pile doen't get a card
        }
        // Card is not in game

        memset(&G, 23, sizeof(struct gameState)); // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game without great hall

#ifdef DEBUG_TESTS
        printf("Adding nonexistant card to discard pile.\n");
#endif
        prevDiscardCount = G.discardCount[p];
        r = gainCard(sea_hag, &G, 0, p);
#ifdef DEBUG_TESTS
        printf("TEST: Result = %d, expected = %d\n", r, -1);
#endif
        assert(r == -1); // GainCard failed
#ifdef DEBUG_TESTS
        printf("TEST: G.discardCount = %d, expected = %d\n", G.discardCount[p], prevDiscardCount);
#endif
        assert(G.discardCount[p] == prevDiscardCount); // check the discard pile doen't get a card
    }

    printf("All tests passed!\n");

    return 0;
}