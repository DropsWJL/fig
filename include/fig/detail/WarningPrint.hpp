#ifndef FIG_WARNING_PRINT_HPP
#define FIG_WARNING_PRINT_HPP

#include <iostream>

namespace fig {
    template<typename... Args>
    void WarningPrint(Args &&...args) {
        ((std::cerr << "\033[31m" << std::forward<Args>(args) << "\033[0m"), ...);
    }
}

#endif