# -*- coding: utf8 -*-
from tkinter import *
from math import *
import tkinter.filedialog as fd
from PIL import Image, ImageTk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_agg import FigureCanvasAgg
import matplotlib.backends.tkagg as tkagg
from tkinter import messagebox
import numpy as np
import math


class FunctionInfo(Frame, object):
    def __init__(self, master):
        super(FunctionInfo, self).__init__(master)
        self.pack()
        OPTIONS = ["sin(x)", "cos(x)", "tg(x)", "ctg(x)", "x**2", "x**3"]
        self.function = StringVar()
        self.function.set(OPTIONS[0])
        w = OptionMenu(master, self.function, *OPTIONS)
        w.pack()
        self.text1 = Entry(self)
        self.text2 = Entry(self)
        self.text1.grid()
        self.text1.insert(0, "0")
        self.text2.grid()
        self.text2.insert(0, "0")
        button = Button(master, text="OK", command=self.choose)
        button.pack()

    def choose(self):
        self.x1 = float(self.text1.get())
        self.x2 = float(self.text2.get())
        self.master.destroy()


class MainWindow(Frame, object):
    EPS = 0.1

    def __init__(self, master):
        super(MainWindow, self).__init__(master)
        self.master = master
        self.pack()
        self.place_menu()
        self.canvas = Canvas(self.master, width=800, height=800)
        self.canvas.pack()
        self.fun_dict = {"sin(x)": np.sin, "cos(x)": np.cos,
                         "tg(x)": self.tg, "ctg(x)": self.ctg,
                         "x**2": self.x_2, "x**3": self.x_3}

    def x_2(self, x):
        return list(map(lambda t: t * t, x))

    def x_3(self, x):
        return list(map(lambda t: t * t * t, x))

    def ctg(self, arr):
        def t(x):
            h = math.sin(x)
            if abs(h) > self.EPS:
                return math.cos(x) / h
            else:
                return float("nan")

        return list(map(lambda a: t(a), arr))

    def tg(self, arr):
        def t(x):
            h = math.cos(x)
            if abs(h) > self.EPS:
                return math.sin(x) / h
            else:
                return float("nan")

        return list(map(lambda a: t(a), arr))

    def open_file(self):
        self.canvas.delete("all")
        self.imgObject = self.canvas.create_image(0, 0)
        filename = fd.askopenfilename()
        if filename != "":
            try:
                src = Image.open(filename)
                src.thumbnail((800, 800))
                self.img = ImageTk.PhotoImage(src)
                self.canvas.itemconfigure(self.imgObject, image=self.img, anchor="nw")
            except IOError:
                print("Incorrect file")

    def close(self):
        self.master.destroy()

    def print_plot(self):
        self.canvas.delete("all")
        wind = Toplevel(master=self.master)
        self.window_info = FunctionInfo(wind)
        self.window_info.wait_window()
        print(self.window_info.x1)
        print(self.window_info.x2)
        print(self.window_info.function.get())
        self.create_plot(self.window_info.function.get(),
                         self.window_info.x1,
                         self.window_info.x2)

    def create_plot(self, fun, x1, x2):
        x = np.linspace(x1, x2, 100)
        y = self.fun_dict[fun](x)
        fig, ax = plt.subplots()
        ax.plot(x, y, color="blue", label="голубая линия")
        ax = plt.gca()
        ax.spines['left'].set_position('center')
        ax.spines['bottom'].set_position('center')
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        plt.savefig('foo.png')
        src = Image.open('foo.png')
        src.thumbnail((800, 800))
        self.imgObject = self.canvas.create_image(0, 0)
        self.img = ImageTk.PhotoImage(src)
        self.canvas.itemconfigure(self.imgObject, image=self.img, anchor="nw")

    def place_menu(self):
        m = Menu(self.master)
        self.master.config(menu=m)
        fm = Menu(m, tearoff=0)
        m.add_cascade(label=u"Опции", menu=fm)
        fm.add_command(label=u"Открыть", command=self.open_file)
        fm.add_command(label=u"Построить график", command=self.print_plot)
        fm.add_command(label=u"Выход", command=self.close)
        hm = Menu(m, tearoff=0)
        m.add_cascade(label=u"Помощь", menu=hm)
        hm.add_command(label=u"Справка", command=self.info)

    def info(self):
        messagebox.showinfo("Info", "Программа предназначена для работы с изображениями"
                            + " и графиками.")


if __name__ == "__main__":
    window = Tk()
    window.title("Приложение 2")
    window.geometry("800x800")
    app = MainWindow(window)
    window.mainloop()