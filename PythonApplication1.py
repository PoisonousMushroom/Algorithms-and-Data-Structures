import time
from math import sqrt

def exponential(n):
    if n==1:
        return 0
    if n==2:
        return 1
    return exponential(n-2) +exponential(n-1) 

def linear(n):
    if n==1:
        return 0
    else :
        if n==2:
            return 1
        else:
            prev=0
            current=1
            i=1
            while i<n-1:
                next=current+prev
                prev=current
                current=next
                i+=1
            return current

def inexact(n):
    q=1.61803
    return round(pow(q,n-1)/sqrt(5))

def largestn():
    #check for exponential
    n=1
    while True:
        start=time.time()
        exponential(n)
        stop=time.time()
        if stop-start>10:
            break
        else:
            n+=1
        print("The exponential algorithm can print ",n," Fibonacci numbers")
    #check for inexact
    n=1
    while True:
        if inexact(n)!=linear(n):
            print(inexact(n))
            print(linear(n))
            break
        else:
            print("The ",n,"th value is printed")
            n+=1
    print("The inexact algorithm's first wrong value is ",n)
    #check for linear
    n=1
    while True:
       start=time.time()
       linear(n)
       stop=time.time()
       if stop-start>10:
          break
       else:
          n+=1
       print("The linear algorithm can print ",n," Fibonacci numbers")
    
largestn()   