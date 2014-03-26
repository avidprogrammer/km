OPEN = '('
CLOS = ')'

def solution(S):
    cnt = 0
    for brack in S:
        if brack == OPEN:
            cnt += 1
        else:
          cnt -= 1
        if cnt < 0:
            break            
            
    return int(cnt == 0)

