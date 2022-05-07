#include "FoodStorage.hpp"

FoodStorage::FoodStorage()
{
	grassQuantity = 0;
	meatQuantity = 0;
	fishQuantity = 0;
}

unsigned int FoodStorage::getGrass() const
{
	return this->grassQuantity;
}

unsigned int FoodStorage::getMeat() const
{
	return this->meatQuantity;
}

unsigned int FoodStorage::getFish() const
{
	return this->fishQuantity;
}

void FoodStorage::addGrass(unsigned int& quantity)
{
	grassQuantity += quantity;
}

void FoodStorage::addMeat(unsigned int& quantity)
{
	meatQuantity += quantity;
}

void FoodStorage::addFish(unsigned int& quantity)
{
	fishQuantity += quantity;
}

void FoodStorage::removeGrass(unsigned int& quantity)
{
	if (grassQuantity - quantity < 0)
	{
		cout << "Cannot remove grass."; //(throw exception)
	}
	
	grassQuantity -= quantity;
}

void FoodStorage::removeMeat(unsigned int& quantity)
{
	if (meatQuantity - quantity < 0)
	{
		cout << "Cannot remove meat."; //(throw exception)
	}
	meatQuantity -= quantity;
}

void FoodStorage::removeFish(unsigned int& quantity)
{
	if (fishQuantity - quantity < 0)
	{
		cout << "Cannot remove fish."; //(throw exception)
	}
	fishQuantity -= quantity;
}

/*
std::istream& operator>>(std::istream& in, FoodStorage& fst)
{
	unsigned int grassQuantity;
	unsigned int meatQuantity;
	unsigned int fishQuantity;
	
	in >> fst.grassQuantity >> fst.meatQuantity >> fst.fishQuantity;
	
	return in;
}*/

void FoodStorage::serialize(std::ofstream& out) const
{
	if(out.is_open())
	{
		out << grassQuantity << " ";
		out << meatQuantity << " ";
		out << fishQuantity << " ";
	}
	
	else
	{
		cout << "Cannot open stream!" << endl;
	}
	//out.write((const char*)&grassQuantity, sizeof(grassQuantity));
	//out.write((const char*)&meatQuantity, sizeof(meatQuantity));
	//out.write((const char*)&fishQuantity, sizeof(fishQuantity));
}

void FoodStorage::deserialize(std::ifstream& in)
{
	
	in >> grassQuantity;
	in >> meatQuantity;
	in >> fishQuantity;
	
	//in.read((char*)&grassQuantity, sizeof(grassQuantity));
	//in.read((char*)&meatQuantity, sizeof(meatQuantity));
	//in.read((char*)&fishQuantity, sizeof(fishQuantity));
}

	
