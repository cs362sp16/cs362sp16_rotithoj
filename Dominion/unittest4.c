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
//test for the getCost function
int main(){
	int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;
int randomSeed = 10;
struct gameState * state = malloc(sizeof(struct gameState));
int cardNumber = treasure_map;
int cardNumber2 = adventurer;
//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
//get the cost and make sure it matches what it should be for that card
int x = getCost(cardNumber);
	assert( x == 4);
int y = getCost(cardNumber2);
assertTrue(y == 6);
	return 0;
}

//int main(){
	//checkWhoseTurn();
	//return 0;
//}