#include "String.h"
#include <iostream>

using namespace std;

void testString() {
    // Default constructor
    String s1;
    s1.output();

    // Constructor with const char*
    String s2("Hello");
    s2.output();

    // Copy constructor
    String s3(s2);
    s3.output();

    // Move constructor
    String s4(std::move(s2));
    s4.output();

    // Assignment operator with const char*
    s1 = "World";
    s1.output();

    // Move assignment operator
    s3 = std::move(s4);
    s3.output();

    // Index operator
    s1[0] = 'w';
    s1.output();

    // Append function
    s1.append("!");
    s1.output();

    // Concatenation operator
    s1 = s1 + s3;
    s1.output();

    // Insert function
    s1.insert(5, " ");
    s1.output();

    // Comparison function
    std::cout << "s1 == s3: " << (s1.compare(s3) == 0 ? "true" : "false") << std::endl;
}

int main() {
    testString();
}
