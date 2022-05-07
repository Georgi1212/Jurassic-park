#ifndef KINDOFDINO_HPP
#define KINDOFDINO_HPP
#include <iostream>

enum KindOfDino {
	CARNIVOROUS, 
	HERBIVOROUS, 
	AQUATIC, 
	FLYING,
	OTHERKIND = -1
};

std::ostream& operator<<(std::ostream& out, const KindOfDino& kd)
{
    
    switch(kd)
    {
        case (KindOfDino)0 : out << "CARNIVOROUS "; break;
        case (KindOfDino)1 : out << "HERBIVOROUS "; break;
        case (KindOfDino)2 : out << "AQUATIC "; break;
        case (KindOfDino)3 : out << "FLYING"; break;
        default: out << "OTHER KIND ";
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, KindOfDino& kd)
{
	int temp;
	in >> temp;
	
	kd = (KindOfDino)temp;
	
	return in;
}

#endif
