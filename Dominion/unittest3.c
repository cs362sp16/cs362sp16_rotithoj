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
//test for the fullDeckCount function
int main(){
	int player = 1;
	int card = smithy;
	int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;
int randomSeed = 10;
struct gameState * state = malloc(sizeof(struct gameState));
state -> deck[player][1] == card;
//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
//make sure that the full deck count is accurate
	assertTrue(fullDeckCount(player, card, state) ==  0);
	return 0;
}

//int main(){
	//checkFullDeckCount();
	//return 0;
	
//}