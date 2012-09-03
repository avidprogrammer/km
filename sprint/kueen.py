"""
A solution to the classic NQueens problem with an additional constraint -
Queens can also move like a knight.
"""
from itertools import permutations

def create_tuples(comb):
    tup = []
    for i, ele in enumerate(comb[:-1]):
        diff = abs(ele - comb[i+1])
        if diff in [1,2]:
            return [] 
    for i, ele in enumerate(comb):
        tup.append((i+1, ele))
    return tup

def test_tup(tup):
    for ref_pos in tup:
        for next_pos in tup :
            if next_pos == ref_pos:
                continue
            row_diff = abs(ref_pos[0] - next_pos[0])
            col_diff = abs(ref_pos[1] - next_pos[1])
        temp_t = (row_diff, col_diff)
        if temp_t in [(2,1), (1,2)] or row_diff == 0 or col_diff == 0 \
           or row_diff == col_diff:
            return False
    return True

def main():
    N = 0
    while (N < 1):
        N = raw_input('Enter positive N or type y to quit : ')
        if N == 'y':
            return
        else:
            N = int(N)
    gen = permutations(range(N), N)
    for comb in gen:
        tup = create_tuples(comb)
        if tup and test_tup(tup):
            print '\n', N
            str = ''
            for ele in comb:
                str += '%s '%ele
            print str 
            return

if __name__ == '__main__':
    main()
