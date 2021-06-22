def fact(n):
    print(f'Calling fact({n})')
    if n == 1:
        return 1
    else:
        return fact(n - 1) * n

n = 100
print(f'The factorial of {n} is {fact(n)}')
