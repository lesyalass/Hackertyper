#include "String.h"
#include <iostream>

int String::length()
{
	return size;
}

char* String::c_str()
{
	return data;
}

int String::countChar(char c)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == c)
		{
			counter++;
		}
	}
	return counter;
}

int String::findFirstOf(char c)
{	
	for (int i = 0; i < size; i++)
	{
		if (data[i] == c)
		{
			return i;
		}
	}	
}

char String::operator[](int index)
{
	assert(index >= 0 && index < size && "index out of range");
	return data[index];
	
}

String String::operator+(const String& s)
{

	String a = String();
	if (a.memorySize < this->size + s.size)
	{
		a.memorySize = (this->length() + s.size + 1) * 2 > 100 ? (this->length() + s.size + 1) * 2 : 100;
		a.data = new char[a.memorySize];
		if(this->data != nullptr)
        {
            strcpy(a.data, this->data);
        }
        if(s.data != nullptr)
        {
            strcpy(a.data + this->size, s.data);
        }
        a.size = strlen(a.data);
	}

	return a;
}

String* String::split(int index)
{
	String s1 = String();
	String s2 = String();
	if (index >= this->length() || index < 0)
	{
		return NULL;
	}
	if (s1.memorySize < index + 1)
	{
		s1.memorySize = (index + 1)*2;
		delete[] s1.data;	
		s1.data = new char[s1.memorySize];
	}
	if (s2.memorySize < this->length() - index - 1)
	{
		s2.memorySize = (this->length() - index - 1)*2;
		delete[] s2.data;
		s2.data = new char[s2.memorySize];
	}
	strncpy(s1.data, this->data, index);
    s1.data[index] = '\0';
	strcpy(s2.data, this->data + index + 1);
	s1.size = strlen(s1.data);
    s2.size = strlen(s2.data);
	String* result = new String[2];
	result[0] = s1;
	result[1] = s2;
	return result;
}

bool String::findstr(char* str)
{
	char* istr;
	istr = strstr(data, str);
	if (istr == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

String::String(const char* input)
{
	memorySize = 100;	
	size = strlen(input);
	if (memorySize <= size)
	{
		memorySize = size*2;
	}
	data = new char[memorySize];
	strcpy(data, input);
}

String::String()
{
	memorySize = 0;
	data = nullptr;
	size = 0;
}

String& String::operator=(const String& object)
{

	if (this != &object)
	{

		this->size = object.size;
		this->memorySize = object.memorySize;
        if(this->data != nullptr)
        {
            delete[] this->data;
        }
        if(memorySize != 0)
        {
            this->data = new char[memorySize];
            strcpy(this->data, object.data);
        }
        else
        {
            this->data = nullptr;
        }

	}
	return *this;
}

String::~String()
{
    delete [] data;
    memorySize = 0;
    size = 0;
    data = nullptr;
}

String::String(const String& object)
{

    this->size = object.size;
    this->memorySize = object.memorySize;
    if(memorySize > 0)
    {
        this->data = new char[memorySize];
        strcpy(this->data, object.data);
    }
    else
    {
        this->data = nullptr;
    }
}

