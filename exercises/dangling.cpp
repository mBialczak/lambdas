#include <iostream>

auto getIndexGenerator()
{
    auto lambda = [value = 0]() mutable {
        return value++;
    };
    return lambda;
}

int getFive()
{
    auto result = 5 + 4;
    return result;
}

// Fix the code.
// We want a generator to provide consecutive numbers starting from 0.
// Correct output: `0123456789`

int main()
{
    auto generator = getIndexGenerator();
    [[maybe_unused]] int value = getFive();
    for (int i = 0; i < 10; ++i) {
        std::cout << generator();
    }
    std::cout << '\n';
    return 0;
}