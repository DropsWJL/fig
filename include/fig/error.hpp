#ifndef FIG_ERROR_HPP
#define FIG_ERROR_HPP

#include "./detail/Utils.hpp"
#include "./detail/WarningPrintStackTrace.hpp"

#if defined(FIG_ERROR_OFF_MODE)
#define FIG_ERROR(...)
#elif defined(FIG_ERROR_CONCISE_MODE)
#define FIG_ERROR(...)                                    \
    do {                                                  \
        fig::WarningPrint("ERROR: ");                     \
        fig::WarningPrint(__VA_ARGS__ __VA_OPT__("...")); \
        fig::WarningFlush();                              \
        fig::FigRaiseAbort();                             \
    } while(0)
#else
#define FIG_ERROR(...)                                      \
    do {                                                    \
        fig::WarningPrint("[FIG ERROR]");                   \
        fig::WarningPrint("[File:", __FILE__, "]");         \
        fig::WarningPrint("[Function:", __func__, "]");     \
        fig::WarningPrint("[Line:", __LINE__, "]\n");       \
        fig::WarningPrint("ERROR: ");                       \
        fig::WarningPrint(__VA_ARGS__ __VA_OPT__(, ) "\n"); \
        fig::WarningPrintStackTrace();                      \
        fig::WarningFlush();                                \
        fig::FigRaiseAbort();                               \
    } while(0)
#endif

#endif