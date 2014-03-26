def fish_fight(fish, down_stck, up_stck):
    for dfish in reversed(down_stck):
        if fish > dfish:
            down_stck.pop()
        else:
            break
    if down_stck:
        up_stck.pop()
    return down_stck, up_stck        
    
def solution(A, B):
    up_stck = []
    down_stck = []
    for idx, fish in enumerate(A):
        if B[idx]:
            # downstream
            down_stck.append(fish)
        else:
            # upstream
            up_stck.append(fish)
            down_stck, up_stck = fish_fight(fish, down_stck, up_stck)
    return len(up_stck) + len(down_stck)

