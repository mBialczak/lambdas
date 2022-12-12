// Create a lambda that with each call returns a consecutive letter of the alphabet
// starting from 'a'. When we reach 'z', the lambda should return uppercase letters
// - from 'A' to 'Z'. Then, it should start overt with 'a'. Don't use static
// or global variables. Try to implement it without looking into the ASCII table.

#include <iostream>

int main()
{

    auto alphabet = [currentLetter = 'a']() mutable {
        const char lowerEnd = 'z';
        const char upperEnd = 'Z';
        char result { currentLetter };
        if (currentLetter == lowerEnd) {
            currentLetter = 'A';
        }
        else if (currentLetter == upperEnd) {
            currentLetter = 'a';
        }
        else {
            ++currentLetter;
        }

        return result;
    };
    for (int i = 0; i < 100; ++i) {
        std::cout << alphabet() << std::endl;
        ;
    }
    std::cout << '\n';
    return 0;
}
