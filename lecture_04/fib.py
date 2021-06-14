def fib(n):
    print(f'Calling fib({n})')
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n - 1) + fib(n -2)

n = 4
print(f'fib({n}) = {fib(n)}')
