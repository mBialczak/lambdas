#pragma once

#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <utility>

// void schedule(std::function<void()> func, std::chrono::seconds time) {
//     std::this_thread::sleep_for(time);
//     func();
// }

// void schedule(std::function<void(int)> func,
//               std::chrono::seconds time,
//               int value) {
//     std::this_thread::sleep_for(time);
//     func(value);
// }
// void schedule(std::function<void(std::string, double)> func,
//               std::chrono::seconds time,
//               std::string text,
//               double value) {
//     std::this_thread::sleep_for(time);
//     func(text, value);
// }

// template <typename... Args>
// void schedule(std::function<void(Args...)>,
//               std::chrono::seconds time,
//               Args... args) {
//     std::this_thread::sleep_for(time);
//     func(std::forward<Args>(args)...);
// }

// template <typename... Args, typename Action>
// void schedule(Action func,
//               std::chrono::seconds time,
//               Args... args) {
//     std::this_thread::sleep_for(time);
//     func(std::forward<Args>(args)...);
// }
template <typename... Args,
          typename Action = std::function<void(Args...)>>
void schedule(Action func,
              std::chrono::seconds time,
              Args... args) {
    std::this_thread::sleep_for(time);
    func(std::forward<Args>(args)...);
}

// template <typename... Args, typename std::function<void(Args...)> Action>
// void schedule(Action func,
//               std::chrono::seconds time,
//               Args... args) {
//     std::this_thread::sleep_for(time);
//     func(std::forward<Args>(args)...);
// }
