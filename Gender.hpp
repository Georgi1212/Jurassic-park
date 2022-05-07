#ifndef GENDER_HPP
#define GENDER_HPP
#include <iostream>

enum Gender {
	MALE,
	FEMALE,
	OTHERGENDER = -1
};

std::ostream& operator<<(std::ostream& out, const Gender& gen)
{
    
    switch(gen)
    {
        case (Gender)0 : out << "MALE "; break;
        case (Gender)1 : out << "FEMALE "; break;
        default: out << "OTHER GENDER ";
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Gender& gen)
{
	int temp;
	in >> temp;
	
	gen = (Gender)temp;
	
	return in;
}

#endif
