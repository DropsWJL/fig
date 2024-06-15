#ifndef FIG_STANDARD_PRINT_HPP
#define FIG_STANDARD_PRINT_HPP

#include <iostream>

namespace fig {
    template<typename... Args>
    void StandardPrint(Args &&...args) {
        ((std::cout << std::forward<Args>(args)), ...);
    }
}

#endif