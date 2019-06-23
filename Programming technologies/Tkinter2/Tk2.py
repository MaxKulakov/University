from tkinter import Tk, Button, SW, W, NW, LEFT, Menu, messagebox, StringVar, OptionMenu, Entry, RIGHT, BOTTOM, \
    VERTICAL, Y, X, HORIZONTAL, Frame, Canvas, Scrollbar, BOTH, Toplevel, TOP
from tkinter.filedialog import askopenfilename

import numpy as np
from PIL import ImageTk, Image

import matplotlib.pyplot as plt


class CanvasPicture(Frame):
    def __init__(self, root, master=None, cnf={}, **kw):
        self.root = root
        self.fun_dict = {"sin x": np.sin, "cos x": np.cos,
                         "tg x": self.tg, "ctg x": self.ctg,
                         "x^2": self.x2, "x^3": self.x3}
        self.view = Canvas(self.root, width=800, height=800, bg="white", scrollregion=(0, 0, 800, 800))
        self.a = float()
        self.b = float()
        self.var = StringVar()
        self.vbar = Scrollbar()
        self.hbar = Scrollbar()

    EPS = 0.1

    def x2(self, x):
        return list(map(lambda t: t * t, x))

    def x3(self, x):
        return list(map(lambda t: t * t * t, x))

    def ctg(self, arr):
        def t(x):
            h = np.math.sin(x)
            if abs(h) > self.EPS:
                return np.math.cos(x) / h
            else:
                return float("nan")

        return list(map(lambda a: t(a), arr))

    def tg(self, arr):
        def t(x):
            h = np.math.cos(x)
            if abs(h) > self.EPS:
                return np.math.sin(x) / h
            else:
                return float("nan")

        return list(map(lambda a: t(a), arr))

    def create_picture(self):
        self.view.delete("all")
        self.vbar.destroy()
        self.hbar.destroy()
        path = askopenfilename()
        if path != "":
            try:
                self.image = ImageTk.PhotoImage(Image.open(path))
                if self.image.height() > 800 or self.image.width() > 800:
                    self.hbar = Scrollbar(self.root, orient=HORIZONTAL)
                    self.hbar.pack(side=BOTTOM, fill=X)
                    self.hbar.config(command=self.view.xview)
                    self.vbar = Scrollbar(self.root, orient=VERTICAL)
                    self.vbar.pack(side=RIGHT, fill=Y)
                    self.vbar.config(command=self.view.yview)
                    self.view.config(xscrollcommand=self.hbar.set, yscrollcommand=self.vbar.set)
                    self.view.create_image(0, 0, image=self.image, anchor=NW)
                    self.view.pack(side=RIGHT, expand=True, fill=BOTH)
                else:
                    self.view.create_image(0, 0, image=self.image, anchor=NW)
                    self.view.pack()
            except IOError:
                print("Incorrect file format or name")

    def print_plot(self):
        self.view.delete("all")
        self.choose_plot()

    def choose_plot(self):
        self.view.delete("all")
        self.c = Tk()
        self.c.title("Test")
        self.c.option_add("*Font", "arial 18")
        self.c.geometry("800x200")
        self.c.grid()
        self.c.protocol("WM_DELETE_WINDOW", self.c.destroy)
        funcs = ["sin x", "cos x", "tg x", "ctg x", "x^2", "x^3"]
        self.var.set(funcs[0])
        opt = OptionMenu(self.c, self.var, *funcs)
        opt.pack(side=TOP)
        self.e1 = Entry(self.c)
        self.e1.pack(side=RIGHT)
        self.e2 = Entry(self.c)
        self.e2.pack(side=RIGHT)
        b = Button(self.c, text="OK", command=self.extract_data)
        b.pack(side=BOTTOM)

    def extract_data(self):
        self.a = float(self.e2.get())
        self.b = float(self.e1.get())
        print(self.b)
        self.create_plot(self.var.get(), self.a, self.b)
        self.c.destroy()

    def create_plot(self, func, a, b):
        x = np.linspace(a, b, 100)
        y = self.fun_dict[func](x)
        fig, ax = plt.subplots()
        ax.plot(x, y, color="black", label="график функции")
        ax = plt.gca()
        ax.autoscale()
        ax.spines['left'].set_position('center')
        ax.spines['bottom'].set_position('center')
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        plt.savefig('foo.png')
        img = Image.open('foo.png')
        img.thumbnail((800, 800))
        self.imgObj = self.view.create_image(0, 0)
        self.image = ImageTk.PhotoImage(img)
        self.view.create_image(0, 0, image=self.image, anchor=NW)
        self.view.pack()


class Tk2(Frame):
    def __init__(self) -> None:
        self.root = Tk()
        self.root.title("Picture or graph")
        self.root.option_add("*Font", "arial 18")
        self.root.geometry("1200x800")
        self.root.grid()
        self.canv = CanvasPicture(root=self.root, width=800, height=800)
        self.create_menu()
        self.root.mainloop()

    def create_menu(self):
        m = Menu(self.root)
        self.root.config(menu=m)
        fm = Menu(m, tearoff=0)
        m.add_cascade(label=u"Опции", menu=fm)
        fm.add_command(label=u"Открыть", command=self.canv.create_picture)
        fm.add_command(label=u"Построить график", command=self.canv.print_plot)
        fm.add_command(label=u"Выход", command=self.close)
        hm = Menu(m, tearoff=0)
        m.add_cascade(label=u"Помощь", menu=hm)
        hm.add_command(label=u"Справка", command=self.info)

    def info(self):
        messagebox.showinfo("Info", "Программа для отрисовки изображений и графиков."
                                    "\n Версия Python: 3.7\nАвтор:Андрей Вязков")

    def close(self):
        exit(0)


if __name__ == "__main__":
    t = Tk2()
