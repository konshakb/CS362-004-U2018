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

int testfailed=0;
int testpassed=0;
int checkAdventure(int p, struct gameState *post)
{
    int r;
    int bonus = 0;
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    r = cardEffect(adventurer, 0, 0, 0, &pre, 0, &bonus);
    return 0;
}
int checksmithy(int p, struct gameState *post)
{
    int r;
    int bonus = 0;
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    r = cardEffect(smithy, 0, 0, 0, &pre, 0, &bonus);
    return 0;
}
int checkcouncil(int p, struct gameState *post)
{
    int bug=0;
    int handCount, discard;
    int r;
    int bonus = 0;
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    handCount=pre.handCount[p];
    discard=pre.playedCardCount;
    r = cardEffect(council_room, 0, 0, 0, &pre, feast, &bonus);
    if(pre.handCount[p]!=handCount+3)//check handCount+3 (4-discard
    {
        testfailed++;
        bug=1;
    }
    if(discard+1!=pre.playedCardCount)//check discard of player
    {
        if(bug!=1)
        {
            testfailed++;
            bug=1;
        }



    }
    if(r!=0)
    {
        if(bug!=1)
        {
            testfailed++;
            bug=1;
        }
    }
    if(bug==0)
        testpassed++;
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
    int i, n, p, deckCount, discardCount, handCount, numTreasures, total;
  //  int k[10] = {adventurer, council_room, feast, gardens, mine
       //kk , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING Council Card. \n");
    total=2000;
    printf("RANDOM TESTS. \n");
    SelectStream(2);
    PutSeed(3);
    int min = 3;
    for (n = 0; n < total; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        deckCount=floor(Random() * MAX_DECK+1);//randomize deck hand discard
        handCount=floor(Random() * MAX_HAND+1);
        discardCount=floor(Random() * MAX_HAND+1);
        G.numPlayers=3;
        p = G.numPlayers-2;
        G.numBuys=1;
        G.playedCardCount = floor(Random() * (MAX_DECK-1));
        for (i=0; i<G.numPlayers; i++)
        {
            G.deckCount[i]=deckCount;//fill all the player's cards
            G.handCount[i]=handCount;
            G.discardCount[i]=discardCount;
        }

        G.whoseTurn = p;

        checkcouncil(p, &G);//call check council

    }
#if (NOISY_TEST == 1)
#endif
    /*
       for (n=0; n < 2000; n++)
       {
       for (i=0; i< sizeof(struct gameState); i++)
       {
       ((char*)&G)[i] = floor(Random() * 256);
       }
       p = floor(Random() * 2);
    //        printf("p: %d\n", p);
    G.deckCount[p]=floor(Random() * MAX_DECK);
    if (G.deckCount[p]<3)
    G.deckCount[p]==3;
    G.discardCount[p]=floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    G.whoseTurn = p;
    numTreasures = floor(Random() * (G.deckCount[p]));
    for (i=0; i < numTreasures; i++)
    {
    G.deck[p][i] = treasures[rand() % 3];
    }

    checkAdventure(p, &G);
    //     checkDrawCard(p, &G);*/
    //}
    printf("All Tests OK\n");
    printf("Tests ran  %d times\n", total);
    printf("Tests failed %d times\n", testfailed);
    printf("Tests passed %d times\n", testpassed);
    return 0;
}





