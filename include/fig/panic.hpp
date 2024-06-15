#ifndef FIG_PANIC_HPP
#define FIG_PANIC_HPP

#include "./detail/Utils.hpp"
#include "./detail/WarningPrintStackTrace.hpp"

#define FIG_PANIC(...)                                      \
    do {                                                    \
        fig::WarningPrint("[FIG PANIC]");                   \
        fig::WarningPrint("[File:", __FILE__, "]");         \
        fig::WarningPrint("[Function:", __func__, "]");     \
        fig::WarningPrint("[Line:", __LINE__, "]\n");       \
        fig::WarningPrint("PANIC: ");                       \
        fig::WarningPrint(__VA_ARGS__ __VA_OPT__(, ) "\n"); \
        fig::WarningPrintStackTrace();                      \
        fig::WarningFlush();                                \
        fig::FigExit(-1);                                   \
    } while(0)

#endif