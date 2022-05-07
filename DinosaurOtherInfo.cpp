#include "DinosaurOtherInfo.hpp"

void DinosaurOtherInfo::ClimateInfo()
{
	cout << "0: Terrestrial " << endl;
	cout << "1: Air " << endl;
	cout << "2: Water " << endl;
	cout << endl;
}

void DinosaurOtherInfo::FoodInfo()
{
	cout << "0: Grass " << endl;
	cout << "1: Meat " << endl;
	cout << "2: Fish " << endl;
	cout << endl;
}

void DinosaurOtherInfo::GenderInfo()
{
	cout << "0: Male " << endl;
	cout << "1: Female " << endl;
	cout << endl;	
}

void DinosaurOtherInfo::KindOfDinoInfo()
{
	cout << "0: Carnivorous " << endl;
	cout << "1: Herbivorous " << endl;
	cout << "2: Aquatic " << endl;
	cout << "3: Flying " << endl;
	cout << endl;
	
}

void DinosaurOtherInfo::EraInfo()
{
	cout << "0: Trias " << endl;
	cout << "1: Chalk " << endl;
	cout << "2: Jura " << endl;
	cout << endl;
}

void DinosaurOtherInfo::TypeInfo()
{
	cout << "0: Plesiosaurus " << endl;
	cout << "1: Brotosaurus " << endl;
	cout << "2: Tyrannosaurus " << endl;
	cout << endl;
}

Climate DinosaurOtherInfo::getClimateByIndex(int& index)
{
	switch(index)
	{
		case 0: return TERRESTRIAL;
		case 1: return AIR; 
		case 2: return WATER; 
		default: cerr << "Other climate. "; 
	}
}

Food DinosaurOtherInfo::getFoodByIndex(int& index)
{
	switch (index)
	{
		case 0: return GRASS; 
		case 1: return MEAT; 
		case 2: return FISH;
		default: cerr << "Other food. "; 
	}
}

Gender DinosaurOtherInfo::getGenderByIndex(int& index)
{
	switch (index)
	{
		case 0: return MALE; 
		case 1: return FEMALE; 
		default: cerr << "Other gender. "; 
	}
}

KindOfDino DinosaurOtherInfo::getKindOfDinoByIndex(int& index)
{
	switch (index)
	{
		case 0: return CARNIVOROUS; 
		case 1: return HERBIVOROUS; 
		case 2: return AQUATIC; 
		case 3: return FLYING; 
		default: cerr << "Other kind. ";
	}
}

Era DinosaurOtherInfo::getEraByIndex(int& index)
{
	switch (index)
	{
		case 0: return TRIAS; 
		case 1: return CHALK; 
		case 2: return JURA; 
		default: cerr << "Other era. ";  
	}
}

Type DinosaurOtherInfo::getTypeByIndex(int& index)
{
	switch (index)
	{
		case 0: return PLESIOSAURUS; 
		case 1: return BROTOSAURUS; 
		case 2: return TYRANNOSAURUS; 
		default: cerr << "Other type. ";   
	}
}
