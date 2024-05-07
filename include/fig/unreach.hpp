#ifndef FIG_UNREACHED_H
#define FIG_UNREACHED_H

#include <fig/panic.hpp>

#define FIG_UNREACH()                               \
    do {                                            \
        fig::figPrint("[FIG UNREACH]");             \
        fig::figPrint("[File:", __FILE__, "]");     \
        fig::figPrint("[Function:", __func__, "]"); \
        fig::figPrint("[Line:", __LINE__, "]\n");   \
        fig::figPrint("UNREACH: ");                 \
        fig::figPrintStackTrace();                  \
        fig::figFlush();                            \
        fig::figExit(-1);                           \
    } while(0)

#endif