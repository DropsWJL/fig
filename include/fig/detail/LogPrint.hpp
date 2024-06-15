#ifndef FIG_LOG_PRINT_HPP
#define FIG_LOG_PRINT_HPP

#include <iostream>

namespace fig {
    template<typename... Args>
    void LogPrint(Args &&...args) {
        ((std::clog << std::forward<Args>(args)), ...);
    }
}

#endif