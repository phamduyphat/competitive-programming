from asyncio.windows_events import NULL
import math

def factorization(base):
    res = []
    i = 2
    while i * i <= base:
        if base % i == 0:
            base = base // i
            res.append(i)
        else:
            i += 1
    if base > 1:
        res.append(base)
    return res

def finding_zero(input, base):
    factors = factorization(base)
    data = {}
    for factor in set(factors):
        temp = input
        res = 0
        while temp:
            temp = temp // factor
            res += temp
        data[factor] = res
    return min([data[factor] // factors.count(factor) for factor in set(factors)])

def main() -> None:
    num, base = [int(x) for x in input().split()]
    print(finding_zero(num, base))

if __name__ == "__main__":
    main()