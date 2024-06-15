#ifndef FIG_IS_BOOL_HPP
#define FIG_IS_BOOL_HPP

#include <type_traits>

namespace fig {
    template<typename T>
    using IsBool = std::is_same<T, bool>;
}

#endif