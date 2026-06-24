# 排列移动

## 目录

- [题意](#statement)
- [RE 原因](#re)
- [核心结论](#core)
- [环上做法](#cycle)
- [复杂度](#complexity)

<a id="statement"></a>
## 题意

给定一个排列 `P`。每次操作同时把每个位置更新为：

$$
P_i \leftarrow P_{P_i}
$$

求进行 `K` 次操作后的排列。

<a id="re"></a>
## RE 原因

原代码有两个高危点。

第一处：

```cpp
vis.assign(n, 0);
```

这会把 `vis` 改成长度为 `n`，合法下标是 `0..n-1`，但后面仍然访问 `vis[1..n]`，所以 `vis[n]` 越界。

第二处：

```cpp
int d = (1ll << to) % siz;
```

当 `to >= 63` 时，左移会产生未定义行为，可能 RE，也可能 WA。

<a id="core"></a>
## 核心结论

把排列看成函数。一次操作是：

$$
P \leftarrow P \circ P
$$

所以：

- 第 `1` 次操作后是 $P^2$。
- 第 `2` 次操作后是 $P^4$。
- 第 `3` 次操作后是 $P^8$。

进行 `K` 次后，结果是：

$$
P^{2^K}
$$

<a id="cycle"></a>
## 环上做法

排列由若干个环组成。

如果某个环长度是 `len`，在这个环上原排列相当于每次向后走 `1` 步。

进行 `K` 次操作后，相当于每个点向后走：

$$
2^K \bmod len
$$

步。

所以对每个环：

```cpp
int step = qpow_mod(2, k, len);
ans[cyc[j]] = cyc[(j + step) % len];
```

<a id="complexity"></a>
## 复杂度

每个点只进一次环分解，快速幂每个环 $O(\log K)$。总复杂度 $O(n \log K)$，空间复杂度 $O(n)$。
