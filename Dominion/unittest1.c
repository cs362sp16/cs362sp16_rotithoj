#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include <assert.h>
int assertTrue(int test){
	if(test)
		printf("TEST SUCCESSFUL\n");
	else
		printf("TEST FAILED\n");
	
}
//test for the isGameOver function
int main(){
int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;
int randomSeed = 10;
struct gameState * state = malloc(sizeof(struct gameState));
//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
//there are no cards in the pile, so the game should be over
int x = isGameOver(state);	
assertTrue(x == 1);	
free(state);
return 0;
}

//int main(){
	//checkGameOver();
	//return 0;
	
//}

