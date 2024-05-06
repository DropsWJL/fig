#ifndef FIG_ASSERT_H
#define FIG_ASSERT_H

#include <fig/detail.hpp>
#include <type_traits>
#include <csignal>

template<typename T>
using is_bool = std::is_same<T, bool>;

#if defined(FIG_ASSERT_OFF_MODE)
#define FIG_ASSERT(cond, ...)                                                      \
    do {                                                                           \
        static_assert(is_bool<decltype(cond)>::value, "cond's type must be bool"); \
    } while(0)
#elif defined(FIG_ASSERT_CONCISE_MODE)
#define FIG_ASSERT(cond, ...)                                                      \
    do {                                                                           \
        static_assert(is_bool<decltype(cond)>::value, "cond's type must be bool"); \
        figPrint("ASSERT MSG: ");                                                  \
        figPrint(__VA_ARGS__, "\n");                                               \
        figFlush();                                                                \
        std::raise(SIGABRT);                                                       \
    } while(0)
#else
#define FIG_ASSERT(cond, ...)                                                      \
    do {                                                                           \
        static_assert(is_bool<decltype(cond)>::value, "cond's type must be bool"); \
        if(!(cond)) {                                                              \
            figPrint("[FIG ASSERT FAILURE]");                                      \
            figPrint("[File:", __FILE__, "]");                                     \
            figPrint("[Function:", __func__, "]");                                 \
            figPrint("[Line:", __LINE__, "]\n");                                   \
            figPrint("ASSERT MSG: ");                                              \
            figPrint(__VA_ARGS__, "\n");                                           \
            figFlush();                                                            \
            std::raise(SIGABRT);                                                   \
        }                                                                          \
    } while(0)

#endif

#endif