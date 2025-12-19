# 算法竞赛学习记录

用于个人日常学习记录，主要维护模板和做题笔记

<!-- TEMPLATE_START -->
## Template

<details open>
<summary><strong>一些杂碎</strong></summary>

- [01--main.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/01--main.txt)
- [02--一些小trick.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/02--一些小trick.txt)
- [03--进制转换.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/03--进制转换.txt)
- [04--重载输出运算符(int128).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/一些杂碎/04--重载输出运算符(int128).txt)

</details>

<details open>
<summary><strong>字符串</strong></summary>

- [01--kmp.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/字符串/01--kmp.txt)

</details>

<details open>
<summary><strong>数学</strong></summary>

- [01--快速幂.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/01--快速幂.txt)
- [02--组合计数.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/02--组合计数.txt)
- [03--线性筛.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/03--线性筛.txt)
- [04--计算几何.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/04--计算几何.txt)
- [05--多项式乘法(NTT).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/05--多项式乘法(NTT).txt)
- [06--米勒罗宾判断素数.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数学/06--米勒罗宾判断素数.txt)

</details>

<details open>
<summary><strong>数据结构</strong></summary>

- [01--DSU.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/01--DSU.txt)
- [02--普通莫队.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/02--普通莫队.txt)
- [03--FenwickTree.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/03--FenwickTree.txt)
- [04--SparseTable.txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/04--SparseTable.txt)
- [05A--懒标记线段树(基础区间修改).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05A--懒标记线段树(基础区间修改).txt)
- [05B--懒标记线段树(区间赋值+区间修改).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05B--懒标记线段树(区间赋值+区间修改).txt)
- [05C--懒标记线段树(动态开点+区间修改).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05C--懒标记线段树(动态开点+区间修改).txt)
- [05D--线段树(区间合并，无modify).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05D--线段树(区间合并，无modify).txt)
- [05E1--吉如一线段树(区间求和).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05E1--吉如一线段树(区间求和).txt)
- [05E2--吉如一线段树(区间求和+区间历史最值).txt](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/Template/数据结构/05E2--吉如一线段树(区间求和+区间历史最值).txt)

</details>

<!-- TEMPLATE_END -->

<!--

https://github.com/Aeyone/aeyone-algorithm-note/blob/main/

-->

## Problemset

#### 基础算法

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
|cf*1600|[CF1623C](https://codeforces.com/contest/1623/problem/C)	|二分+一点DP思想|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/09.22/c.cpp)|
|cf*1600|[CF1680C](https://codeforces.com/contest/1680/problem/C)	|二分 n*n优化至nlogn|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/09.23/b.cpp)|
|cf*1700|[CF1343D](https://codeforces.com/contest/1343/problem/D)	|枚举+二分 需要动点脑子|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.22-10.24/1343D.cpp)|
||
|cf*1700|[CF1381A2](https://codeforces.com/contest/1381/problem/A2)	|双指针|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.27/1381A2.cpp)|
|cf*1800|[CF1734D](https://codeforces.com/contest/1734/problem/D)	|高难度双指针|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.29/1734d.cpp)|
|cf*1800|[CF1979D](https://codeforces.com/contest/1979/problem/D)	|双指针+贪心(假的*1800)|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.17/a.cpp)|
|cf*1800|[CF1852B](https://codeforces.com/contest/1852/problem/B)	|双指针 细节要考虑清楚 洛谷评蓝 确实有点难度|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.19/a.cpp)|
||
|atc*100|[ABC433_B](https://atcoder.jp/contests/abc433/tasks/abc433_b)	|最基本的单调栈用法|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/AtCoder/abc433/b.cpp)|
|cf*1800|[CF1845D](https://codeforces.com/contest/1845/problem/D)	|单调栈好题 有点挑战性|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.15/c.cpp)|
||
|cf*1800|[CF1801B](https://codeforces.com/contest/1801/problem/B)	|有趣贪心|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/12.17/d.cpp)|


#### 动态规划

|Difficulty| Problem | Note | Code |
|----------| -------- | ---- | ---- |
|cf*1700|[CF1625C](https://codeforces.com/problemset/problem/1625/C)|很好的一道线性dp，考虑删除与不删除，详解看code|[Accept Code](https://github.com/Aeyone/aeyone-algorithm-note/blob/main/src/Training/10.12/a.cpp)|
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