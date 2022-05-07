#ifndef CAGE_HPP
#define CAGE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include "Vector.hpp"
#include "Climate.hpp" //
#include "Food.hpp"
#include "Era.hpp"
#include "KindOfDino.hpp"
#include "Dinosaur.hpp"
#include "CageOtherInfo.hpp"
#include "FoodStorage.hpp"

using namespace std;

class Cage 
{
	private:
		unsigned int cageId;
		unsigned int size;
		Climate climate;
		Era era;
		Vector<Dinosaur> dinosaurs;
		FoodStorage foodStorage;
		
		void validationAddingDino(Dinosaur& dinosaur);
		void initializeCageForFirstAdding(Dinosaur& dinosaur);
		
	public:
		Cage();
		Cage(unsigned int _cageId, unsigned int _size, Climate _climate, Era _era);
		
		void addDinosaur(Dinosaur& dinosaur);
		void removeDinosaur(String& name);

		void addFood(Food food, unsigned int quantity);
		void removeFood(Food food, unsigned int quantity);
		
		void setCageId (unsigned int _cageId);
		//void setSizeOfCage (unsigned int _size);
		void setClimate (Climate _climate);
		void setEra (Era _era);
		
		const int getCageId() const;
		const int getCurrentSizeInCage() const;
		Climate getClimate() const;
		Era getEra() const;
		
		bool isThereAnySpaceInCage();
		bool isThisCageSuitable(Dinosaur& dinosaur);
		
		void printCage() const;
		
		friend std::ostream& operator<<(std::ostream& out, const Cage& cg);		
		friend std::istream& operator>>(std::istream& in, Cage& cg);
		
		void serialize(std::ofstream& out) const;
		void deserialize(std::ifstream& in);
		void serializeAllDinosaurs(std::ofstream& out);
		void deserializeAllDinosaurs(std::ifstream& in);
};

#endif


