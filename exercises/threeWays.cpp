#include <algorithm>
#include <iostream>
#include <vector>

// use STL algorithm to check if all elements are divisible by 3
// implement 3 versions:
// * lambda
// * functor
// * function

bool is_divisible_by_three(const int number)
{
    return number % 3 == 0;
}

struct Is_divisible_by_three
{
    bool operator()(const int number)
    {
        return number % 3 == 0;
    }
};

int main()
{
    std::vector numbers = { 18, 21, 36, 90, 27, 14, 103 };
    bool all_divisible1 = std::all_of(numbers.begin(),
                                      numbers.end(),
                                      is_divisible_by_three);

    bool all_divisible2 = std::all_of(numbers.begin(),
                                      numbers.end(),
                                      Is_divisible_by_three {});

    bool all_divisible3 = std::all_of(numbers.begin(),
                                      numbers.end(),
                                      [](int number) {
                                          return number % 3 == 0;
                                      });

    std::cout << "With function: " << std::boolalpha << all_divisible1 << std::endl;
    std::cout << "With function: " << std::boolalpha << all_divisible2 << std::endl;
    std::cout << "With function: " << std::boolalpha << all_divisible3 << std::endl;

    return 0;
}
