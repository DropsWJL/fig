#ifndef FIG_UTILS_HPP
#define FIG_UTILS_HPP

#include <iostream>
#include <csignal>

namespace fig {
    template<typename T = void>
    void WarningFlush() {
        std::cerr << std::flush;
    }

    template<typename T = void>
    void LogFlush() {
        std::clog << std::flush;
    }

    template<typename T = void>
    void StandardFlush() {
        std::cout << std::flush;
    }

    template<typename T = void>
    void FigRaiseAbort() {
        std::raise(SIGABRT);
    }
    
    template<typename T = void>
    [[noreturn]]
    void FigExit(int status) {
        std::exit(status);
    }
}

#endif