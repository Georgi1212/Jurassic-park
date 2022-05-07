#include "Dinosaur.hpp"


Dinosaur::Dinosaur()
{
	name = "";
	gender = OTHERGENDER;
	era = OTHERERA;
	kind = OTHERKIND;
	type = OTHERTYPE;
	food = OTHERFOOD; 
	cageId = 0;
	
}

Dinosaur::Dinosaur (String _name, Gender _gender, Era _era, KindOfDino _kind, Type _type, Food _food, unsigned int _cageId)
{
	name = _name;
	gender = _gender;
	era = _era;
	kind = _kind;
	type = _type;
	food = _food;
	cageId = _cageId;
}
/*
void Dinosaur::setName (String _name)
{
	name = _name;
}

void Dinosaur::setGender (Gender _gender)
{
	gender = _gender;
}

void Dinosaur::setEra (Era _era)
{
	era = _era;
}
void Dinosaur::setKindOfDino (KindOfDino _kind)
{
	kind = _kind;
}

void Dinosaur::setType (Type _type)
{
	type = _type;
}

void Dinosaur::setFood (Food _food)
{
	food = _food;
}*/

void Dinosaur::setCageId(unsigned int _cageId)
{
	cageId = _cageId;
}


String Dinosaur::getName() const
{
	return this->name;
}

Gender Dinosaur::getGender() const
{
	return this->gender;
}

Era Dinosaur::getEra() const
{
	return this->era;
}

KindOfDino Dinosaur::getKindOfDino() const
{
	return this->kind;
}

Type Dinosaur::getType() const
{
	return this->type;
}

Food Dinosaur::getFood() const
{
	return this->food;
}

unsigned int Dinosaur::getCageId() const
{
	return this->cageId;
}

Climate Dinosaur::getClimateByKind(KindOfDino kind)
{
	switch(kind)
	{
		case CARNIVOROUS: return TERRESTRIAL;
		case HERBIVOROUS: return TERRESTRIAL; 
		case AQUATIC: return WATER; 
		case FLYING: return AIR;
		default: break;
	}
}

Food getFoodByKind(KindOfDino kind)
{
	switch(kind)
	{
		case CARNIVOROUS: return MEAT;
		case HERBIVOROUS: return GRASS; 
		case AQUATIC: return FISH; 
		case FLYING: return GRASS;
		default: break;
	}
}
/*
bool Dinosaur::operator!=(const Dinosaur& other)
{
	return !(*this == other);
}*/

void Dinosaur::printDinosaur() const
{
	cout << "Name: " << name << endl;
	
	cout << "Gender: ";
		switch (gender)
		{
			case MALE: cout << "Male" << endl; break;
			case FEMALE: cout << "Female" << endl; break;
			default: cerr << "Other gender. "; break;
		}
	
	cout << "Era: ";
		switch (era)
		{
			case TRIAS: cout << "Trias" << endl; break;
			case CHALK: cout << "Chalk" << endl; break;
			case JURA: cout << "Jura" << endl; break;
			default: cerr << "Other era. "; break;
		}
		
	cout << "Kind of dinosaur: ";
		switch (kind)
		{
			case CARNIVOROUS: cout << "Carnivorous" << endl; break;
			case HERBIVOROUS: cout << "Herbivorous" << endl; break; 
			case AQUATIC: cout << "Aquatic" << endl; break; 
			case FLYING: cout << "Flying" << endl; break;
			default: cerr << "Other kind. "; break;
		}
		
	cout << "Type: ";
		switch (type)
		{
			case PLESIOSAURUS: cout << "Plesiosaurus" << endl; break;
			case BROTOSAURUS: cout << "Brotosaurus" << endl; break;
			case TYRANNOSAURUS: cout << "Tyrannosaurus" << endl; break;
			default: cerr << "Other type. "; break;
		}
		
	cout << "Food: ";
		switch (food)
		{
			case GRASS: cout << "Grass" << endl; break;
			case MEAT: cout << "Meat" << endl; break; 
			case FISH: cout << "Fish" << endl; break;
			default: cerr << "Other food. "; break;
		}
		
}

std::ostream& operator<<(std::ostream& out, const Dinosaur& d)
{
	out << d.name << " ";
	switch(d.gender)
	{
		case (Gender)0 : out << "MALE "; break;
        case (Gender)1 : out << "FEMALE "; break;
        default: out << "OTHER GENDER ";
	}
	
	switch(d.era)
	{
		case (Era)0: out << "TRIAS "; break;
	    case (Era)1: out << "CHALK "; break;
		case (Era)2: out << "JURA "; break;
		default: out << "OTHER "; break;
	}
	
	switch(d.kind)
    {
        case (KindOfDino)0 : out << "CARNIVOROUS "; break;
        case (KindOfDino)1 : out << "HERBIVOROUS "; break;
        case (KindOfDino)2 : out << "AQUATIC "; break;
        case (KindOfDino)3 : out << "FLYING"; break;
        default: out << "OTHER KIND ";
    }
    
    switch(d.type)
    {
        case (Type)0 : out << "PLESIOSAURUS "; break;
        case (Type)1 : out << "BROTOSAURUS "; break;
        case (Type)2 : out << "TYRANNOSAURUS "; break;
        default: out << "OTHER TYPE ";
    }
    
    switch(d.food)
    {
        case (Food)0 : out << "GRASS "; break;
        case (Food)1 : out << "MEAT "; break;
        case (Food)2 : out << "FISH "; break;
        default: out << "OTHER FOOD ";
    }
	
	out << d.cageId;
	
	return out;
}

std::istream& operator>>(std::istream& in, Dinosaur& d)
{
	String name;
	int cageId;
	int temp_gender;
	int temp_era;
	int temp_kind;
	int temp_type;
	int temp_food;

	in >> d.name;
	
	in >> temp_gender;
	d.gender = (Gender)temp_gender;
	
	in >> temp_era;
	d.era = (Era)temp_era;
	
	in >> temp_kind;
	d.kind = (KindOfDino)temp_kind;
	
	in >> temp_type;
	d.type = (Type)temp_type;
	
	in >> temp_food;
	d.food = (Food)temp_food;
	
	in.ignore();
	
	return in;
}

void Dinosaur::serialize(std::ofstream& out) const
{
	if (out.is_open())
	{
		name.serialize(out);
		out << " ";
		out << gender << " ";
		out << era << " ";
		out << kind << " ";
		out << type << " ";
		out << food << " ";
		out << cageId << " ";
		out << endl;
	}
	else
	{
		cout << "Cannot open stream!" << endl;
	}
	/*if (!ofs.is_open())
	{
		cout << "The file is still not open!";
	}
	name.serialize(ofs);
	ofs.write((const char*)&gender, sizeof(gender));
	ofs.write((const char*)&era, sizeof(era));
	ofs.write((const char*)&kind, sizeof(kind));
	ofs.write((const char*)&type, sizeof(type));
	ofs.write((const char*)&food, sizeof(food));
	ofs.write((const char*)&cageId, sizeof(cageId));*/
}

void Dinosaur::deserialize(std::ifstream& in)
{
	if (in.is_open())
	{
		name.deserialize(in);
		in >> gender; //enum?
		in >> era; //enum?
		in >> kind; //enum?
		in >> type; //enum?
		in >> food; //enum?
		in >> cageId;
	}
	/*if (!ifs.is_open())
	{
		//cout << "The file is still not open!";
		throw "The file is still not open!";
	}
    
	name.deserialize(ifs);
	ifs.read((char*)&gender, sizeof(gender));
	ifs.read((char*)&era, sizeof(era));
	ifs.read((char*)&kind, sizeof(kind));
	ifs.read((char*)&type, sizeof(type));
	ifs.read((char*)&food, sizeof(food));
	ifs.read((char*)&cageId, sizeof(cageId));*/
}  

/*
void Dinosaur::loadDinosaur(std::ifstream& in)
{
	int genderIndex, eraIndex, kindIndex, typeIndex, foodIndex;
	
	cout << "Name: ";
	in >> this->name;

	//DinosaurOtherInfo::GenderInfo();
	cout << "Gender: ";
	in >> genderIndex;
	this->gender = DinosaurOtherInfo::getGenderByIndex(genderIndex);

	//DinosaurOtherInfo::EraInfo();
	cout << "Era: ";
	in >> eraIndex;
	this->era = DinosaurOtherInfo::getEraByIndex(eraIndex);

	//DinosaurOtherInfo::KindOfDinoInfo();
	cout << "Kind: ";
	in >> kindIndex;
	this->kind = DinosaurOtherInfo::getKindOfDinoByIndex(kindIndex);

	//DinosaurOtherInfo::TypeInfo();
	cout << "Type: ";
	in >> typeIndex;
	this->type = DinosaurOtherInfo::getTypeByIndex(typeIndex);

	//DinosaurOtherInfo::FoodInfo();
	cout << "Food: ";
	in >> foodIndex;
	this->food = DinosaurOtherInfo::getFoodByIndex(foodIndex);
	
	in.ignore();
}*/

