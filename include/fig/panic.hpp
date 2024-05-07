#ifndef FIG_PANIC_H
#define FIG_PANIC_H

#include <fig/detail.hpp>

#define FIG_PANIC(...)                              \
    do {                                            \
        fig::figPrint("[FIG PANIC]");               \
        fig::figPrint("[File:", __FILE__, "]");     \
        fig::figPrint("[Function:", __func__, "]"); \
        fig::figPrint("[Line:", __LINE__, "]\n");   \
        fig::figPrint("PANIC: ");                   \
        fig::figPrint(__VA_ARGS__, "\n");           \
        fig::figPrintStackTrace();                  \
        fig::figFlush();                            \
        fig::figExit(-1);                           \
    } while(0)

#endif