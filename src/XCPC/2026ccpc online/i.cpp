#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	vector<int> v;
	int n = 30;
	for(int a = -n;a<=n;a++){
		for(int b = -n;b<=n;b++){
			for(int c = -n;c<=n;c++){
				// int sum = (pow(a+b+c,3)-pow(a,3)-pow(b,3)-pow(c,3)-6*a*b*c)/3;
				int sum = a*b*(a+b)+a*c*(a+c)+b*c*(b+c);
				if (sum >= 0) {
					v.push_back(sum);
				}
			}
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(auto x:v)cout<<x<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}