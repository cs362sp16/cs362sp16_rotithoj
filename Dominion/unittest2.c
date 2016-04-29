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
//test for the numHandCards function
int main(){
int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;
int randomSeed = 10;
struct gameState * state = malloc(sizeof(struct gameState));
//add a card to the hand of the current player
state -> handCount[whoseTurn(state)] = 1;
//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
//get the number of cards in the hand and make sure it is correct in this case
int x = numHandCards(state);	
assertTrue(x == 1);	
free(state);
return 0;
}
//int main(){
	//checkNumHandCards();
	//return 0;
		
	
	
//}