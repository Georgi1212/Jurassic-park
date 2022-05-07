#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>

enum Food {
	GRASS, 
	MEAT, 
	FISH,
	OTHERFOOD = -1
};

std::ostream& operator<<(std::ostream& out, const Food& fd)
{
    
    switch(fd)
    {
        case (Food)0 : out << "GRASS "; break;
        case (Food)1 : out << "MEAT "; break;
        case (Food)2 : out << "FISH "; break;
        default: out << "OTHER FOOD ";
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Food& fd)
{
	int temp;
	in >> temp;
	
	fd = (Food)temp;
	
	return in;
}

#endif
