#include <iostream>
#include <cstring>
#include <fstream>

#include "Vector.hpp"
#include "String.hpp"
#include "KindOfDino.hpp"
#include "Type.hpp"
#include "Gender.hpp"
#include "Food.hpp"
#include "Era.hpp"
#include "Climate.hpp"
#include "Cage.hpp"
#include "CageOtherInfo.hpp"
#include "Dinosaur.hpp"
#include "DinosaurOtherInfo.hpp"
#include "FoodStorage.hpp"

using namespace std;

void AddingCageIdAndSizeOfCage(unsigned int& size, unsigned int& cageId);
void AddingDinosaurInCage(Dinosaur& dinosaur, unsigned int& cageId, unsigned int size, Vector<Cage> cages);


int main ()
{
	//Dinosaur dinosaur;
	String name;
	KindOfDino kind;
	Gender gender;
	Food food;
	Era era;
	Climate climate;
	Type type;
	unsigned int cageId;
	
	Vector<Dinosaur> dinosaurs;
	Vector<Cage> cages;
	Vector<Food> foods;
	
	//Cage cage;
	unsigned int size;
	
	FoodStorage foodStorage;
	unsigned int quantity;
	
	
	cout << "---Welcome to the Dino park!---" << endl;
	cout << "Type help for more information." << endl;
	
	char command[32];
	cout << "Enter command: ";
	cin.getline(command, 31);
	
	
	while (strcmp(command, "exit") != 0)
	{
		if(strcmp(command, "help") == 0)
		{
			cout << "---Information---" << endl;
			cout << "The following commands are supported:" << endl;
			cout << "add dinosaur -> Adding new dinosaur;" << endl;
			cout << "add cage -> Adding cage;" << endl; // 
			cout << "add food -> Adding food to storage;" << endl;
			cout << "remove dinosaur -> Removing dinosaur;" << endl;
			cout << "exit -> Ends the program." << endl;
		}
		
		if (strcmp(command, "add dinosaur") == 0)
		{
			cout << "Enter the name: " << endl;
			cin >> name;
			
			cout << endl;
			
			cout << "Enter the gender: (0-MALE | 1-FEMALE) " << endl;
			cin >> gender;
			
			cout << endl;
			
			cout << "Enter the era: (0-TRIAS | 1-CHALK | 2-JURA) " << endl;
			cin >> era;
			
			cout << endl;
			
			cout << "Enter the kind: (0-CARNIVOROUS | 1-HERBIVOROUS | 2-AQUATIC | 3-FLYING) " << endl;
			cin >> kind; 
			
			cout << endl;
			
			cout << "Enter the type: (0-PLESIOSAURUS | 1-BROTOSAURUS | 2-TYRANNOSAURUS) " << endl;
			cin >> type;
			
			cout << endl;
			
			cout << "Enter the food: (0-GRASS | 1-MEAT | 2-FISH) " << endl;
			cin >> food;
			
			cout << endl;
			
			/*cout << "Enter cageId: " << endl;
			cin >> cageId;*/
			
		 	Dinosaur dinosaur(name, gender, era, kind, type, food, cageId);
		 	
		 	/*cout << "Climate of the dino by it's kind: ";
			dinosaur.getClimateByKind(kind);*/
			
			dinosaurs.push_back(dinosaur);
			
			if(cages.getSize() > 0)
			{
				bool flag = false;
				
				for (unsigned int i = 0; i < cages.getSize(); ++i)
				{
					if(cages[i].isThisCageSuitable(dinosaur) && cages[i].isThereAnySpaceInCage())
					{
						cages[i].addDinosaur(dinosaur);
						cout << "Dinosaur " << dinosaur.getName() << " successfully added." << endl;
						flag = true;
						break;
					}
				}
				
				if (flag == false)
				{
					cout << "There is not enough space! Enter the size of the new cage." << endl;
					
					AddingCageIdAndSizeOfCage(size, cageId);
					AddingDinosaurInCage(dinosaur, cageId, size, cages);
				}
			}
			
			else
			{
				AddingCageIdAndSizeOfCage(size, cageId);
				AddingDinosaurInCage(dinosaur, cageId, size, cages);
			}
			
		}
		
		if(strcmp(command, "add cage") == 0)
		{
			AddingCageIdAndSizeOfCage(size, cageId);
			
			cout << " Enter the climate: (0-TERRESTRIAL | 1-AIR | 2-WATER) ";
			cin >> climate;
			
			cout << " Enter the era: (0-TRIAS | 1-CHALK | 2-JURA)";
			cin >> era;
			
			Cage newcage(cageId, size, climate, era);
			cages.push_back(newcage);
			cout << "Successfull!" << endl;
			
		}
		
		if(strcmp(command, "add food") == 0)
		{
			cout << "Enter quantity of food: ";
			cin >> quantity;
			
			/*cout << "Enter food: (0-GRASS | 1-MEAT | 2-FISH) " << endl;
			cin >> food;*/
			
			for (unsigned int i = 0; i < cages.getSize(); ++i)
			{
				if (cages[i].getClimate() == TERRESTRIAL)
				{
					food = MEAT;
					cages[i].addFood(food, quantity);
				}
				
				if (cages[i].getClimate() == WATER)
				{
					food = FISH;
					cages[i].addFood(food, quantity);
				}
				
				if(cages[i].getClimate() == AIR)
				{
					food = GRASS;
					cages[i].addFood(food, quantity);
				}
			}
			cout << "Now there is food for everyone!" << endl;
		}
		
		if(strcmp(command, "remove dinosaur") == 0)
		{
			cout << "Enter cageId: ";
			cin >> cageId;
			
			cout << "Enter the name of the dino you would like to remove" << endl;
			cin >> name; 
			cages[cageId].removeDinosaur(name);
			
			cout << "Dinosaur " << name << " is successfully removed." << endl;
		}
		
		cout << "Enter command: ";
		cin.getline(command, 31);
		
		if (strcmp(command, "help") != 0 || strcmp(command, "add dinosaur") != 0 || strcmp(command, "add cage") != 0 || 
			strcmp(command, "add food") != 0 || strcmp(command, "remove dinosaur") != 0 || strcmp(command, "exit") != 0)
		{
			cerr << "Invalid command!";
		}
		
	}
	
	ifstream DinosInput("Dinos.txt");
	for (unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
		dinosaurs[i].deserialize(DinosInput);
	}
	
	ifstream CagesInput("Cages.txt");
	for (unsigned int i = 0; i < cages.getSize(); ++i)
	{
		cages[i].deserialize(CagesInput);
	}

	ofstream DinosOutput("Dinos.txt");
	for (unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
    	dinosaurs[i].serialize(DinosOutput);
    }
    
    ofstream CagesOutput("Cages.txt");
    for (unsigned int i = 0; i< cages.getSize(); ++i)
	{
    	cages[i].serialize(CagesOutput);
    }
	
	
	return 0;
}


void AddingCageIdAndSizeOfCage(unsigned int& size, unsigned int& cageId)
{
	cout << "Enter cageId: " << endl;
	cin >> cageId;
	
	cout << "Size of the cage: ";
	cin >> size;
	/*size = CageOtherInfo::randomNumber(3);
	
	switch (size)
	{
		case 1: size = 1; break;
		case 2: size = 3; break;
		case 3: size = 10; break;
		default: size = 1; break;
	}*/
}

void AddingDinosaurInCage(Dinosaur& dinosaur, unsigned int& cageId, unsigned int size, Vector<Cage> cages)
{
	Climate currentClimate = Dinosaur::getClimateByKind(dinosaur.getKindOfDino());
	Cage newCage(cageId, size, currentClimate, dinosaur.getEra());
	cages.push_back(newCage);
	newCage.addDinosaur(dinosaur);
}
