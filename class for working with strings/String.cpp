#include "String.h"
#include <cstring>
#include <iostream>


String::String() {
	size = 0;
	capacity = 0;
	pointer = nullptr;
}

String::String(const char* str) {
	size = std::strlen(str);
	capacity = size;
	pointer = new char[capacity + 1];
	strcpy_s(pointer, capacity + 1, str);
}

String::String(const String& str) {
	size = str.size;
	capacity = str.capacity;
	pointer = new char[capacity + 1];
	strcpy_s(pointer, capacity + 1, str.pointer);
}

String::String(String&& str) noexcept {
	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;
	str.pointer = nullptr;
	str.capacity = 0;
	str.size = 0;
}

String::~String() {
	if (pointer != nullptr) {delete[] pointer;}
}

String& String::operator= (const char* str) {
	size = std::strlen(str);
	capacity = size;

	if (pointer != nullptr) {delete[] pointer;}
	pointer = new char[capacity + 1];
	strcpy_s(pointer, capacity + 1, str);

	return *this;
}

String& String::operator= (String&& str) noexcept {
	if (this != &str) {
		if (pointer != nullptr) { delete[] pointer; }
		size = str.size;
		capacity = str.capacity;
		pointer = str.pointer;
		str.pointer = nullptr;
		str.size = 0;
		str.capacity = 0;
	}
	return *this;
}

char& String::operator[] (std::size_t pos) {
	if (pos >= 0 && pos < size) {
		return *(pointer + pos);
	}
	throw std::exception("IndexError: index out of range");
}

//String& String::append(const String& str) {
//	std::size_t new_size = size + str.size;
//	//if (size == 0) {
//	//	String temp(str);
//	//	return temp;
//	//}
//	//else if (new_size == 0) {
//	//	return *this;
//	//}
//	if (new_size >= capacity) {
//		capacity = new_size;
//		char* new_pointer = new char[capacity + 1];
//		strcpy_s(new_pointer, capacity + 1, pointer);
//		if (pointer != nullptr) { delete[] pointer; }
//		pointer = new_pointer;
//		if (new_pointer != nullptr) { delete[] new_pointer; }
//	}
//	strcat_s(pointer, capacity+1, str.pointer);
//	setSize(new_size);
//	//size = new_size;
//	return *this;
//}


//String& String::append(const String& str) {
//	//if (pointer[0] == '\0') { return const_cast<String&>(str); }
//	//if (str.pointer[0] == '\0') { return *this; }
//	std::size_t newCapacity = size + str.size;
//	char* newPointer = new char[newCapacity + 1];
//	strcpy_s(newPointer, newCapacity + 1, pointer);
//	strcat_s(newPointer, newCapacity + 1, str.pointer);
//	newPointer[newCapacity] = '\0';
//	//if (pointer != nullptr) {
//	delete[] pointer;
//	//}
//	pointer = newPointer;
//	size = newCapacity;
//	capacity = newCapacity;
//	return *this;
//}

//String& String::append(const String& str) {
//	std::size_t newCapacity = size + str.size;
//	char* newPointer = new char[newCapacity + 1];
//	strcpy_s(newPointer, newCapacity + 1, pointer);
//	strcat_s(newPointer, newCapacity + 1, str.pointer);
//	newPointer[newCapacity] = '\0';
//	delete[] pointer;
//	pointer = newPointer;
//	size = newCapacity;
//	capacity = newCapacity;
//	return *this;
//}

const char& String::operator[](std::size_t pos) const {
	if (pos > size)
		throw std::out_of_range("IndexError: index out of range");
	return *(pointer + pos);
}

String& String::append(const String& str) {
	//—уществет баг при попытке работы с пустой строкой
	std::size_t newCapacity = size + str.size;
	char* newPointer = new char[newCapacity + 1];
	strcpy_s(newPointer, newCapacity + 1, pointer);
	strcat_s(newPointer, newCapacity + 1, str.pointer);
	newPointer[newCapacity] = '\0';
	if (pointer != nullptr) { delete[] pointer; }
	pointer = newPointer;
	size = newCapacity;
	capacity = newCapacity;
	return *this;
}



String& String::operator+(const String& str) {
	return append(str);
}


//String& String::insert(std::size_t pos, const char* str) {
//	std::size_t str_size = std::strlen(str);
//	std::size_t new_size = size + str_size;
//	if (new_size >= capacity) {
//		capacity = new_size;
//		char* new_pointer = new char[capacity + 1];
//		strcpy_s(new_pointer, capacity + 1, pointer);
//		if (pointer != nullptr) {delete[] pointer;}
//		pointer = new_pointer;
//		if (new_pointer != nullptr) { delete[] new_pointer; }
//	}
//	std::memmove(pointer + pos + str_size, pointer + pos, size - pos + 1);
//	std::memcpy(pointer + pos, str, str_size);
//	size = new_size;
//	return *this;
//}

String& String::insert(std::size_t pos, const char* str)
{
	if (pos > size || pos < 0)
	{
		throw std::out_of_range("IndexError: index out of range");
	}
	std::size_t insertionSize = strlen(str);
	std::size_t newCapacity = size + insertionSize;
	char* newPointer = new char[newCapacity + 1];
	strncpy_s(newPointer, newCapacity + 1, pointer, pos);
	newPointer[pos] = '\0';
	strcat_s(newPointer, newCapacity + 1, str);
	strcat_s(newPointer, newCapacity + 1, pointer + pos);
	if (pointer != nullptr) { delete[] pointer; }
	pointer = newPointer;
	size = newCapacity;
	capacity = newCapacity;
	return *this;
}

int String::compare(const String& str) {
	return std::strcmp(pointer, str.pointer);
}

int String::getSize() {
	return size;
}


//hack
void String::output() {
	for (int i = 0; i < capacity; i++)
		std::cout << pointer[i];
	std::cout << std::endl;
}

String& String::operator=(String& str) noexcept {
	if (this != &str) {
		if (pointer != nullptr) { delete[] pointer; }
		size = str.size;
		capacity = str.capacity;
		pointer = str.pointer;
		str.pointer = nullptr;
		str.size = 0;
		str.capacity = 0;
	}
	return *this;
}