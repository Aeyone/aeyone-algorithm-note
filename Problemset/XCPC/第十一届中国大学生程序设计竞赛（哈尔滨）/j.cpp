/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

vector<int> modify(vector<int> s){
    vector<int> ss;
    for(int i = 0; i < s.size(); i ++){
        ss.push_back(INF);
        ss.push_back(s[i]);
    }
    ss.push_back(INF);
    return ss;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	n = s.size();
	vector<int> to;
	auto manacher = [&](vector<int> str)->void{
	    vector<int> s = modify(str);
		vector<int> p(s.size());
	    int n = s.size();
	    // for(auto e : s){
	    // 	if(e == INF){
	    // 		cout << "x" << ' ';
	    // 	}else{
	    // 		cout << e << ' ';
	    // 	}
	    // }
	    // cout << '\n';
	    for(int i = 0, len = 0, c = 0, r = 0; i < n; i++){
	        len = (i < r ? min(p[c * 2 - i], r - i) : 1);
	        while(i + len < n && i - len >= 0 && s[i - len] == s[i + len]){
	        	len ++;
	        }
	        p[i] = len;
	        if (i + len > r){ //记得更新
	            r = i + len;
	            c = i;
	        }
	        // cout << "i, len = " << i << ' ' << len << '\n';
	        if(len >= 2){
	        	int L = (i - len + 2) / 2, R = (i + len - 2) / 2;
	        	to[L] = max(to[L], R);
	        }
	    }
	};
	vector<int> w, st, ed;
	vector<array<int, 2>> pre, suf;
	vector<vector<int>> pcnt, scnt;
	auto cmp = [](char a, char b)->bool{
		return a == b || ((a == 'w' || a == 'v') && (b == 'w' || b == 'v'));
	};
	for(int l = 0, r = 0; l < n; l = r){
		array<int, 2> P = {0, 0}, S = {0, 0};
		vector<int> pc, sc;
		int sum = 0, ssum = 0;
		while(r < n && cmp(s[l], s[r])){
			sum += (s[r ++] == 'w') + 1;
			P[sum & 1] = sum;
			pc.push_back(sum);
		}
		for(int i = r - 1; i >= l; i --){
			ssum += (s[i] == 'w') + 1;
			S[ssum & 1] = ssum;
			sc.push_back(ssum);
		}
		if(s[l] == 'o'){
			sum = -sum;
		}
		w.push_back(sum);
		st.push_back(l);
		ed.push_back(r - 1);
		pre.push_back(P);
		suf.push_back(S);
		pcnt.push_back(pc);
		scnt.push_back(sc);
	}
	int m = w.size();
	to.resize(m);
	iota(to.begin(), to.end(), 0);
    manacher(w);
    array<int, 2> ans;
    int mx = 0;
    for(int i = 0; i < m; i ++){
    	// for(int j = st[i]; j <= ed[i]; j ++){
    	// 	cout << s[j];
    	// }
    	// cout << " | to = " << to[i] << '\n';

    	int l = i - 1, r = to[i] + 1, len = ed[to[i]] - st[i] + 1, add = -1;
    	int pidx = 0, sidx = 0;
    	if(l >= 0 && r < m){
    		add = max(min(suf[l][0], pre[r][0]), min(suf[l][1], pre[r][1]));
    		// cout << "add = " << add << '\n';
    		sidx = lower_bound(scnt[l].begin(), scnt[l].end(), add) - scnt[l].begin() + 1;
    		pidx = lower_bound(pcnt[r].begin(), pcnt[r].end(), add) - pcnt[r].begin() + 1;
    		// cout << "sidx = " << sidx << " pidx = " << pidx << '\n';
    		if(scnt[l][sidx - 1] == add && pcnt[r][pidx - 1] == add){
	    		len = (ed[to[i]] + pidx) - (st[i] - sidx) + 1;
    		}else{
    			add = -1;
    		}
    	}
    	// cout << "st = " << st[i] << " ed[i] = " << ed[to[i]] << '\n';
    	// cout << "len = " << len << '\n';
    	if(len > mx){
    		mx = len;
    		if(add == -1){
    			ans = {st[i], ed[to[i]]};
    		}else{
    			ans = {st[i] - sidx, ed[to[i]] + pidx};
    		}
    	}
    }
    // cout << '\n';
    // cout << mx << '\n';
    // cout << ans[0] << ' ' << ans[1] << '\n';
    for(int i = ans[0]; i <= ans[1]; i ++){
    	cout << s[i];
    }
    cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}