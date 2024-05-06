#include <csignal>
#include <fig/assert.hpp>
#include <fig/debug.hpp>
#include <fig/error.hpp>
#include <fig/panic.hpp>
#include <fig/unreach.hpp>

#include <algorithm>
#include <vector>

static void FigAssert() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {2, 5, 1, 3, 4};
    FIG_ASSERT(vec1 != vec2, "Before Sorting, vec1 == vec2.");
    std::sort(vec2.begin(), vec2.end());
    FIG_ASSERT(vec1 == vec2, "After Sorting, vec1 != vec2.");
}

static void FigPanic() {
    auto defaultCerr = std::cerr.rdbuf();
    std::cerr.rdbuf(nullptr);
    std::signal(SIGABRT, []([[maybe_unused]]int e) { /* Empty */ });
    FIG_PANIC("Something wrong!");
    std::signal(SIGABRT, SIG_DFL);
    std::cerr.rdbuf(defaultCerr);
}

static void FigUnreach() {
    auto defaultCerr = std::cerr.rdbuf();
    std::cerr.rdbuf(nullptr);
    std::signal(SIGABRT, []([[maybe_unused]]int e) { /* Empty */ });
    FIG_UNREACH();
    std::signal(SIGABRT, SIG_DFL);
    std::cerr.rdbuf(defaultCerr);
}

static void FigDebug() {
    FIG_DEBUG();
}

int main() {
    FigDebug();
    FigAssert();
    FigPanic();
    FigUnreach();
    return 0;
}