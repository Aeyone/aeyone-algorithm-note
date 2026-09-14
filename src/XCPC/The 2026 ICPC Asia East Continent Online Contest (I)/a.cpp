#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve () {
	int n;
	cin>>n;
	string s(n,'0');
	vector<int>a(n);

	set<array<int,2>>st1,st2;
	map<int,int>la;
	vector<int>cnt(n);
	for(int i = 0;i<n;i++){
		cin>>s[i];
		cin>>a[i];
		if(s[i] == '+'){
			if(la.find(a[i])==la.end()){
				st1.insert({i,a[i]});
				st2.insert({i,a[i]});
				la[a[i]] = i;
			}
			else{
				int idx = la[a[i]];
				if(st2.find({idx,a[i]})!=st2.end()){
					cnt[idx]++;
					st1.erase({idx,a[i]});
					st2.erase({idx,a[i]});
					la.erase(a[i]);
				}
				else{
					int t = -1,sum = 0;
					while(1){
						auto &[aa,b] = *st1.rbegin();
						t = max(t,la[b]);
						sum++;
						st1.erase({aa,b});
						if(st2.find({aa,b})!=st2.end())st2.erase({aa,b});
						la.erase(b);
						if(b==a[i])break;
					}
					cnt[t]+=sum;
				}
				st1.insert({i,a[i]});
				st2.insert({i,a[i]});
				la[a[i]] = i;
			}
		}

		if(s[i] == 'T'){
			int idx = la[a[i]];
			if(st2.find({idx,a[i]})!=st2.end()){
				st2.erase({idx,a[i]});
			}
			la[a[i]] = i;
		}
		if(s[i] == 'F'){
			if(la.find(a[i])==la.end()){
				continue;
			}
			int idx = la[a[i]];
			// cerr << "idx = " << idx << '\n';

			if(st2.find({idx,a[i]})!=st2.end()){
				st2.erase({idx,a[i]});
				st1.erase({idx,a[i]});
				cnt[idx]++;
				la.erase(a[i]);
			}
			else {
				int t = -1,sum = 0;
				while(1){
					auto &[aa,b] = *st1.rbegin();
					t = max(t,la[b]);
					sum++;
					st1.erase({aa,b});
					if(st2.find({aa,b})!=st2.end())st2.erase({aa,b});
					la.erase(b);
					if(b==a[i])break;
				}
				cnt[t]+=sum;
			}
		}
	}

	string ans;
	for(int i = 0;i<n;i++){
		// cerr << cnt[i] << ' ';
		if(s[i]=='T'||s[i]=='F')ans+='?';
		else ans+=s[i];
		ans+=string(cnt[i],'-');
	}
	ans += string(st1.size(), '-');
	
	cout<<ans<<"\n";

	vector<int> stt;
	int cur = 0;
	for(int i = 0;i<n;i++){
		char c = s[i];
		if(c=='+'){
			for(auto x:stt){
				if(x==a[i]){
					cout<<"NO\n";
					return;
				}
			}
			stt.push_back(a[i]);
		}

		if(c=='T'){
			bool ok = 0;
			for(auto x:stt){
				ok |= x==a[i];
			}
			if(!ok){
				cout<<"NO2"<<"\n";
				return;
			}

		}

		if(c=='F'){
			for(auto x:stt){
				if(x==a[i]){
					cout<<"NO3\n";
					return;
				}
			}
		}
		while(cnt[i]--){
			if(stt.empty()){
				cout<<"NO"<<"\n";
				return;
			}
			stt.pop_back();
		}
	}
	cout<<"YES\n";
}

signed main () {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}