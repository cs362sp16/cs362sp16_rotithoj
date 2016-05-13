#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"
#include <assert.h>
int assertTrue(int test){
	if(test)
		printf("TEST SUCCESSFUL\n");
	else
		printf("TEST FAILED\n");
	
}
int main(int argc, char * argv[]){
	srand(time(NULL));
	int numPlayers = rand() % 50;
	int currentPlayer = rand() % 50;
	int handPos = rand() % 50;
	int randomSeed = argv[1];
	int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, council_room};
		struct gameState *state = malloc(sizeof(struct gameState));
	initializeGame(numPlayers, kingdomCards, randomSeed, state);
	int x = state -> numActions + 1;
	int y = hallfunc(currentPlayer, state, handPos);
	assertTrue(state -> numActions == x);
	assertTrue(state -> handCount[state -> whoseTurn] == 1);
	return 0;
}
//test great hall