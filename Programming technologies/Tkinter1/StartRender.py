from tkinter import Frame, Tk, Button, messagebox
from Tkinter1 import QuestionService as qs


class StartRender(Frame):
    qs.flag = 0
    qs.answers = list()

    def __init__(self):
        self.root = Tk()
        self.root.title("Test")
        self.root.option_add("*Font", "arial 18")
        self.root.geometry("800x400")
        self.root.grid()
        self.create_widgets()
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.root.mainloop()

    def create_widgets(self):
        Button(self.root, text="Start", command=self.start).pack()

    def start(self):
        self.root.destroy()

    def on_closing(self):
        if messagebox.askokcancel("Quit", "Are you sure?"):
            self.root.destroy()
            exit(0)