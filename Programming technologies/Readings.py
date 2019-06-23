from typing import Any


class Printing:
    def __init__(self, publisher, year, title):
        self.publisher = publisher
        self.year = year
        self.title = title

    def set_publisher(self, value):
        self.publisher = value

    def set_year(self, value):
        self.year = value

    def set_title(self, value):
        self.title = value

    def get_publisher(self):
        return self.publisher

    def get_year(self):
        return self.year

    def get_title(self):
        return self.title

    def print(self):
        print('Издательство:', self.publisher, sep=' ')
        print('Год издания:', self.year, sep=' ')
        print('Название:', self.title, sep=' ')


class Magazine(Printing):
    def __init__(self, publisher, year, title, number, month):
        super().__init__(publisher, year, title)
        self.number = number
        self.month = month

    def set_number(self, value):
        self.number = value

    def set_month(self, value):
        self.month = value

    def get_number(self):
        return self.number

    def get_month(self):
        return self.month


    def print(self):
        super().print()
        print('Номер:', self.number, sep=' ')
        print('Месяц', self.month, sep=' ')


class Book(Printing):

    def __init__(self, publisher, year, title, theme, author, pages):
        super().__init__(publisher, year, title)
        self.theme = theme
        self.author = author
        self.pages = pages

    def set_theme(self, value):
        self.theme = value

    def set_author(self, value):
        self.author = value

    def set_pages(self, value):
        self.pages = value

    def get_theme(self):
        return self.theme

    def get_pages(self):
        return self.pages

    def get_author(self):
        return self.author

    def print(self):
        super().print()
        print('Тематика:', self.theme, sep=' ')
        print('Автор:', self.author, sep=' ')
        print('Количество страниц:', self.pages, sep=' ')


class WorkBook(Printing):

    def __init__(self, publisher, year, title, purpose):
        super().__init__(publisher, year, title)
        self.purpose = purpose

    def set_purpose(self, value):
        self.publisher = value

    def get_purpose(self):
        return self.purpose

    def print(self):
        super().print()
        print('Назначение:', self.purpose, sep=' ')


def demo():
    p = Printing('Дрофа', 1999, 'Учебник по математике за 6 класс')
    p.print()
    p.set_year(2006)
    p.print()
    m = Magazine('издательский дом Москва', 2012, 'Юный робототехник', 12, 'December')
    m.print()
    b = Book('Дрофа', 2014, 'Гарри Поттер и Орден Феникса', 'Фентези', 'Дж. К. Роулинг', 600)
    b.print()
    w = WorkBook('Дрофа', 1999, 'Учебник по математике за 6 класс', 'математика')
    w.print()