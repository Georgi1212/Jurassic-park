#include "Cage.hpp"

void Cage::validationAddingDino(Dinosaur& dinosaur)
{
	if(dinosaurs.getSize() >= size)
	{
		cerr << "This cage is full.";
	}
	
	if(era != dinosaur.getEra() && dinosaurs[0].getKindOfDino() != dinosaur.getKindOfDino() && dinosaurs.getSize() > 0)
	{
		cerr << "This dino doesn't match the cage's era and the kind of other dinosaur(s).";
	}	
	return;
}

void Cage::initializeCageForFirstAdding(Dinosaur& dinosaur)
{
	//KindOfDino kind_dinosaur = dinosaur.getKindOfDino();
	
	if (dinosaurs.getSize() == 0)
	{
		Climate newClimate = Dinosaur::getClimateByKind(dinosaur.getKindOfDino()); // ...
		this->climate = newClimate;
		this->era = dinosaur.getEra();
	}
	return;
}

Cage::Cage()
{
	cageId = 0;
	size = 0;
	climate = OTHERCLIMATE; 
	era = OTHERERA;
}

Cage::Cage(unsigned int _cageId, unsigned int _size, Climate _climate, Era _era)
{
	cageId = _cageId;
	size = _size;
	climate = _climate;
	era = _era;
}

void Cage::addDinosaur(Dinosaur& dinosaur)
{
	validationAddingDino(dinosaur);
	initializeCageForFirstAdding(dinosaur);
	dinosaurs.push_back(dinosaur);
	dinosaur.setCageId(this->cageId);
}

void Cage::removeDinosaur(String& name)
{
	int index = 0;
	
	for(unsigned int i = 0; i < this->dinosaurs.getSize(); ++i)
	{
		if(dinosaurs[i].getName() == name)
		{
			index = i;
			break;
		}
		this->dinosaurs.deleteAt(index);
	}
}

void Cage::addFood(Food food, unsigned int quantity)
{
	switch(food)
	{
		case GRASS: foodStorage.addGrass(quantity); break;
		case MEAT: foodStorage.addMeat(quantity); break;
		case FISH: foodStorage.addFish(quantity); break;
		default: cerr << "Unknown food. "; break;
	}
}

void Cage::removeFood(Food food, unsigned int quantity)
{
	switch(food)
	{
		case GRASS: foodStorage.removeGrass(quantity); break;
		case MEAT: foodStorage.removeMeat(quantity); break;
		case FISH: foodStorage.removeFish(quantity); break;
		default: cerr << "Unknown food. "; break;
	}
}

void Cage::setCageId (unsigned int _cageId)
{
	cageId = _cageId;
}
/*
void Cage::setSizeOfCage (unsigned int _size)
{
	size = _size;
}*/

void Cage::setClimate (Climate _climate)
{
	climate = _climate;
}

void Cage::setEra (Era _era)
{
	era = _era;
}

const int Cage::getCageId() const
{
	return this->cageId;
}

const int Cage::getCurrentSizeInCage() const
{
	return this->dinosaurs.getSize();
}

Climate Cage::getClimate() const
{
	return this->climate;
}

Era Cage::getEra() const
{
	return this->era;
}

bool Cage::isThereAnySpaceInCage()
{
	return dinosaurs.getSize() <= size;
}

bool Cage::isThisCageSuitable(Dinosaur& dinosaur)
{
	if(era != dinosaur.getEra() && dinosaurs.getSize() > 0)
	{
		return false;
	}
	
	if(dinosaurs[0].getKindOfDino() != dinosaur.getKindOfDino() && dinosaurs.getSize() > 0)
	{
		return false;
	}
	
	return true;
}

void Cage::printCage() const
{
	cout << "Id: " << cageId << endl;
	cout << "Size: " << size << endl;
	cout << "Climate: ";
		switch(climate)
		{
			case TERRESTRIAL: cout << "Terrestrial" << endl; break;
			case AIR: cout << "Air" << endl; break;
			case WATER: cout << "Water"<< endl ;break;
			default: cerr << "Other climate. "; break; 
		}
		
	cout << "Era: ";
		switch(era)
		{
			case TRIAS: cout << "Trias" << endl; break;
			case CHALK: cout << "Chalk" << endl; break;
			case JURA: cout << "Jura" << endl; break;
			default: cerr << "Other era. "; break;
		}
	
	cout << "Meat Quantity: " << foodStorage.getMeat() << "; Grass Quantity: " << foodStorage.getGrass() << "; Fish Quantity: " << foodStorage.getFish() << endl;
	
	for (unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
		dinosaurs[i].printDinosaur();
	}
}

std::ostream& operator<<(std::ostream& out, const Cage& cg)
{
	out << cg.cageId << " " << cg.size << " ";
	switch(cg.climate)
	{
		case (Climate)0: out << "TERRESTRIAL "; break;
	    case (Climate)1: out << "AIR "; break;
		case (Climate)2: out << "WATER "; break;
		default: out << "OTHER "; break;
	}
	
	switch(cg.era)
	{
		case (Era)0: out << "TRIAS "; break;
	    case (Era)1: out << "CHALK "; break;
		case (Era)2: out << "JURA "; break;
		default: out << "OTHER "; break;
	}
	
	return out;
}

std::istream& operator>>(std::istream& in, Cage& cg)
{
	int cageId;
	int size;
	int temp_climate;
	int temp_era;
	//Climate other_climate;
	//Era other_era;
	
	in >> cg.cageId >> cg.size; //>> other_climate >> other_era;
	//cg.setClimate(other_climate);
	//cg.setEra(other_era);
	
	in >> temp_climate;
	cg.climate = (Climate)temp_climate;
	
	in >> temp_era;
	cg.era = (Era)temp_era;

	return in;
}

void Cage::serialize(std::ofstream& out) const
{
	if (out.is_open())
	{
		out << this->cageId << " ";
		out << this->size << " ";
		out << this->climate << " ";
		out << this->era << " ";
		this->foodStorage.serialize(out);
		out << endl;
	}
	
	else
	{
		cout << "Cannot open the stream!" << endl;
	}
	/*if (!ofs.is_open())
	{
		cout << "The file is still not open!" << endl;
	}
	
	ofs.write((const char*)&id, sizeof(id));
	ofs.write((const char*)&size, sizeof(size));
	ofs.write((const char*)&climate, sizeof(climate));
	ofs.write((const char*)&era, sizeof(era));
	this->foodStorage.serialize(ofs);*/
}

void Cage::deserialize(std::ifstream& in)
{
	if (in.is_open())
	{
		in >> cageId;
		in >> size;
		in >> climate; // enum?
		in >> era; // enum?
		this->foodStorage.deserialize(in);
	}
	/*if (!ifs.is_open())
	{
		cout << "The file is still not open!" << endl;
	}
	
	ifs.read((const char*)&id, sizeof(id));
	ifs.read((const char*)&size, sizeof(size));
	ifs.read((const char*)&climate, sizeof(climate));
	ifs.read((const char*)&era, sizeof(era));
	this->foodStorage.deserialize(ifs);*/
}

void Cage::serializeAllDinosaurs(std::ofstream& out)
{
	for(unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
		dinosaurs[i].serialize(out);
	}
}

void Cage::deserializeAllDinosaurs(std::ifstream& in)
{
	for(unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
		dinosaurs[i].deserialize(in);
	}
}


