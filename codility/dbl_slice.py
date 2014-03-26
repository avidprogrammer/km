def get_max_here(arr):
    lenArr = len(arr)
    max_fin_here = [0] * lenArr
    for idx in xrange(1, lenArr - 1):
        max_fin_here[idx] = max(0, max_fin_here[idx-1] + arr[idx])
    return max_fin_here

def solution(A):
    lenA = len(A)
    max_end_here = get_max_here(A)
    max_start_here = get_max_here(A[::-1])
    max_start_here.reverse()
    
    dbl_slice = 0
    for idx in range(0, lenA - 2):
        dbl_slice = max(dbl_slice, max_end_here[idx] + max_start_here[idx+2])

    return dbl_slice

