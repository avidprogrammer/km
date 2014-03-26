class DStack(object):
    def __init__(self):
        self.elements = []
        
    def add(self, ele):
       if self.elements and self.elements[-1] != ele:
            self.elements.pop()
       else:
            self.elements.append(ele)
            
    def get_dom(self, threshold):
        if self.elements and len(self.elements) >= threshold:
            return self.elements[-1]
        return -1
    
def get_dom_threshold(A):
    len_a = len(A)
    if len_a % 2:
        return 1
    return 2
    
def solution(A):
    stck = DStack()
    dom, dom_idx = -1, -1
    for ele in A:
        stck.add(ele)  
    dom = stck.get_dom(get_dom_threshold(A))
    if dom != -1:
        dom_idx = A.index(dom)
    return dom_idx

test_arr1 = [1,2,2,3,3,3,4,4,4,4]
print solution(test_arr1)
