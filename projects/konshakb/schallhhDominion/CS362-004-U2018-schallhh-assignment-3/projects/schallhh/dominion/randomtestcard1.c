/*tration of how to write unit tests for dominion-base
 *      */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "math.h"


int testfailed;
int testpassed;
int checksmithy(int p, struct gameState *post)
{
    int bug=0;
    int r;
    int bonus = 0;
    int handCount;
    int postCount;
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    handCount=pre.handCount[p];

    r = cardEffect(smithy, 0, 0, 0, &pre, 0, &bonus);
    postCount=pre.handCount[p];
    printf("pre.handCount after %d handcount before %d\n", postCount, handCount+3);
    if(postCount != (handCount+3))
    {
        //    printf("pre.handCount after %d handcount before %d\n", postCount, handCount+3);

        testfailed++;//
        bug=1;
    }
    if(r!=0)
    {
        if(bug==0)
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
    int i, n, p, numTreasures, total;
  //  int k[10] = {adventurer, council_room, feast, gardens, mine
    //    , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING SmithyCard. \n");
    printf("RANDOM TESTS. \n");
    SelectStream(2);
    PutSeed(3);
    total=2000;
    int min = 4;
    for (n = 0; n < total; n++) 
    {
        for (i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        //random values
        p = floor(Random() * MAX_PLAYERS);
        G.deckCount[p]=floor(Random() * MAX_DECK);
       if(G.deckCount[p]<4)
            G.deckCount[p]=4;

        numTreasures = floor(Random() * ((G.deckCount[p] - min) + 1) + min);

        for (i = 0; i < numTreasures; i++) 
        {
            //            G.deck[player][i] = treasures[i];
        }
        G.discardCount[p] = 0;
        G.handCount[p] = floor(Random() * ((MAX_HAND+1)));
        G.whoseTurn = p;
        checksmithy(p, &G);//call function

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
    printf("Tests ran  %d times\n", total);
    printf("Tests failed %d times\n", testfailed);
    printf("Tests passed %d times\n", testpassed);
    return 0;
}





