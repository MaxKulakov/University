from math import sqrt


def length(x1, y1, x2, y2):
    return sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2))


def is_triangle(a, b, c):
    if a + b > c and a + c > b and b + c > a:
        return True
    else:
        return False


def square(a, b, c):
    p = (a + b + c) / 2
    return sqrt(p * (p - a) * (p - b) * (p - c))


def solution():
    min_square = 1000.0
    n = int(input())
    points = list()
    res = list()
    for i in range(n):
        x, y, = int(input()), int(input())
        points.append((x, y))

    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i != j and k != j and i != k:
                    a = length(points[i][0], points[i][1], points[j][0], points[j][1])
                    b = length(points[j][0], points[j][1], points[k][0], points[k][1])
                    c = length(points[k][0], points[k][1], points[i][0], points[i][1])
                    if is_triangle(a, b, c):
                        if square(a, b, c) < min_square:
                            min_square = round(square(a, b, c), 1)
                            res = [points[i], points[j], points[k]]
    print(min_square)
    print(*res)


def change(l1: list, l2: list):
    tmp = list(l1)
    l1.clear()
    for el in l2:
        l1.append(el)
    l2.clear()
    l2 = list(tmp)


inputFile = open('input.txt', 'r')
outputFile = open('output.txt', 'w')


def max_letter_line(char, text):
    maximum = 0
    line_number = -1
    d = dict()
    for i in range(1, text):
        for k in range(len(text[i])):
            if text[i][k].isalumn():
                if d[text[i][k]] not in d:
                    d[text[i][k]] = 1
                else:
                    d[text[i][k]] += 1
        if d[char] / sum(d.values()) > maximum:
            line_number = i
    return maximum * 100, line_number


C = inputFile.read(1)
l = [line.strip() for line in inputFile]
percent, number = max_letter_line(C, l)
outputFile.write(str(percent) + " " + str(number))

inputFile.close()
outputFile.close()


def add_item(item_name, item_cost):
    global is_printed
    if is_printed is True:
        is_printed = False
        cart.clear()
        cart.append((item_name, item_cost))
    else:
        cart.append((item_name, item_cost))


cart = list()
count = 0
is_printed = False


def print_receipt():
    global is_printed
    if cart is not []:
        global count
        count += 1
        print('Чек ' + str(count) + '. Всего предметов: ' + str(len(cart)))
        summary = 0
        for i in cart:
            summary += i[1]
            print(str(i[0]) + ' - ' + str(i[1]))
        print("Итого:", summary, sep=' ')
        print("-----")
        is_printed = True


commands = list()
last_command = ' '
while True:
    command = input()
    if command is '' and last_command is '':
        break
    commands.append(command)
    last_command = command

last_command = commands[0]
for i in range(len(commands)):
    if commands[i] == 'print_receipt()' and last_command == 'print_receipt()':
        continue
    else:
        c = commands[i]
        exec(c)
        last_command = commands[i]





