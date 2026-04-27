# Sum and Product

## 目录
1. [题面翻译](#problem-translation)
2. [核心结论](#core-conclusion)
3. [DFS 在做什么](#dfs-meaning)
4. [几个易疑惑点](#faq)
5. [复杂度](#complexity)

<a id="problem-translation"></a>
## 题面翻译

定义 $f(n,k)$ 为满足下列条件的整数对 $(a,b)$ 的个数：
- $0 \le a,b < n$
- $k(a+b) \equiv ab \pmod n$

给定 $n,m$，求

$$
\sum_{k=0}^{m} f(n,k)
$$

答案对 $998244353$ 取模。

输入限制：
- $1 \le T \le 10^4$
- $1 \le n \le 10^{14}$
- $0 \le m < n$
- $n > 10^8$ 的测试组最多只有 $10$ 组

输出：每组输出一行答案。

<a id="core-conclusion"></a>
## 核心结论

原式可改写为

$$
(a-k)(b-k) \equiv k^2 \pmod n
$$

最终答案是

$$
\sum_{k=0}^{m} f(n,k)
=
\sum_{d \mid n} d \cdot \varphi\!\left(\frac{n}{d}\right) \cdot \left(\left\lfloor \frac{m}{g(d)} \right\rfloor + 1\right)
$$

其中 $g(d)=\prod_{p^e \parallel d} p^{\lceil e/2 \rceil}$，表示满足 $d \mid x^2$ 的最小正整数 $x$。所以本题本质上就是：枚举 $n$ 的每个约数 $d$，计算它的贡献。

<a id="dfs-meaning"></a>
## DFS 在做什么

若 $n=\prod p_t^{a_t},\ d=\prod p_t^{i_t}$，那么 DFS 的每一层就是给一个质因子 $p_t$ 选择指数 $i_t \in [0,a_t]$。所有层选完后，就得到一个完整约数 $d$。因此这个 DFS 本质上就是：暴力枚举 $n$ 的所有约数。

代码里同时维护：
- $d=\prod p_t^{i_t}$
- $\phi_{nd}=\varphi\!\left(\frac{n}{d}\right)=\prod \varphi(p_t^{a_t-i_t})$
- $g_d=g(d)=\prod p_t^{\lceil i_t/2 \rceil}$

它们能一起维护，是因为这三个量都能按“每个质因子各贡献一项，最后整体相乘”的方式拆开。

到叶子时直接累加

$$
d \cdot \phi_{nd} \cdot \left(\left\lfloor \frac{m}{g_d} \right\rfloor + 1\right)
$$

### 枚举顺序

它不是按约数大小枚举，而是按“质因子顺序 + 每层指数从小到大 + DFS”枚举。

例如 $12=2^2 \cdot 3^1$ 时，指数顺序是 $(0,0),(0,1),(1,0),(1,1),(2,0),(2,1)$，对应约数顺序是 $1,3,2,6,4,12$，不是从小到大。

<a id="faq"></a>
## 几个易疑惑点

1. `\#\{...\}` 表示集合元素个数。  
   例如 $\#\{k \in [0,m] \mid d \mid k^2\}$ 表示满足条件的 $k$ 有多少个。

2. 为什么有 $\left\lfloor \frac{m}{g(d)} \right\rfloor + 1$？  
   因为 $d \mid k^2 \iff g(d) \mid k$，而区间 $[0,m]$ 中按 $g(d)$ 的倍数计数，并且要把 $k=0$ 算进去。

3. 为什么 `cur_g` 只在奇数次时乘一个 $p$？  
   因为 $\lceil 0/2 \rceil,\lceil 1/2 \rceil,\lceil 2/2 \rceil,\lceil 3/2 \rceil,\dots$ 的变化是 $0,1,1,2,\dots$。

4. 为什么可以一边 DFS 一边算答案？  
   因为每个叶子对应唯一一个约数 $d$，而它的贡献已经完全由 $d,\phi_{nd},g_d$ 决定。

5. 这份代码不是在搜索复杂结构，它只是用 DFS 这种写法枚举所有约数。

<a id="complexity"></a>
## 复杂度

- 试除分解：$O(\sqrt{n})$
- DFS 枚举约数：$O(\tau(n))$

总复杂度：

$$
O(\sqrt{n}+\tau(n))
$$

其中 $\tau(n)$ 是约数个数。
