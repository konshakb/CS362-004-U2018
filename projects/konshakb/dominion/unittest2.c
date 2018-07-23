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
    int i;
    int numPlayer=2;
    int seed = 1000;
    int r;
    int bug=0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds
    //    printf("%d is max hand\n", MAX_HAND);
    //  printf("%d copper\n", copper);
    // printf("%d curse\n", curse);
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    printf("Is game over test:\n");
    for(i=0; i < 25; i++)
    {
        printf("supply card total: %d\n", G.supplyCount[i]);
    }
    for(i=0; i < 3; i++)
    {
        G.supplyCount[i]=0;//empty 3 supply cards
    }
    printf("%d province\n", province);
    r=isGameOver(&G);
    if(r==1)
    {
        printf("Test passed.  r = %d because there are three empty supply piles\n", r);
        bug=0;
    }
    else
    {
        printf("Test failed.  Game did not end with 3 empty supply piles\n");
        bug=1;
    }


    for(i=0; i < 3; i++)
    {
        G.supplyCount[i]=1;//reset supply
    }
    r=isGameOver(&G);
    printf("result %d\n", r);
    G.supplyCount[province]=0;
    r=isGameOver(&G);
    if(r==1)
    {
        printf("Test passed.  r = %d because there are no province cards left\n", r);
        bug=0;
    }
    else
    {
        printf("Test failed.  Game did not end with no province cards left\n");
        bug=1;
    }
    G.supplyCount[3]=1;//reset province
    for(i=0; i < 25; i++)
    {
        if(i != 3)
        {
            G.supplyCount[i]=0;
            r=isGameOver(&G);
            if(r==1)
                break;
            G.supplyCount[i]=1;
        }
    }
    if(r==1)
    {
        printf("Test failed.  r = %d Game ended based on a card not province being 0\n", r);
        bug=1;
    }
    else
    {
        printf("Test passed.  Cards not province did not cause game to end\n");
        bug=0;
    }
                if(bug==1)
                    printf("All tests did not pass.\n");
                else
                    printf("All tests passed!\n");





    /* 
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
