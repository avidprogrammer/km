parens = [set([''])]

def get_parens(N):
  global parens

  if len(parens) > N:
    return parens[N]
  
  prev_parens = get_parens(N-1)
  this_parens = set()
  for comb in prev_parens:
    this_parens.add('(%s)'%comb)
    this_parens.add('()%s'%comb)
    this_parens.add('%s()'%comb)
  parens.append(this_parens)
  return this_parens

p0 = get_parens(0)
e0 = set([''])
assert((p0 - e0) == set())

p1 = get_parens(1)
e1 = set(['()'])

p2 = get_parens(2)
e2 = set(['(())', '()()'])
assert((p2 - e2) == set())
 

print get_parens(3)
print get_parens(4) 
