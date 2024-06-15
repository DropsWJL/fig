#ifndef FIG_LOG_HPP
#define FIG_LOG_HPP

#include "./detail/Utils.hpp"
#include "./detail/LogPrint.hpp"

#if defined(FIG_LOG_OFF_MODE)
#define FIG_LOG(...)
#else
#define FIG_LOG(...)                                    \
    do {                                                \
        fig::LogPrint("[FIG LOG]");                     \
        fig::LogPrint(__VA_ARGS__ __VA_OPT__(, ) "\n"); \
        fig::LogFlush();                                \
    } while(0)
#endif

#endif