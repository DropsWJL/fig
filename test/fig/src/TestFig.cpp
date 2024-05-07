#include <csignal>
#include <cstdlib>
#include <fig/assert.hpp>
#include <fig/debug.hpp>
#include <fig/error.hpp>
#include <fig/panic.hpp>
#include <fig/unreach.hpp>

#include <algorithm>
#include <vector>

[[maybe_unused]]
static void FigUnreach() {
    FIG_UNREACH();
}

[[maybe_unused]]
static void FigPanic() {
    FIG_PANIC("Something wrong!");
}

static void FigAssert() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {2, 5, 1, 3, 4};
    FIG_ASSERT(vec1 != vec2, "Before Sorting, vec1 == vec2.");
    std::sort(vec2.begin(), vec2.end());
    FIG_ASSERT(vec1 == vec2, "After Sorting, vec1 != vec2.");
}

static void FigError() {
    std::signal(SIGABRT, []([[maybe_unused]] int e) { /* Empty */ });
    FIG_ERROR("Something wrong!");
    std::signal(SIGABRT, SIG_DFL);
}

static void FigDebug() {
#if defined(FIG_DEBUG_OFF_MODE)
    return;
#else
    FIG_DEBUG(
        return;);
    FigPanic();
#endif
}

int main() {
    FigDebug();
    FigAssert();
    FigError();
    return 0;
}