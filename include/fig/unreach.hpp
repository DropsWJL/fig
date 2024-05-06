#ifndef FIG_UNREACHED_H
#define FIG_UNREACHED_H

#include <fig/panic.hpp>
#include <csignal>

#define FIG_UNREACH()                          \
    do {                                       \
        figPrint("[FIG UNREACH]");             \
        figPrint("[File:", __FILE__, "]");     \
        figPrint("[Function:", __func__, "]"); \
        figPrint("[Line:", __LINE__, "]\n");   \
        figPrint("UNREACH: ");                 \
        figPrintStackTrace();                  \
        figFlush();                            \
        std::raise(SIGABRT);                   \
    } while(0)

#endif