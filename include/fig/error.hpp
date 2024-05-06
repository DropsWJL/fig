#ifndef FIG_ERROR_H
#define FIG_ERROR_H

#include <fig/detail.hpp>

#if defined(FIG_ERROR_OFF_MODE)
#define FIG_ERROR(...)
#elif defined(FIG_ERROR_CONCISE_MODE)
#define FIG_ERROR(...)         \
    do {                       \
        figPrint("ERROR: ");   \
        figPrint(__VA_ARGS__); \
        figFlush();            \
        std::raise(SIGABRT);   \
    } while(0)
#else
#define FIG_ERROR(...)                         \
    do {                                       \
        figPrint("[FIG ERROR]");               \
        figPrint("[File:", __FILE__, "]");     \
        figPrint("[Function:", __func__, "]"); \
        figPrint("[Line:", __LINE__, "]\n");   \
        figPrint("ERROR: ");                   \
        figPrint(__VA_ARGS__, "\n");           \
        figPrintStackTrace();                  \
        figFlush();                            \
        std::raise(SIGABRT);                   \
    } while(0)
#endif

#endif