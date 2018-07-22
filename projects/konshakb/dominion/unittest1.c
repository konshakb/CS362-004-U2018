
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
/*
   int getCost(int cardNumber)
   {
   switch( cardNumber ) 
   {
   case estate:
   return 2;
   case duchy:
   return 5;
   case province:
   return 8;
   case copper:
   return 0;
   case silver:
   return 3;
   case gold:
   return 6;
   case adventurer:
   return 6;
   case council_room:
   return 5;
   case feast:
   return 4;
   case gardens:
   return 4;
   case mine:
   return 5;
   case remodel:
   return 4;
   case smithy:
   return 4;
   case village:
   return 3;
   case baron:
   return 4;
   case great_hall:
   return 3;
   case minion:
   return 5;
   case steward:
   return 3;
   case tribute:
   return 5;
   case ambassador:
   return 3;
   case cutpurse:
   return 4;
   case embargo: 
   return 2;
   case outpost:
   return 5;
   case salvager:
   return 4;
   case sea_hag:
   return 4;
   case treasure_map:
   return 4;
   }

   return -1;
   }
   */
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int cost=0;
    int bug=0;
    printf("Testing curse\n");
    cost=getCost(0);//curse3
    if(cost==0)
        printf("Passed: curse cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }

    printf("Testing estate\n");
    cost=getCost(1);//estate
    if(cost==2)
        printf("Passed: estate cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(2);//duchy
    if(cost==5)
        printf("Passed: duchy cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(3);//province
    if(cost==8)
        printf("Passed: province cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(4);//copper
    if(cost==0)
        printf("Passed: copper cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(5);//silver
    if(cost==3)
        printf("Passed: silver cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
cost=getCost(6);//gold
    if(cost==6)
        printf("Passed: gold cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(7);//adv
    if(cost==6)
        printf("Passed: adventurer cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(8);//councilroom
    if(cost==5)
        printf("Passed: coucil room cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(9);//feast
    if(cost==4)
        printf("Passed: feast cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(10);//gardens
    if(cost==4)
        printf("Passed: gardens cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(11);//mine
    if(cost==5)
        printf("Passed: mine cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(12);//remodel
    if(cost==4)
        printf("Passed: remodel cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(13);//smithy
    if(cost==4)
        printf("Passed: smithy cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(14);//village
    if(cost==3)
        printf("Passed: village cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(15);//baron
    if(cost==4)
        printf("Passed: baron cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(16);//ghall
    if(cost==3)
        printf("Passed: great_hall cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(17);//minion
    if(cost==5)
        printf("Passed: minion cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(18);//steward
    if(cost==3)
        printf("Passed: steward cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(19);//tribute
    if(cost==5)
        printf("Passed: tribute cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(20);//ambassador
    if(cost==3)
        printf("Passed: ambassador cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(21);//cutpurse
    if(cost==4)
        printf("Passed: cutpurse cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(22);//embargo
    if(cost==2)
        printf("Passed: embargo cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(23);//outpost
    if(cost==5)
        printf("Passed: outpost cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(24);//salvager
    if(cost==4)
        printf("Passed: salvager cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(25);//seahag
    if(cost==4)
        printf("Passed: seahag cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    cost=getCost(26);//map
    if(cost==4)
        printf("Passed: treasure map cost %d\n", cost);
    else
    {
        printf("Test failed\n");
        bug=1;
    }
    if(bug==0)
    {
        printf("All tests passed\n");
    }
    else
    {
        printf("All tests did not pass\n");
    }
    /*
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];//maxhand = 500
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING updateCoins():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {
#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif
                assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif
                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif
                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
            }
        }
    }

    printf("All tests passed!\n");
*/
    return 0;
}
