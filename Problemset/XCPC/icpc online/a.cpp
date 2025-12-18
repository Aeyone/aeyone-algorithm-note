#include <bits/stdc++.h>
using namespace std;

struct Msg{
	string name, st;
	char plm;
	int time;
};

bool cmp(Msg &a, Msg &b){
	return (a.time < b.time);
}

void solve(){
	int n;
	cin >> n;
	vector<Msg> tot, unk;
	int idx = 0;
	map<string, int> mp;
	for(int i = 0; i < n; i ++){
		string name, st;
		char plm;
		int time;
		cin >> name >> plm >> time >> st;

		if(mp.find(name) == mp.end())
			mp[name] = idx ++;

		Msg	tmp;
		tmp.name = name;
		tmp.st = st;
		tmp.plm = plm;
		tmp.time = time;

		if(st == "Unknown"){
			unk.push_back(tmp);
		}else{
			tot.push_back(tmp);
		}
	}
	vector<string> getName(idx + 10);
	for(auto [s, i] : mp)
		getName[i] = s;
	
	sort(tot.begin(), tot.end(), cmp);
	sort(unk.begin(), unk.end(), cmp);

	vector<vector<array<int, 2>>> g(idx + 10, vector<array<int, 2>>(30));
	for(int i = 0; i < (int)tot.size(); i ++){
		auto tmp = tot[i]; 
		int id = mp[tmp.name];
		int pid = tmp.plm - 'A';

		if(g[id][pid][1] == 1)
			continue;

		if(tmp.st == "Rejected")
			g[id][pid][0] += 20;
		else{
			g[id][pid][0] += tmp.time;
			g[id][pid][1] = 1;
		}
	}

	int MxCnt = 0, Mxtime = 0;
	for(int i = 0; i < idx; i ++){
		int cnt = 0, time = 0;
		for(int j = 0; j < 26; j ++){
			if(g[i][j][1] == 1)
				cnt ++, time += g[i][j][0];
		}
		if(cnt > MxCnt || (cnt == MxCnt && time <= Mxtime))
			MxCnt = cnt, Mxtime = time;
	}
	vector<string> res;

	for(int i = 0; i < (int)unk.size(); i ++){
		auto tmp = unk[i];

		int id = mp[tmp.name];
		int pid = tmp.plm - 'A';

		if(g[id][pid][1] == 1)
			continue;

		g[id][pid][0] += tmp.time;
		g[id][pid][1] = 1;
	}
	
	for(int i = 0; i < idx; i ++){
		int cnt = 0, time = 0;
		for(int j = 0; j < 26; j ++){
			if(g[i][j][1] == 1)
				cnt ++, time += g[i][j][0];
		}
		// cout << "name = " << getName[i] << " cnt = " << cnt << " time = " << time << '\n';

		if(cnt > MxCnt || (cnt == MxCnt && time <= Mxtime))
			res.push_back(getName[i]);
	}

	sort(res.begin(), res.end());
	for(auto s : res)
		cout << s << ' ';
	cout << '\n';
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while(_ --)
		solve();
}