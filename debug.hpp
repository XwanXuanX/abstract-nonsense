#include <bits/stdc++.h>
using namespace std;

inline namespace FastIO {
#define SFINAE(x, ...)                                                         \
    template <class, class = void> struct x : std::false_type {};              \
    template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuples, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
template <typename T> char sp(T &t) {
    return (Iterable<T>::value || IsTuples<T>::value) ? '\n' : ' ';
}
template <typename T> void re(T &t) {
    if constexpr (DefaultI<T>::value) {
        cin >> t;
    } else if constexpr (Iterable<T>::value) {
        for (auto &x : t)
            re(x);
    } else if constexpr (IsTuples<T>::value) {
        std::apply([&](auto &...args) { (re(args), ...); }, t);
    }
}
template <typename T> void pt(T &t) {
    if constexpr (DefaultO<T>::value) {
        cout << t;
    } else if constexpr (Iterable<T>::value) {
        int i = 0;
        for (auto &&x : t)
            ((i++) ? (cout << sp(x), pt(x)) : pt(x));
    } else if constexpr (IsTuples<T>::value) {
        std::apply(
            [&](auto const &...args) {
                int i = 0;
                (((i++) ? (cout << " ", pt(args)) : pt(args)), ...);
            },
            t);
    }
}
template <typename T, typename... Ts>
void ps(const string &s, T &t, Ts &...ts) {
    pt(t), ((cout << s, pt(ts)), ...), cout << '\n';
}
void ps(const string &) { cout << '\n'; }
template <typename... Ts> void print(const Ts &...ts) {
    FastIO::ps(" ", ts...);
}
template <typename... Ts> void read(Ts &...ts) { ((FastIO::re(ts)), ...); }
#undef SFINAE
} // namespace FastIO