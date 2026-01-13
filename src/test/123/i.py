n, x = map(int, input().split())
ans = 0
while x > 0:
    ans += 1
    k = n // 4
    if n % 4 >= 2:
        k += 1
    k = min(2 * k, n - 2 * k)
    n -= k
    x -= k
    if k == 0:
        break
print(ans)