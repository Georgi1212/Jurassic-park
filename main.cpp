#include <iostream>
#include "Vector.hpp"
#include "String.hpp"


using namespace std;


int main ()
{
	Vector<int> vect;
	
	vect.push_back(1);
	vect.push_back(2);
	
	cout << vect;
    
    
	String string1;
	String string2;
	
	cin >> string1;
	cin >> string2;
	
	cout << string1;
	cout << string2;
	
	
	
	
	return 0;	
}
