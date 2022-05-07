#ifndef CLIMATE_HPP
#define CLIMATE_HPP

#include <iostream>

enum Climate {
	TERRESTRIAL,
	AIR,
	WATER,
	OTHERCLIMATE = -1
};


std::ostream& operator<<(std::ostream& out, const Climate& cl)
{
    /*switch(cl)
    {
        case TERRESTRIAL : return out << "TERRESTRIAL"; 
        case AIR : return out << "AIR"; 
        case WATER : return out << "WATER"; 
        default: return out << "OTHER CLIMATE";
    }*/
    
    switch(cl)
    {
        case (Climate)0 : out << "TERRESTRIAL "; break;
        case (Climate)1 : out << "AIR "; break;
        case (Climate)2 : out << "WATER "; break;
        default: out << "OTHER CLIMATE ";
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Climate& cl)
{
	int temp;
	in >> temp;
	
	cl = (Climate)temp;
	
	return in;
}

#endif

