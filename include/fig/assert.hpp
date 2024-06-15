#ifndef FIG_ASSERT_HPP
#define FIG_ASSERT_HPP

#include "./detail/IsBool.hpp"
#include "./detail/Utils.hpp"
#include "./detail/WarningPrint.hpp"

#if defined(FIG_ASSERT_OFF_MODE)
#define FIG_ASSERT(cond, ...)                                                          \
    do {                                                                               \
        static_assert(fig::IsBool<decltype(cond)>::value, "cond's type must be bool"); \
    } while(0)
#elif defined(FIG_ASSERT_CONCISE_MODE)
#define FIG_ASSERT(cond, ...)                                                          \
    do {                                                                               \
        static_assert(fig::IsBool<decltype(cond)>::value, "cond's type must be bool"); \
        fig::WarningPrint("ASSERT MSG: ");                                             \
        fig::WarningPrint(__VA_ARGS__ __VA_OPT__(, ) "\n");                            \
        fig::WarningFlush();                                                           \
        fig::FigRaiseAbort();                                                          \
    } while(0)
#else
#define FIG_ASSERT(cond, ...)                                                          \
    do {                                                                               \
        static_assert(fig::IsBool<decltype(cond)>::value, "cond's type must be bool"); \
        if(!(cond)) {                                                                  \
            fig::WarningPrint("[FIG ASSERT FAILURE]");                                 \
            fig::WarningPrint("[File:", __FILE__, "]");                                \
            fig::WarningPrint("[Function:", __func__, "]");                            \
            fig::WarningPrint("[Line:", __LINE__, "]\n");                              \
            fig::WarningPrint("ASSERT MSG: ");                                         \
            fig::WarningPrint(__VA_ARGS__ __VA_OPT__(, ) "\n");                        \
            fig::WarningFlush();                                                       \
            fig::FigRaiseAbort();                                                      \
        }                                                                              \
    } while(0)

#endif

#endif