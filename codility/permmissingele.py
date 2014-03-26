def solution(A):
    N = len(A)
    exp_sum = (N+1)*(N+2)/2
    act_sum = sum(A)
    return exp_sum - act_sum

