#pragma once
#include <cstddef>


class String {
private:
	std::size_t size;
	std::size_t capacity;
	char* pointer;
public:
	String();
	String(const char* str);
	String(const String& str);
	String(String&& str) noexcept;
	~String();

	String& operator=(const char* str);
	String& operator= (String&& str) noexcept;
	char& operator[] (std::size_t pos);
	String& append(const String& str);
	String& operator+ (const String& str);
	String& insert(std::size_t pos, const char* str);
	int compare(const String& str);
	int getSize();

	// hack
	void output();
	String& operator= (String& str) noexcept;
	//void setSize(unsigned int value);
	const char& operator[](std::size_t pos) const;

};

