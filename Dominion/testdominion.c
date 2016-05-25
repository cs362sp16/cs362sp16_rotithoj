#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"
#include <assert.h>
#include "rngs.h"
int selectCards(int * kingdomCards){
	srand(time(NULL));

	int i = 0;
	int j = 0;
	  for(i = 0; i < 10; i++){
		  
		  int index = rand() % treasure_map;
		  
		   if(!contains(kingdomCards, index))
		  kingdomCards[i] = index;
	  }
	  return kingdomCards;
	
	
}
int contains(int *hand,int card) 
{
	int i = 0;
	for(i = 0; i < 10; i++) 
	{
		if(hand[i] == card) 
			return 1;
	}
	return 0;
}
void initialDeal(int player, struct gameState * g){
	int i = 0;
	for(i = 0; i < 7; i++)
		g -> hand[player][i] = copper;
	for(i = 8; i < 10; i++)
		g -> hand[player][i] = estate;
	
}
void playGame(int handPos, int choice1, int choice2, int choice3, struct game * g, int supplyPos, int player){
int money = 0;
	int i = 0;
	int j = 0;
	int smithyPos = 0;
	int adventurerPos = 0;
	int numAdventurers = 0;
	int numSmithies = 0;
		shuffle(player,g);
		for(i = 0; i < 5; i++)
		drawCard(player,g);
	while(j < numHandCards(g)){
	if(handCard(j, g) == copper)
		money++;
	else if(handCard(j, g) == silver)
		money+=2;
	else if(handCard(j, g) == gold)
		money+=3;
	else if(handCard(j,g) == smithy)
		smithyPos = j;
	else if(handCard(j,g) == adventurer)
		adventurerPos = j;
	j++;
	}
	if(smithyPos > -1){
	playCard(smithyPos, choice1, choice2, choice3,g);
j = 0;
while(j < numHandCards(g)){
		if(handCard(j, g) == copper){
			playCard(j, choice1, choice2, choice3, g);
		money++;
		}
	else if(handCard(j, g) == silver){
		playCard(j, choice1, choice2, choice3, g);
		money+=2;
	}
	else if(handCard(j, g) == gold){
		playCard(j, choice1, choice2, choice3, g);
		money+=3;
	
      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, g);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, g);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, g);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, g);
      }
	  cardEffect(smithy, choice1, choice2, choice3, g, NULL);
	}
	j++;
}
	}
if(adventurerPos > -1){
	playCard(adventurerPos, choice1, choice2, choice3,g);
j = 0;
while(j < numHandCards(g)){
		if(handCard(j, g) == copper){
			playCard(j, choice1, choice2, choice3, g);
		money++;
		}
	else if(handCard(j, g) == silver){
		playCard(j, choice1, choice2, choice3, g);
		money+=2;
	}
	else if(handCard(j, g) == gold){
		playCard(j, choice1, choice2, choice3, g);
		money+=3;
	
      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, g);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, g);
      }
      else if ((money >= 4) && (numAdventurers < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, g);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, g);
      }
	}
	j++;
}

	for(i = 0; i < 5; i++)
		drawCard(player,g);
	player++;
	if(player >= 2)
		player %= 2;
     endTurn(g);
	
	j++;
		cardEffect(adventurer, choice1, choice2, choice3, g, NULL);
}
}
	
	

int main(int argc, char * argv[]){
	srand(time(NULL));
	struct game * g = newGame();
  int numPlayers = rand() % 2 + 2;
  int playerlist [4] = {1,2,3,4};
int player = rand() % 2;
  	int * kingdomCards = malloc(sizeof(int)* 10);
  kingdomCards = selectCards(kingdomCards);
  int i = 0;
  int index = 0;

int seed = atoi(argv[1]);

initialDeal(player,g);
int x = initializeGame(numPlayers, kingdomCards, seed, g);

int handPos = rand() % treasure_map;
shuffle(player,g);
int choice1 = rand() % treasure_map;
int choice2 = rand() % treasure_map;
int choice3 = rand() % treasure_map;

int supplyPos = rand() % treasure_map;
buyCard(supplyPos,g);
numHandCards(g);
int currentCard = rand() % treasure_map; 
int card = handCard(handPos, g);
int supply = supplyCount(currentCard, g);
int count = fullDeckCount(player, currentCard, g);
int turn = whoseTurn(g);
endTurn(g);
int over = isGameOver(g);
int score = scoreFor(player, g);
for(i = 0; i < 20; i++){
	getCost(kingdomCards[i]);
	cardEffect(kingdomCards[i], choice1, choice2, choice3, g, NULL);

	}

	
	cardEffect(treasure_map, choice1, choice2, choice3, g, NULL);
drawCard(player, g);
int j = rand() % treasure_map;
int cardCost = getCost(kingdomCards[j]);
int * bonus = NULL;
playGame(handPos, choice1, choice2, choice3, g, supplyPos, player);
scoreFor(player,g);
getWinners(playerlist, g);
return 0;
}
