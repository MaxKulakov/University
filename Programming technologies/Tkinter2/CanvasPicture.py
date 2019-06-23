from tkinter import Frame, Canvas, RIGHT, LEFT, SW, W, E, NW, Scrollbar, Y, X, BOTTOM, HORIZONTAL, VERTICAL, BOTH, Tk, \
    Radiobutton, StringVar, Entry, DoubleVar, Label, CENTER, TOP, IntVar, Button, OptionMenu
from tkinter.filedialog import askopenfilename
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import numpy as np

from PIL import Image, ImageTk


class CanvasPicture(Frame):
    def __init__(self, root, master=None, cnf={}, **kw):
        self.root = root
        self.view = Canvas(self.root, width=800, height=800, bg="white", scrollregion=(0,0,800,800))

    def create_picture(self):
        self.view.delete("all")
        path = askopenfilename()
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

    def choose_plot(self):
        self.view.delete("all")
        self.c = Tk()
        self.c.title("Test")
        self.c.option_add("*Font", "arial 18")
        self.c.geometry("800x200")
        self.c.grid()
        self.c.protocol("WM_DELETE_WINDOW", self.c.destroy)
        self.var = StringVar()
        funcs = ["sin x", "cos x", "tg x", "ctg x", "x^2", "x^3"]
        self.var.set(funcs[0])
        opt = OptionMenu(self.c, self.var, *funcs).pack()
        self.e1 = Entry(self.c)
        self.e1.pack(side=RIGHT)
        self.e2 = Entry(self.c)
        self.e2.pack(side=RIGHT)
        b = Button(self.c, text="OK", command=self.extract_data)
        b.pack(side=BOTTOM)

    def create_plot(self):
        if self.var.get() == "sin x":
            print('here')
            x = np.linspace(self.a, self.b, 100)
            y = np.sin(x)
            ax = plt.plot(x, y, color="black")
            # ax.plot(x, y, color="black")
            ax = plt.gca()
            ax.spines['left'].set_position('center')
            ax.spines['bottom'].set_position('center')
            ax.spines['top'].set_visible(False)
            ax.spines['right'].set_visible(False)
            plt.savefig('foo.png')
            img = Image.open('foo.png')
            img.thumbnail((800, 800))
            self.imgObj = self.view.create_image(0, 0)
            self.image = ImageTk.PhotoImage(img)
            self.view.itemconfigure(self.imgObj, image=self.image, anchor=NW)
        elif self.var.get() == 2:
            x = np.linspace(self.a, self.b, 100)
            y = np.sin(x)
            fig, ax = plt.subplots()
            ax.plot(x, y, color="black")
            ax = plt.gca()
            ax.spines['left'].set_position('center')
            ax.spines['bottom'].set_position('center')
            ax.spines['top'].set_visible(False)
            ax.spines['right'].set_visible(False)
            plt.savefig('/Users/andryyyha/PycharmProjects/Programming technologies/Tkinter2/foo.png')
            img = Image.open('/Users/andryyyha/PycharmProjects/Programming technologies/Tkinter2/foo.png')
            img.thumbnail((800, 800))
            self.imgObj = self.view.create_image(0, 0)
            self.image = ImageTk.PhotoImage(img)
            self.view.itemconfigure(self.imgObj, image=self.image, anchor=NW)
        elif self.var.get() == 3:
            pass
        elif self.var.get() == 4:
            pass
        elif self.var.get() == 5:
            pass
        elif self.var.get() == 6:
            pass

    def extract_data(self):
        self.a = float(self.e2.get())
        self.b = float(self.e1.get())
        self.c.destroy()
