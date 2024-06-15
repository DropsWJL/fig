#ifndef FIG_UNREACHED_HPP
#define FIG_UNREACHED_HPP

#include "./detail/Utils.hpp"
#include "./detail/WarningPrintStackTrace.hpp"

#define FIG_UNREACH()                                   \
    do {                                                \
        fig::WarningPrint("[FIG UNREACH]");             \
        fig::WarningPrint("[File:", __FILE__, "]");     \
        fig::WarningPrint("[Function:", __func__, "]"); \
        fig::WarningPrint("[Line:", __LINE__, "]\n");   \
        fig::WarningPrint("UNREACH: ");                 \
        fig::WarningPrintStackTrace();                  \
        fig::WarningFlush();                            \
        fig::FigExit(-1);                               \
    } while(0)

#endif