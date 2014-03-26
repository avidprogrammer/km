def solution(A):
    passing_cars = 0
    lenA = len(A)
    west_cars = [0] *len(A)
    tot_west_cars = 0

    for idx in xrange(0, lenA):
        west_cars[idx] = west_cars[idx-1] + A[idx]
    
    tot_west_cars = west_cars[lenA - 1]

    for idx, ele in enumerate(A):
        if not ele:
            passing_cars += (tot_west_cars - west_cars[idx])
            
    if passing_cars > 1000000000:
        passing_cars =  -1
    
    return passing_cars

