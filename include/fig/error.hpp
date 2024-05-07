#ifndef FIG_ERROR_H
#define FIG_ERROR_H

#include <fig/detail.hpp>

#if defined(FIG_ERROR_OFF_MODE)
#define FIG_ERROR(...)
#elif defined(FIG_ERROR_CONCISE_MODE)
#define FIG_ERROR(...)              \
    do {                            \
        fig::figPrint("ERROR: ");   \
        fig::figPrint(__VA_ARGS__); \
        fig::figFlush();            \
        fig::figRaiseAbort();       \
    } while(0)
#else
#define FIG_ERROR(...)                              \
    do {                                            \
        fig::figPrint("[FIG ERROR]");               \
        fig::figPrint("[File:", __FILE__, "]");     \
        fig::figPrint("[Function:", __func__, "]"); \
        fig::figPrint("[Line:", __LINE__, "]\n");   \
        fig::figPrint("ERROR: ");                   \
        fig::figPrint(__VA_ARGS__, "\n");           \
        fig::figPrintStackTrace();                  \
        fig::figFlush();                            \
        fig::figRaiseAbort();                       \
    } while(0)
#endif

#endif