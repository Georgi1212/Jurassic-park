#ifndef FOODSTORAGE_HPP
#define FOODSTORAGE_HPP

#include <iostream>
#include <fstream>

using namespace std;

class FoodStorage 
{
	private:
		unsigned int grassQuantity;
		unsigned int meatQuantity;
		unsigned int fishQuantity;
		
	public:
		FoodStorage();
		
		unsigned int getGrass() const;
		unsigned int getMeat() const;
		unsigned int getFish() const;

		void addGrass(unsigned int& quantity);
		void addMeat(unsigned int& quantity);
		void addFish(unsigned int& quantity);
		
		void removeGrass(unsigned int& quantity);
		void removeMeat(unsigned int& quantity);
		void removeFish(unsigned int& quantity);
		
		//friend istream& operator>>(istream& in, FoodStorage& fst); 

		void serialize(std::ofstream& out) const;
		void deserialize(std::ifstream& in);
};

#endif
