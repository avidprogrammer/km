"""
Kadane's Algorithm
Find the subarray with the largest sum
"""
import random
TOTAL_ELEMENTS = 10

arr = [random.randint(-10, 10) for x in range(0, TOTAL_ELEMENTS)]
def main():
    maxstartidx, maxendidx = 0, 1
    curstartidx = 0
    maxsofar = arr[0]
    maxendhere = arr[0]
    for i in range(0, TOTAL_ELEMENTS):
        print arr[i]
    for i in range(1, TOTAL_ELEMENTS):
        maxendhere = max(arr[i], maxendhere +arr[i])
        maxsofar =  max(maxendhere, maxsofar)
        if maxendhere == arr[i]:
            curstartidx = i
        if maxsofar == maxendhere:
            maxendidx = i
            maxstartidx = curstartidx
    print "STARTIDX %d ENDIDX %d max %d"%(maxstartidx+1, maxendidx+1, maxsofar)

if __name__ == '__main__':
    main()
