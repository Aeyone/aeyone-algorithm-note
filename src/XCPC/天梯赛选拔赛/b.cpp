#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve()
{
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<int> a(n + 1), vis(m + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		vis[a[i]]++;
	}
	int ans = 0;
	for (int i = n; i > 0; i--)
	{
		if (--vis[a[i]] == 0)
			break;
		ans++;
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--)
	{
		solve();
	}
}