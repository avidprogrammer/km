def solution(A):
    leader = A[0]
    cur_ldr_cnt = 1
    tot_ldr_cnt, ldr_cnt = 0, 0
    arrlen = len(A)
    eq_ldr = 0
    
    for ele in A[1:]:
        if ele != leader:
            cur_ldr_cnt -= 1
        else:
            cur_ldr_cnt += 1
        if not cur_ldr_cnt:
            cur_ldr_cnt = 1
            leader = ele
    
    tot_ldr_cnt = A.count(leader)
    if tot_ldr_cnt <= len(A)/2:
        return 0

    ldr_cnt = 0
    for idx, ele in enumerate(A):
        if ele == leader:
            ldr_cnt += 1
        if ldr_cnt > (idx+1)/2 and \
           ((tot_ldr_cnt - ldr_cnt) > (arrlen - idx - 1)/2):
            eq_ldr += 1
    
    return eq_ldr
