OPEN_BRACK = ['[', '{', '(']
CLOS_BRACK = [']', '}', ')']
C_PARAN_D = dict(zip(CLOS_BRACK, OPEN_BRACK))


def solution(S):
    brackets = []
    
    for c in S:
        if c in OPEN_BRACK:
            brackets.append(c)
        elif c in CLOS_BRACK:
            if not brackets or C_PARAN_D[c] != brackets[-1]:
                brackets.append(c)
                break
            else:
                brackets.pop()
            
    return int(not brackets)

