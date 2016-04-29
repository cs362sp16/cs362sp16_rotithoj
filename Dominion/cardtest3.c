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
//test for the Gardens card, contained inside the cardEffect function
int main(){
int choice1 = 0;
int choice2 = 0;
int choice3 = 0;	
int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;
int randomSeed = 10;
int card = gardens;
struct gameState * state = malloc(sizeof(struct gameState));
//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
int handPos = 0;
int * bonus = NULL;
//go into cardEffect and pass in gardens as a parameter so that the code associated with it can be executed
int x = cardEffect(card, choice1, choice2, choice3, state, handPos, bonus);
assertTrue(x == -1);	
return 0;
}
//int main(){
	//testGardens();
	//return 0;
//}