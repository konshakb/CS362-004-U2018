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
#include "math.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
/*
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
   */

int gamefail=0;
int checkAdventure(int p, struct gameState *post)
{
    int r;
    int bonus = 0;
    struct gameState pre;
//    int player=0;
    int prehand=0;
    int bug=0;




    memcpy (&pre, post, sizeof(struct gameState));
//    p= pre.whoseTurn;
   //     printf("current player hand total: %d\n", pre.handCount[p]);//before and after card count
    prehand=pre.handCount[p];

    updateCoins(p, &pre, 0);
      //  printf("current player hand total: %d\n", pre.handCount[p]);
    r = cardEffect(adventurer, 0, 0, 0, &pre, 0, &bonus);
    if(pre.handCount[p]!=prehand+2)
    {
        gamefail++;
        bug=1;
    }
    updateCoins(p, &pre, 0);
    if(pre.coins!=6)
    {
        if(bug!=1)
        {
            gamefail++;//coppers added and should total 6.  Test will fail
            bug=1;
        }
    }

    if(r!=0)
    {
        if(bug!=1)
        {
            printf("Test failed.  Game State is -1\n");
            gamefail++;
            bug=1;
        }
    }

    return 0;
}
int checkDrawCard(int p, struct gameState *post)
{
    int r;
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    r = drawCard (p, post);

    if (pre.deckCount[p] > 0)
    {
        pre.handCount[p]++;
        pre.hand[p][pre.handCount[p]-1]=pre.deck[p][pre.deckCount[p]-1];
        pre.deckCount[p]--;
    }
    else if (pre.discardCount[p] > 0) 
    {
        memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
        memcpy(pre.discard[p], post->discard[p], sizeof(int) * pre.discardCount[p]);
        pre.hand[p][post->handCount[p]-1]=post->hand[p][post->handCount[p]-1];
        pre.handCount[p]++;
        pre.deckCount[p]=pre.discardCount[p]-1;
        pre.discardCount[p]=0;
    }




    assert (r==0);
    assert(memcmp(&pre, post, sizeof(struct gameState))==0);
    return 0;
}
int main() {
    int i, n, p, numTreasures;
 //   int k[10] = {adventurer, council_room, feast, gardens, mine
    //    , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING AdventureCard. \n");
    printf("RANDOM TESTS. \n");
    SelectStream(2);
    PutSeed(3);
    int min = 3;
    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {//initialize random tests
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * MAX_PLAYERS);
        G.deckCount[p]=floor(Random() * MAX_DECK+1);
        if(G.deckCount[p]<3)
            G.deckCount[p]=3;
        numTreasures = floor(Random() * ((G.deckCount[p] - min) + 1) + min);
        for (i = 0; i < numTreasures; i++) {
            G.deck[p][i] = copper;//fill numtreasures with copper
        }
        G.discardCount[p] = 0;//0 discard amount
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.whoseTurn = p;
        checkAdventure(p, &G);//run checkadventure
    }
    printf("Test failed %d times\n", gamefail);
    return 0;
}





