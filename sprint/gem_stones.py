def get_gems():
    N = int(raw_input())
    gems = set([c for c in raw_input()])
    for i in range(N-1):
        gems = gems.intersection([c for c in raw_input()])
    return len(gems)

print get_gems()
