def make_change(coins, n):
  table = [0] *(n+1)
  table[0] = 1
  
  for c in coins:
    for val in range(c, n+1):
      table[val] += table[val-c]

  print table
  return table[n]

assert make_change([1,5,10,25], 16)   == 6
