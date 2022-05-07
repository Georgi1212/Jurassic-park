#ifndef ERA_HPP
#define ERA_HPP

#include <iostream>

enum Era {
	TRIAS,
	CHALK,
	JURA,
	OTHERERA = -1
};

std::ostream& operator<<(std::ostream& out, const Era& e)
{
    
    switch(e)
    {
        case (Era)0 : out << "TRIAS "; break;
        case (Era)1 : out << "CHALK "; break;
        case (Era)2 : out << "JURA "; break;
        default: out << "OTHER ERA ";
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Era& e)
{
	int temp;
	in >> temp;
	
	e = (Era)temp;
	
	return in;
}
#endif
