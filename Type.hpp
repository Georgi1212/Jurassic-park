#ifndef TYPE_HPP
#define TYPE_HPP
#include<iostream>

enum Type {
	PLESIOSAURUS,
	BROTOSAURUS,
	TYRANNOSAURUS,
	OTHERTYPE = -1,
};

std::ostream& operator<<(std::ostream& out, const Type& t)
{
    
    switch(t)
    {
        case (Type)0 : out << "PLESIOSAURUS "; break;
        case (Type)1 : out << "BROTOSAURUS "; break;
        case (Type)2 : out << "TYRANNOSAURUS "; break;
        default: out << "OTHER TYPE ";
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Type& t)
{
	int temp;
	in >> temp;
	
	t = (Type)temp;
	
	return in;
}


#endif

