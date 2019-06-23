def intersectionMax(a, b):
    res = list()
    for i in range(len(a)):
        res.append(min(a[i][1], b[i][1]))
    return res


def unionMax(a, b):
    res = list()
    for i in range(len(a)):
        res.append(max(a[i][1], b[i][1]))
    return res


def intersectionAlg(a, b):
    res = list()
    for i in range(len(a)):
        res.append(round(a[i][1] * b[i][1], 2))
    return res


def unionAlg(a, b):
    res = list()
    for i in range(len(a)):
        res.append(round(((a[i][1] + b[i][1]) - (a[i][1] * b[i][1])), 2))
    return res


def intersectionOgr(a, b):
    res = list()
    for i in range(len(a)):
        res.append(max(0, a[i][1] + b[i][1] - 1))
    return res

def unionOgr(a, b):
    res = list()
    for i in range(len(a)):
        res.append(min(1, a[i][1] + b[i][1]))
    return res


def carrier(a):
    res = list()
    for i in range(len(a)):
        if a[i][1] > 0:
            res.append(a[i][0])
    return res


def cardA(a):
    res = 0
    for i in range(len(a)):
        res += a[i][1]
    return res


def h(a):
    return max(a[i][1] for i in range(len(a)))


def slice(a, alpha):
    return [a[i][1] > alpha for i in range(len(a))]


def dlc(a):
    return [1 - a[i][1] for i in range(len(a))]


def processing():
    print('Input dimension')
    n = int(input())
    a = list()
    b = list()
    print('Input first set')
    for i in range(n):
        el, val = input().split()
        a.append((int(el), float(val)))
    # print('Input second set')
    # for i in range(n):
    #     el, val = input().split()
    #     b.append((int(el), float(val)))

    # print(*intersectionMax(a, b))
    # print(*intersectionAlg(a, b))
    # print(*intersectionOgr(a, b))
    print(dlc(a))
    print(cardA(a))
    print(h(a))



processing()