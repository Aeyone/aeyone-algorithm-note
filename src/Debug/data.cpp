#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l,ll r){
    return uniform_int_distribution<ll>(l,r)(rng);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXSUM = 100000;

    int T = Rand(1,100000);
    cout << T << "\n";

    int used = 0;

    for(int t=0;t<T;t++){

        int remain = MAXSUM - used;

        if(remain <= 0){
            cout << 1 << "\n";
            cout << "1 1\n";
            continue;
        }

        int n = Rand(1, remain);
        used += n;

        cout << n << "\n";

        int type = Rand(1,4);

        for(int i=0;i<n;i++){

            ll u,d;

            if(type==1){
                // 完全随机
                u = Rand(1,1000000000);
                d = Rand(1,1000000000);
            }
            else if(type==2){
                // 上牙接近单调
                u = i + Rand(0,5);
                d = Rand(1,100000);
            }
            else if(type==3){
                // 大数
                u = Rand(1e9-1000,1e9);
                d = Rand(1e9-1000,1e9);
            }
            else{
                // 小范围
                u = Rand(1,50);
                d = Rand(1,50);
            }

            cout << u << " " << d << "\n";
        }
    }

    return 0;
}