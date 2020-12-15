#pragma once
#include <string.h>
#include <cassert>

class String
{
	public:
		int length();
		String();
		~String();
		String(const char* input);
        String(const String& object);
		String& operator=(const String& object);
		char* c_str();
		int countChar(char c);
		int findFirstOf(char c);
		char operator[](int index);
		String operator+(const String& s);
		String* split(int index);
		bool findstr(char* str);

	private:
		int size;
		char* data;	
		int memorySize;
};

