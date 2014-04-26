def get_peaks(A):
    peaks = []
    for idx in xrange(1, len(A)-1):
        if (A[idx-1] < A[idx]) and (A[idx] > A[idx+1]):
            peaks.append(idx)
    return peaks
    
def blocks_contain_peaks(peaks, arr_len, mult):
    peak_idx = 0
    peak_len = len(peaks)
    for i in range(1, arr_len/mult):
        prod = mult * i
        cur_peak = peaks[peak_idx]
        if cur_peak >= prod:
            return False
        while peak_idx < peak_len and peaks[peak_idx] < prod:
            peak_idx += 1
        if peak_idx == peak_len:
            return False
    return True
    
def solution(A):
    peaks = get_peaks(A)
    arr_len = len(A)
    num_blocks = len(peaks)
    while (num_blocks):
        mult = arr_len/num_blocks
        divisible  = not(arr_len%num_blocks)
        if divisible and blocks_contain_peaks(peaks, arr_len, mult):
            break
        num_blocks -= 1
    return num_blocks
