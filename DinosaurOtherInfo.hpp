#ifndef DINOSAUROTHERINFO_HPP
#define DINOSAUROTHERINFO_HPP


#include<iostream>
#include "String.hpp"
#include "Gender.hpp"
#include "Climate.hpp"
#include "Era.hpp"
#include "KindOfDino.hpp"
#include "Type.hpp"
#include "Food.hpp"

using namespace std;

struct DinosaurOtherInfo
{
	void ClimateInfo();
	void FoodInfo();
	void GenderInfo();
	void KindOfDinoInfo();
	void EraInfo();
	void TypeInfo();

	Climate getClimateByIndex(int& index);
	Food getFoodByIndex(int& index);
	Gender getGenderByIndex(int& index);
	KindOfDino getKindOfDinoByIndex(int& index);
	Era getEraByIndex(int& index);
	Type getTypeByIndex(int& index);
};

#endif
