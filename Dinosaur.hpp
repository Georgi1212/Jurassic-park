#ifndef DINOSAUR_HPP
#define DINOSAUR_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include "String.hpp"
#include "Vector.hpp"
#include "Gender.hpp"
#include "KindOfDino.hpp"
#include "Climate.hpp"
#include "Type.hpp"
#include "Food.hpp"
#include "Era.hpp"
#include "DinosaurOtherInfo.hpp"

using namespace std;

class Dinosaur {
	
	private:
		String name;
		Gender gender;
		Era era;
		KindOfDino kind;
		Type type;
		Food food;
		unsigned int cageId;
		
	public:
		Dinosaur ();
		Dinosaur (String _name, Gender _gender, Era _era, KindOfDino _kind, Type _type, Food _food, unsigned int _cageId);
		
		String getName() const;
		Gender getGender() const;
		Era getEra() const;
		KindOfDino getKindOfDino() const;
		Type getType() const;
		Food getFood() const;
		unsigned int getCageId() const;
		
		void setCageId (unsigned int _cageid);
		/*void setName (String _name);
		void setGender (Gender _gender);
		void setEra (Era _era);
		void setKindOfDino (KindOfDino _kind);
		void setType (Type _type);
		void setFood (Food _food);*/
		
		Climate getClimateByKind(KindOfDino kind);
		Food getFoodByKind(KindOfDino kind);
		//bool operator!=(const Dinosaur& other);
		
		void printDinosaur() const;
		
		friend std::ostream& operator<<(std::ostream& out, const Dinosaur& d);		
		friend std::istream& operator>>(std::istream& in, Dinosaur& d);
		
		void serialize(std::ofstream& out) const;
		void deserialize(std::ifstream& in);  	
		//void loadDinosaur(std::ifstream& in);
	
};

#endif
