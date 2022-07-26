def sieve(range_max):
    is_prime = [True] * range_max
    primes = []
    spf = [None] * range_max
    is_prime[0] = is_prime[1] = False
    for i in range(2, range_max):
        if is_prime[i]:
            primes.append(i)
            # A prime number is its own smallest prime factor
            spf[i] = i

        j = 0
        while j < len(primes) and i * primes[j] < range_max and primes[j] <= spf[i]:
            # This loop will only run once for even numbers.
            is_prime[i * primes[j]] = False
            spf[i * primes[j]] = primes[j]
            j += 1

    return primes


def main():
    x=int(input())
    print(sieve(x))


if __name__ == "__main__":
    main()