#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {y, x};
    }
    sort(a.begin(), a.end()); // 按bi升序排序，方便区间枚举
    int ans = 0;

    // 枚举区间左端点 i
    for (int i = 0; i < n; i++) {
        priority_queue<int> heap; // 最大堆，维护当前区间选中消息的ai
        i64 sum = 0;              // 当前选中消息ai的和

        // 枚举区间右端点 j
        for (int j = i; j < n; j++) {
            // 跳跃代价是b[j] - b[i]，是区间跨度，不随消息剔除而变化
            int b_diff = a[j].first - a[i].first;

            sum += a[j].second;   // 加入aj
            heap.push(a[j].second);

            // 如果总时间超出预算 l，贪心剔除最大a_i消息
            while (!heap.empty() && sum + b_diff > l) {
                sum -= heap.top();
                heap.pop();
            }
            //如果是a[l]被弹出了 在后面的循环中会枚举到不含a[l]的集合保证正确性
            //如果是a[r]被弹出了 那么在枚举到r之前就会有更优解产生

            //通过遍历所有左端点i和右端点j 枚举所有区间，保证了所有可能的“区间子集”都能被覆盖
			//无论什么时候弹出左端点或右端点消息，对应的子集都会在其他阶段的区间里被重新考虑

            // 更新最大可读消息数
            ans = max(ans, (int)heap.size());
        }
    }
    cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}