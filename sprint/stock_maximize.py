def maximize():
    N = int(raw_input())
    max_so_far = [0]*(N+1)
    profit = 0
    prices = map(int, raw_input().split())
    
    for idx in range(N-1, -1, -1):
        max_so_far[idx] = max(prices[idx], max_so_far[idx+1])
    
    for idx, p in enumerate(prices):
        profit += max_so_far[idx] - p
    
    print profit   

T = int(raw_input())
for i in range(T):
    maximize()
