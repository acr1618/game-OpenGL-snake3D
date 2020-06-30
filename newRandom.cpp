#include "newRandom.h"
#include <stdlib.h>
#include <time.h>

newRandom::newRandom() {   //construtor
}

int newRandom::cenario() {

		srand((unsigned)time(NULL));     /*random de int*/
		sorteio1 = 1 + rand() % 2;
		return sorteio1;

}

float newRandom::RandomBetween()
	{

		sorteio2 = (((float)rand() / RAND_MAX) * diff) + 1.0;  /*random de float*/
		return sorteio2;

}


