#ifndef FIG_PANIC_H
#define FIG_PANIC_H

#include <fig/detail.hpp>
#include <csignal>

#define FIG_PANIC(...)                         \
    do {                                       \
        figPrint("[FIG PANIC]");               \
        figPrint("[File:", __FILE__, "]");     \
        figPrint("[Function:", __func__, "]"); \
        figPrint("[Line:", __LINE__, "]\n");   \
        figPrint("PANIC: ");                   \
        figPrint(__VA_ARGS__, "\n");           \
        figPrintStackTrace();                  \
        figFlush();                            \
        std::raise(SIGABRT);                   \
    } while(0)

#endif