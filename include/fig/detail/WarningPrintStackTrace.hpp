#ifndef FIG_WARNING_PRINT_STACKTRACE_HPP
#define FIG_WARNING_PRINT_STACKTRACE_HPP

#include "WarningPrint.hpp"
#include <execinfo.h>
#include <vector>

namespace fig {
    template<typename T = void>
    void WarningPrintStackTrace() {
        const int maxFrames = 64;
        void *stackFrames[maxFrames];
        int numFrames  = backtrace(stackFrames, maxFrames);
        char **symbols = backtrace_symbols(stackFrames, numFrames);

        WarningPrint("Stack Trace:\n");
        if(symbols != nullptr) {
            std::vector<std::string_view> stackTrace(symbols, symbols + numFrames);
            for(const auto &frame : stackTrace) {
                WarningPrint(frame, "\n");
            }
            free(symbols);
        } else {
            WarningPrint("Failed to get stack trace.");
        }
    }
}

#endif