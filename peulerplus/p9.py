primes = {}
for m in range(2, 60):
    for n in range(1, m):
        a = m**2 - n**2
        b = 2*m*n
        c = m**2 + n**2
        mult = 1
        s = a + b +c
        while (s <= 3000):
            p = a*b*c*(mult**3)
            if not primes.get(s):
                primes[s] = 0
            if (primes[s] < p):
                primes[s] = p
            mult += 1
            s = a*mult+b*mult+c*mult

T = int(raw_input())            
for _ in xrange(T):
    N = int(raw_input())            
    if not primes.get(N):
        print -1
    else:
        print primes[N]
