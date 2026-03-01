#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector b(n+1,vector<int> (n+1));
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> b[i][j];
		}
	}
	int ans=0;
	vector<int> vis(n+1),dis(n+1,INF);
	vis[1]=1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h;
	for(int i=2;i<=n;i++){
		h.push({b[1][i],i});
	} 
	while(h.size()){
		auto [w,u]=h.top();
		h.pop();
		if(vis[u]) continue;
		vis[u]=1,ans+=w;
		for(int v=1;v<=n;v++){
			// cout<<"v = "<< v<<" w = "<<w<<endl;
			if(!vis[v]&&dis[v]>b[u][v]){			
				dis[v]=b[u][v];
				h.push({dis[v],v});
			} 
		}
	}
	// cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		int mn=INF;
		for(int j=1;j<=n;j++){
			mn=min(mn,b[i][j]);
		}
		ans+=mn*(a[i]-1);
	}	
	cout<<ans<<endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}