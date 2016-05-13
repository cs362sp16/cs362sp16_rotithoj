CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
	
unittest1: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS)
	
unittest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS)
	
unittest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS)
	
cardtest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	
cardtest2: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	
cardtest3: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS)
	
cardtest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard1: dominion.o randomtestcard1.c
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard2: dominion.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard1.out: randomtestcard1 playdom
	./randomtestcard1 42 >> randomtestcard1.out
	echo "GCOV FOR COUNCIL ROOM CARD" >> randomtestcard1.out
	gcov -f -b dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2 playdom
	./randomtestcard2 42 >> randomtestcard2.out
	echo "GCOV FOR GREAT HALL CARD" >> randomtestcard2.out
	gcov -f -b dominion.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer playdom
	./randomtestadventurer 42 >> randomtestadventurer.out
	echo "GCOV FOR ADVENTURER CARD" >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out
	
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o  $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)
	
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	./unittest1 >> unittestresults.out
	echo "GCOV AFTER UNITTEST1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	
	./unittest2 >> unittestresults.out
	echo "GCOV AFTER UNITTEST2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	
	./unittest3 >> unittestresults.out
	echo "GCOV AFTER UNITTEST3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	echo "GCOV AFTER UNITTEST4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out

	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER CARDTEST1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out

	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER CARDTEST2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER CARDTEST3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER CARDTEST4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#./playdom 3 >> unittestresults.out
	#echo "RESULTS AFTER A GAME" >> unittestresults.out
	#gcov dominion.c >> unittestresults.out	
	
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o  $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2  player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
