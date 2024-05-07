#ifndef FIG_DETAIL_H
#define FIG_DETAIL_H

#include <iostream>
#include <vector>
#include <type_traits>
#include <string_view>
#include <execinfo.h>
#include <csignal>

namespace fig {
    template<typename T>
    using is_bool = std::is_same<T, bool>;

    template<typename... Args>
    void figPrint(Args &&...args) {
        ((std::cerr << "\033[31m" << std::forward<Args>(args) << "\033[0m"), ...);
    }

    template<typename T = void>
    void figFlush() {
        std::cerr << std::flush;
    }

    template<typename T = void>
    void figPrintStackTrace() {
        const int maxFrames = 64;
        void *stackFrames[maxFrames];
        int numFrames  = backtrace(stackFrames, maxFrames);
        char **symbols = backtrace_symbols(stackFrames, numFrames);

        figPrint("Stack Trace:\n");
        if(symbols != nullptr) {
            std::vector<std::string_view> stackTrace(symbols, symbols + numFrames);
            for(const auto &frame : stackTrace) {
                figPrint(frame, "\n");
            }
            free(symbols);
        } else {
            figPrint("Failed to get stack trace.");
        }
    }

    template<typename T = void>
    void figRaiseAbort() {
        std::raise(SIGABRT);
    }

    template<typename T = void>
    void figExit(int status) {
        std::exit(status);
    }
} // namespace fig

#endif