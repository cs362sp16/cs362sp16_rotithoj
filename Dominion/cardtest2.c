#include <stdio.h>
#include <math.h>
#include "dominion.h"
#include <stdlib.h>
#include <assert.h>
int assertTrue(int test){
	if(test)
		printf("TEST SUCCESSFUL\n");
	else
		printf("TEST FAILED\n");
	
}
//test for the outpost card function
int main(){
	int currentPlayer = 1;
	int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;
int randomSeed = 10;
struct gameState * state = malloc(sizeof(struct gameState));

//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
	int handpos = 1;
	outpostfunc(currentPlayer, state, handpos);
	//makes sure that the outpost flag is set by the outpost function
	assertTrue(state -> outpostPlayed == 1);
	return 0;
}
//int main(){
	//testSmithyfunc();
	//return 0;
//}