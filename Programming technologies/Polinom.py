from math import floor


class Polinom:
    # koeffs = list()

    def __init__(self, *args) -> None:
        self.koeffs = list()
        for arg in args:
            self.koeffs.append(arg)

    def __eq__(self, o: object) -> bool:
        if len(self.koeffs) > len(o.koeffs):
            return True
        elif len(self.koeffs) < len(o.koeffs):
            return False
        else:
            for i in range(len(self.koeffs)):
                if self.koeffs[i] != o.koeffs[i]:
                    return False
        return True

    def __ne__(self, o: object) -> bool:
        if len(self.koeffs) != len(o.koeffs):
            return True
        else:
            for i in range(len(self.koeffs)):
                if self.koeffs[i] != o.koeffs[i]:
                    return True
        return False

    def __add__(self, other):
        sum = list()
        l1 = len(self.koeffs)
        l2 = len(other.koeffs)
        if l1 > l2:
            for _ in range(l1 - l2):
                other.koeffs.append(0)
        else:
            for _ in range(l2 - l1):
                other.koeffs.append(0)
        for i in range(l1):
            sum.append(self.koeffs[i] + other.koeffs[i])
        return Polinom(*sum)

    def __neg__(self):
        neg = [-k for k in self.koeffs]
        return Polinom(*neg)

    def deg(self):
        return len(self.koeffs)

    def result(self, x):
        res = 0
        for i in range(len(self.koeffs)):
            res += self.koeffs[i] * x ** i
        return res

    def get10(self, value):
        if value > len(self.koeffs):
            return 'Deg is undefined'
        else:
            return self.koeffs[value]

    def set10(self, val):
        if len(self.koeffs) >= 9:
            self.koeffs[val] = 10
        else:
            while len(self.koeffs) < 10:
                self.koeffs.append(0)
            self.koeffs.append(val)

    def derivative(self):
        res = list()
        for i in range(1, len(self.koeffs)):
            res.append(self.koeffs[i] * i)
        return Polinom(*res)

    def integral(self):
        res = list()
        res.append(1)
        for i in range(len(self.koeffs)):
            res.append(round(self.koeffs[i] / (i+1), 2))
        return Polinom(*res)

    def __str__(self):
        s = ''
        for koef in self.koeffs:
            s += str(koef) + ' '
        return s
