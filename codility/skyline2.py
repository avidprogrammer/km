def add_to_stack(stack, h, blks):
    stack.append(h)
    blks += 1
    return stack, blks

def check_for_blk(stack, h, blks):
    if not stack:
        stack, blks = add_to_stack(stack, h, blks)     
    elif h < stack[-1]:
        stack.pop()
        stack, blks = check_for_blk(stack, h, blks)
    elif h > stack[-1]:
        stack, blks = add_to_stack(stack, h, blks)
    return stack, blks        
        
def solution(H):
    blks = 1
    stack = [H[0]]
    for h in H[1:]:
        stack, blks = check_for_blk(stack, h, blks)
    return blks                
    

