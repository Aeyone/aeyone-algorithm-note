#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    // 输入文件
    int n = inf.readInt(1, 18, "n");

    int N = 1 << n;
    int len = 2 * N;

    vector<int> a(len);

    // 读取选手输出
    for(int i = 0; i < len; i++) {
        a[i] = ouf.readInt(0, N-1, "a[i]");
    }

    if (!ouf.seekEof()){    
        quitf(_pe, "Extra data in output");
    }

    // 检查双排列（每个数出现两次）
    vector<int> cnt(N, 0);
    for(int x : a) cnt[x]++;

    for(int i = 0; i < N; i++) {
        if(cnt[i] != 2)
            quitf(_wa,
                  "value %d appears %d times (expected 2)",
                  i, cnt[i]);
    }

    // 计算 xor 和
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        sum += (a[2*i] ^ a[2*i+1]);
    }

    long long need = 1LL << (2*n-1);

    if(sum != need) {
        quitf(_wa,
              "xor sum = %lld, expected %lld",
              sum, need);
    }

    quitf(_ok, "correct construction");
}