lnks = []
wt = []
node_wt = []

def dfs(root):
    global node_wt
    to_visit = [root]
    node_wt = [0] * (N+1)
    ord_stck = []
    visited = [0] * (N+1)

    # build stack
    while to_visit:
        this_node = to_visit[-1]
        if visited[this_node]:
            ord_stck.append(to_visit.pop())
            continue 
        visited[this_node] = 1
        to_visit += [lnk for lnk in lnks[this_node] if not visited[lnk]]
               
    #compute weights
    for this_node in ord_stck:
        node_wt[this_node] = wt[this_node-1]
        for lnk in lnks[this_node]:
            node_wt[this_node] += node_wt[lnk]
            
def cut_the_tree():
    global lnks, wt, N
    
    N = int(raw_input())
    wt = map(int, raw_input().split())
    tot_wt = sum(wt)
    lnks = [set() for i in range(N+1)]

    for e in range(N-1):
        a,b = map(int, raw_input().split())
        lnks[a].add(b)
        lnks[b].add(a)
    
    cand = 0
    for lnk in lnks:
        if len(lnk) > 1:
            break
        cand += 1
    dfs(cand)
    
    min_diff = min([abs(tot_wt - nw*2) for nw in node_wt])
    return min_diff                
    
print cut_the_tree()
