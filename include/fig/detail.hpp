#ifndef FIG_DETAIL_H
#define FIG_DETAIL_H

#include <iostream>
#include <vector>
#include <string_view>
#include <execinfo.h>

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

#endif