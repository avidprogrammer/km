def num_factors(num):
  factors = set([1, num])
  sqrt = int(num ** 0.5)
  for divisor in xrange(2, sqrt+1):
    if num % divisor == 0:
      factors.add(divisor)
      factors.add(num/divisor)
  return len(factors)

for N in range(1, 330):
  n = 2
  while(1):
    pynum = (n*(n+1))/2
    n += 1
    numf = num_factors(pynum)
    if numf > N:
      print pynum
      break
