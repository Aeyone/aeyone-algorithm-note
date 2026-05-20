#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() { // 普通st表
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    const int pow = 20;
    vector<array<int, pow + 1>> st(n);

    for(int i = 0; i < n; i ++){    //p = 0时
        st[i][0] = a[i];
    }
    for(int p = 1; n >> p > 0; p ++){   //枚举所有p
        for(int i = 0; i + (1 << p) <= n; i ++){    //从下标 i 开始的长度为 2^p 的区间大小不能超过n
            st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
        }
    }
    auto query = [&](int l, int r)->int{
        int p = __lg(r - l + 1);
        return max(st[l][p], st[r - (1 << p) + 1][p]);//取从l开始的2^p格内和以r结尾的2^p格内的最大值
    };

    for(int i = 0; i < n; i ++){
        for(int j = i; j < n; j ++)
            cout << "i: " << i + 1 << ' ' << "j: " << j + 1 << ' ' << "MAX: " << query(i, j) << '\n';
    }
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}