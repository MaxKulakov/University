import math

def y(x):
    return (x * x) + 3

def euler(x, y):
    return (-1 * x * x) + (2 * x) - (3 + y(x))


def solution():
    isEnd = None
    while (not isEnd):
        isEnd = True
        print("Input a")
        a = float(input())
        print("Input b")
        b = float(input())
        print("Input y0")
        y0 = float(input())
        print("Input n")
        n = float(input())
        h =(b - a) /n
        x = [n + 1]
        y = [n + 1]
        y_2 = [2 * (n + 1)]
        for xi in x:
            xi 
