#include <bits/stdc++.h>

constexpr std::uint64_t gcd(std::uint64_t a, std::uint64_t b) noexcept {
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0) {
        std::uint64_t r = a % b;
        a = b;
        b = r;
    }
    return a;
}


uint64_t compute(uint64_t a, uint64_t b, uint64_t k) {
    if (a == b) {
        return 1;
    }
    auto g = gcd(a, b);
    if (a / g <= k and b / g <= k) {
        return 1;
    }
    return 2;
}

void solve() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int a, b, k;
        std::cin >> a >> b >> k;
        std::cout << compute(a, b, k) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

