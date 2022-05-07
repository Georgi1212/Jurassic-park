#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class String {
	
	private:
		unsigned int size;
		char* str;
		
		void copy(const String& other);
		void destroy();
		
		//
		void setStr (const char* _str);
		void setSize(const unsigned int _size);
		
	public:
		//unsigned int length() const;
		
		unsigned int getSize() const;
		
		const char* getStr() const;
		
		
		String();
		String(const char* _str);
		String(const String& other);
		~String();
		
		String& operator=(const String& other);
		
		String operator+(const String& other);
		String& operator+=(const String& other);
		
		const char& operator[](unsigned int index) const;
		char& operator[](unsigned int index);
		
		bool operator==(const String& other);
		bool operator!=(const String& other);
		
		bool contains(char c);
		
		friend std::ostream& operator<<(std::ostream& out, const String& s);
		friend std::istream& operator>>(std::istream& in, String& s);
		
		void helperFuncDeserialize(std::ifstream& in);
		
		void serialize(std::ofstream& out) const;
		void deserialize(std::ifstream& in);
		
};

#endif
