#pragma once

#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <utility>

template <typename Action, typename ...Args>
void schedule(Action func,
              std::chrono::seconds time,
              Args... args) {
    std::this_thread::sleep_for(time);
    std::invoke(func, std::forward<Args>(args)...);
}
