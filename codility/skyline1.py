def add_to_stack(stack, h, blks):
    stack.append(h)
    blks += 1
    return stack, blks


def solution(H):
    blks = 1
    stack = [H[0]]
    for h in H[1:]:
        if h == stack[-1]:
            continue
        elif h < stack[-1]:
            while stack and h < stack[-1]:
                stack.pop()
            if not stack:
                stack, blks = add_to_stack(stack, h, blks)
            elif h == stack[-1]:
                continue
            else:
                stack, blks = add_to_stack(stack, h, blks)
        else:
            stack, blks = add_to_stack(stack, h, blks)
                
    return blks      

