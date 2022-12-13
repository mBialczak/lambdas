#pragma once

#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <utility>

template <typename... Args,
          typename Action = std::function<void(Args...)>>
void schedule(Action func,
              std::chrono::seconds time,
              Args... args) {
    std::this_thread::sleep_for(time);
    func(std::forward<Args>(args)...);
}
