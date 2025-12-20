# 算法竞赛学习记录

用于个人日常学习记录，主要维护模板和做题笔记

<!-- TEMPLATE_START -->
## Template

<details open>
<summary><strong>一些杂碎</strong></summary>

- [01 - main.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/01%20-%20main.txt)
- [02 - 一些小trick.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/02%20-%20一些小trick.txt)
- [03 - 进制转换.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/03%20-%20进制转换.txt)
- [04 - int128 输出流自定义.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/04%20-%20int128%20输出流自定义.txt)

</details>

<details open>
<summary><strong>字符串</strong></summary>

- [01 - kmp.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/字符串/01%20-%20kmp.txt)

</details>

<details open>
<summary><strong>数学</strong></summary>

- [01 - 快速幂.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/01%20-%20快速幂.txt)
- [02 - 组合计数.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/02%20-%20组合计数.txt)
- [03 - 线性筛.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/03%20-%20线性筛.txt)
- [04 - 计算几何.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/04%20-%20计算几何.txt)
- [05 - 多项式乘法（NTT）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/05%20-%20多项式乘法（NTT）.txt)
- [06 - 米勒-罗宾素数检验（Miller–Rabin）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/06%20-%20米勒-罗宾素数检验（Miller–Rabin）.txt)

</details>

<details open>
<summary><strong>数据结构</strong></summary>

- [01 - 并查集（DSU）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/01%20-%20并查集（DSU）.txt)
- [02 - 普通莫队.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/02%20-%20普通莫队.txt)
- [03 - 树状数组（FenwickTree）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/03%20-%20树状数组（FenwickTree）.txt)
- [04 - ST表（SparseTable）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/04%20-%20ST表（SparseTable）.txt)
- [05 - 线段树（区间合并，不带修）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05%20-%20线段树（区间合并，不带修）.txt)
- [06A - 懒标记线段树（基础区间操作）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/06A%20-%20懒标记线段树（基础区间操作）.txt)
- [06B - 懒标记线段树（双重区间操作）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/06B%20-%20懒标记线段树（双重区间操作）.txt)
- [06C - 懒标记线段树（动态开点+区间操作）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/06C%20-%20懒标记线段树（动态开点+区间操作）.txt)
- [07A - 吉如一线段树（区间求和）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/07A%20-%20吉如一线段树（区间求和）.txt)
- [07B - 吉如一线段树（区间求和+区间历史最值）.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/07B%20-%20吉如一线段树（区间求和+区间历史最值）.txt)
- [07C - 吉如一线段树（区间求和+区间历史最值） (副本).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/07C%20-%20吉如一线段树（区间求和+区间历史最值）%20(副本).txt)

</details>

<!-- TEMPLATE_END -->

<!--

https://github.com/Aeyone/aeyone-algorithm-note/blob/main/

-->

## Problemset

#### 基础算法

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
|cf*1600|[Balanced Stone Heaps](https://codeforces.com/contest/1623/problem/C)|二分+一点DP思想|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/09.22/c.cpp)|
|cf*1600|[Binary String](https://codeforces.com/contest/1680/problem/C)|二分 n*n优化至nlogn|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/09.23/b.cpp)|
|cf*1700|[Constant Palindrome Sum](https://codeforces.com/contest/1343/problem/D)|枚举+二分 需要动点脑子|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.22-10.24/1343D.cpp)|
||
|cf*1700|[Prefix Flip (Hard Version)](https://codeforces.com/contest/1381/problem/A2)|双指针|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.27/1381A2.cpp)|
|cf*1800|[Slime Escape](https://codeforces.com/contest/1734/problem/D)|高难度双指针|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.29/1734d.cpp)|
|cf*1800|[Fixing a Binary String](https://codeforces.com/contest/1979/problem/D)|双指针+贪心，循环位移经典Trick|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.17/a.cpp)|
|cf*1800|[Imbalanced Arrays](https://codeforces.com/contest/1852/problem/B)|双指针 细节要考虑清楚 洛谷评蓝 确实有点难度|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.19/a.cpp)|
||
|atc*100|[Nearest Taller](https://atcoder.jp/contests/abc433/tasks/abc433_b)|最基本的单调栈用法|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/AtCoder/abc433/b.cpp)|
|cf*1800|[Rating System](https://codeforces.com/contest/1845/problem/D)|单调栈好题 有点挑战性|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.15/c.cpp)|
||
|cf*1800|[Buying gifts](https://codeforces.com/contest/1801/problem/B)|有趣贪心|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.17/d.cpp)|


#### 动态规划

|Difficulty| Problem | Note | Code |
|----------| --------| ---- | ---- |
|atc*719|[Robot Customize](https://atcoder.jp/contests/abc431/tasks/abc431_d)|简单背包DP，带一点条件的转移|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/11.28/a.cpp)|
|cf*1700|[Sleeping Schedule](https://codeforces.com/contest/1324/problem/E)|DP练手题，背包计数|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.22-10.24/1324E.cpp)|
|cf*1700|[Road Optimization](https://codeforces.com/problemset/problem/1625/C)|很典，详解看code|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.12/a.cpp)|
|cf*1600|[Good Triples](https://codeforces.com/contest/1907/problem/E)|数学+背包DP|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.03/a.cpp)|
|cf*1800|[Attribute Checks](https://codeforces.com/contest/2025/problem/D)|本质背包DP，也是通过不同选择线性递推|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/08.03/a.cpp)|
|cf*1600|[Good Key, Bad Key](https://codeforces.com/contest/1703/problem/G)|考虑势能分析，最多除2除30下，在此基础上进行DP|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/09.22/e.cpp)|
|atc*1694|[Shortest One Formula](https://atcoder.jp/contests/abc403/tasks/abc403_f)|难点在于想到使用DP解决这个问题，状态转移本身不难|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.12/f.cpp)|
|cf*1600|[Array Walk](https://codeforces.com/contest/1389/problem/B)|线性DP，细节处理要仔细分析|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/11.29/c.cpp)|
|cf*1700|[Minimizing the Sum](https://codeforces.com/contest/1969/problem/C)|很有难度的一道DP，状态转移非常关键|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/11.29/d.cpp)|
||
|cf*1700|[Consecutive Subsequence](https://codeforces.com/contest/977/problem/F)|构造+经典LIS问题变形|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.27/977F.cpp)|
||
|cf*1800|[The Sports Festival](https://codeforces.com/contest/1509/problem/C)|很普通的区间DP|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/11.11/1509C.cpp)|
||
|cf*1600|[Parsa's Humongous Tree](https://codeforces.com/contest/1528/problem/A)|树形DP+贪心（只考虑上界和下界）|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/11.27/a.cpp)|
|cf*1700|[Substring](https://codeforces.com/contest/919/problem/D)|有向图上DP，很典|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.30/919D.cpp)|
|easy|[AVL tree](https://ac.nowcoder.com/acm/contest/108306/A)|树形DP+AVL树的性质（2025牛客暑期多校训练营9）|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/NowCoder/2025牛客暑期多校训练营9/a.cpp)|
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|
||
|easy|[Not a subset sum](https://qoj.ac/contest/2645/problem/15317)|状压DP，想到转移就很好做了（2025上海区域赛D）|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/XCPC/The%202025%20ICPC%20Asia%20Shanghai%20Regional%20Contest/d.cpp)|
|atc*1752|[Inserting Process](https://atcoder.jp/contests/abc425/tasks/abc425_f)|状压DP，和上题类似，难点在于处理相邻位置相同时的条件转移|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.02/c.cpp)|
|atc*1229|[2x2 Erasing 2](https://atcoder.jp/contests/abc424/tasks/abc424_d)|简单状压DP|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.02/d.cpp)|
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|

#### 数据结构

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|

#### 数学

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|

#### 图论

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|

#### 字符串

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|
||[]()||[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/)|