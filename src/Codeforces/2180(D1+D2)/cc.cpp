#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static mt19937_64 rng (
    chrono::steady_clock::now().time_since_epoch().count()
);
#define randll(l, r) (uniform_int_distribution<long long>((l),(r))(rng))

string lltos(i64 num, int base, int siz){
	if(num == 0){
		return string(siz, '0');
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	while(res.size() < siz) {
		res += "0";
	}
	reverse(res.begin(), res.end());
	return res;
}
void solve() {
    int n, k;
    std::cin >> n >> k;
    
    if (k % 2 == 1) {
        for (int i = 0; i < k; i++) {
            std::cout << n << " \n"[i == k - 1];
        }
    } else if (!(n & (n - 1))) {
        std::cout << 0 << " ";
        for (int i = 1; i < k; i++) {
            std::cout << n << " \n"[i == k - 1];
        }
    } else {
        int t = std::__lg(n);
        int x = (2 << std::__lg(n - (1 << t))) - 1;
        int y = n ^ x;
        for (int i = 0; i < k; i++) {
            if (i == 0) {
                std::cout << x;
            } else if (i == 1) {
                std::cout << y;
            } else {
                std::cout << n;
            }
            std::cout << " \n"[i == k - 1];
        }
    }
}
 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
