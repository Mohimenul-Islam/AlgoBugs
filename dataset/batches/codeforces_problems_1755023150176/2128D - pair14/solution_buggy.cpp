#include <bits/stdc++.h>

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    u32 t;
    cin >> t;
    while (t--) {
        u32 n;
        cin >> n;
        vector<u32> ps(n);
        for (auto& p : ps) {
            cin >> p;
        }
        u64 sum = n * (n + 1) / 2;
        for (u64 i = 1; i < n; ++i) {
            sum += (ps[i - 1] > ps[i]) * i * (n - i);
        }
        cout << sum << endl;
    }
    return 0;
}
