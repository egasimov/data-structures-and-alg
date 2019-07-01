import time
def good_fibonacci(n):
    """ Return pair of Fibonacci numbers : F(n) and F(n-1) """
    if n<=1:
        return (n,0)
    else:
        (a,b)=good_fibonacci(n-1)
        return (a+b,a)


def bad_fibonacci(n):
    if(n<=1):
        return n
    else:
        return bad_fibonacci(n-1)+bad_fibonacci(n-2)

def iter_fibo(n):
    if(n<=2):
        return n
    x0=1
    x1=1
    while(n>2):
        x2=x0+x1
        x0=x1
        x1=x2
        n=n-1
    return x2

start=time.time()
print(iter_fibo(20))
print(-start+time.time())

start=time.time()
print(good_fibonacci(20))
print(-start+time.time())

start=time.time()
print(bad_fibonacci(20))
print(-start+time.time())




