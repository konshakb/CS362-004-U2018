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
    int i=0;
    int j=0;
    int r=0;
    int testing=1000;
    int bug=0;
    compare(&i, &testing);
    //int results=0;

//    printf("%d and %d", i, testing);
    for (i=0;i<testing;i++)
    {
       // printf("%d and %d", i, testing);
        r=compare(&i, &testing);
        if(r==-1)
        {
            //    printf("Passed:  Result should be -1  %d\n", r);
        }
        else
            bug=1;
    }
    for (i=2000;i>testing;i--)
    {
     //   printf("%d and %d", i, testing);
        r=compare(&i, &testing);
        if(r==1)
        {
            // printf("Passed: Result should be 1  %d\n", r);
        }
        else bug=1;
    }
    for (i=0;i<testing;i++)
    {
        j=i;
//        printf("%d and %d", i, testing);
        r=compare(&i, &j);
        if(r==0)
        {
            // printf("Passed:  Result should be 0  %d\n", r);
        }
        else bug=1;
    }
    if (bug==0)
        printf("All tests passed\n");
    else
        printf("Compare function failed\n");
    /*    
          r=0;
          int numPlayer=2;
          int seed = 1000;
          int k[10] = {adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall};
          struct gameState G;
    // arrays of all coppers, silvers, and golds
    //    printf("%d is max hand\n", MAX_HAND);
    //  printf("%d copper\n", copper);
    // printf("%d curse\n", curse);
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    printf("Supply cards:\n");
    for(i=0; i < 25; i++)
    {
    printf("supply card total: %d\n", G.supplyCount[i]);
    }
    for(i=0; i < 3; i++)
    {
    G.supplyCount[i]=0;
    }
    printf("%d province\n", province);
    r=isGameOver(&G);
    printf("result %d\n", r);
    for(i=0; i < 3; i++)
    {
    G.supplyCount[i]=1;
    }
    printf("%d province\n", province);
    r=isGameOver(&G);
    printf("result %d\n", r);
    G.supplyCount[3]=0;
    r=isGameOver(&G);
    printf("result %d\n", r);
    G.supplyCount[3]=1;
    for(i=0; i < 25; i++)
    {
    if(i != 3)
    {
    G.supplyCount[i]=0;
    r=isGameOver(&G);
    printf("result %d\n", r);
    if(r==1)
    break;
    G.supplyCount[i]=1;
    }
    }





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
