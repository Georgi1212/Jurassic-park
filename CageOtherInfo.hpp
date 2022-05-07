#ifndef CAGEOTHERINFO_HPP
#define CAGEOTHERINFO_HPP

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Climate.hpp"
#include "KindOfDino.hpp"

using namespace std;

struct CageOtherInfo 
{
	//Climate getClimateByKind(KindOfDino kind);
	int randomNumber(int maxNumber);
	
};

/*Climate CageOtherInfo::getClimateByKind(KindOfDino kind)
{
	switch(kind)
	{
		case CARNIVOROUS: return TERRESTRIAL;
		case HERBIVOROUS: return TERRESTRIAL; 
		case AQUATIC: return WATER; 
		case FLYING: return AIR;
		default: break;
	}
}*/

int CageOtherInfo::randomNumber(int maxNumber)
{
	srand(time(NULL));
	int number = rand() % maxNumber + 1;
	return number;
}


#endif
