#ifndef FIG_ASSERT_H
#define FIG_ASSERT_H

#include <fig/detail.hpp>

#if defined(FIG_ASSERT_OFF_MODE)
#define FIG_ASSERT(cond, ...)                                                           \
    do {                                                                                \
        static_assert(fig::is_bool<decltype(cond)>::value, "cond's type must be bool"); \
    } while(0)
#elif defined(FIG_ASSERT_CONCISE_MODE)
#define FIG_ASSERT(cond, ...)                                                           \
    do {                                                                                \
        static_assert(fig::is_bool<decltype(cond)>::value, "cond's type must be bool"); \
        fig::figPrint("ASSERT MSG: ");                                                  \
        fig::figPrint(__VA_ARGS__, "\n");                                               \
        fig::figFlush();                                                                \
        fig::figRaiseAbort();                                                           \
    } while(0)
#else
#define FIG_ASSERT(cond, ...)                                                           \
    do {                                                                                \
        static_assert(fig::is_bool<decltype(cond)>::value, "cond's type must be bool"); \
        if(!(cond)) {                                                                   \
            fig::figPrint("[FIG ASSERT FAILURE]");                                      \
            fig::figPrint("[File:", __FILE__, "]");                                     \
            fig::figPrint("[Function:", __func__, "]");                                 \
            fig::figPrint("[Line:", __LINE__, "]\n");                                   \
            fig::figPrint("ASSERT MSG: ");                                              \
            fig::figPrint(__VA_ARGS__, "\n");                                           \
            fig::figFlush();                                                            \
            fig::figRaiseAbort();                                                       \
        }                                                                               \
    } while(0)

#endif

#endif