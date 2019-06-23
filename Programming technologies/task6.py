# 1
s = input()
print(s[2])  # 1
print(s[len(s) - 1])  # Tkinter2
print(s[:5])  # 3
print(s[:-2])  # 4
print(s[::2])  # 5
print(s[1::2])  # 6
print(s[::-1])  # 7
print(s[::-2])  # 8
print(len(s))

# Tkinter2
# если результат поиска не -1, то сравниваем позиции взождений, если они равны - буква одна в строке - выводим позицию
# иначе выводим обе позиции
s = input()
first = s.find('f')
last = s.rfind('f')
if first != -1:
    if first == last:
        print(first)
    else:
        print(first)
        print(last)

# 3

# находим префикс в который не включаем букву h
# находим инфикс, который не будет включать первую h и не будет включать вторую h
# находим суффикс начиная с последнего вхождения h и не включая его
# соединяем строки разворачивая инфикс
s = input()
prefix = s[:s.find('h')]
infix = s[s.find('h'):s.rfind('h') + 1]
suffix = s[s.rfind('h') + 1:]
s = prefix + infix[::-1] + suffix
print(s)

# 4
# находим префикс, который включает h
# находит инфикс
# находим суффикс, который включает h
# соединяем строки, заменяя в инфиксе h на H
s = input()
prefix = s[:s.find('h') + 1]
infix = s[s.find('h') + 1:s.rfind('h')]
suffix = s[s.rfind('h'):]
s = prefix + infix.replace('h', 'H') + suffix
print(s)

# 5
# заменяем все @ на пустые строки
s = input()
print(s.replace('@', ''))