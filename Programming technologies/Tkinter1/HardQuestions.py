from tkinter import Frame, Tk, Label, LEFT, TOP, StringVar, Button, Entry, messagebox
from Tkinter1 import QuestionService


class HardQuestions(Frame):
    def __init__(self, master=None, cnf={}, **kw):
        self.root = Tk()
        self.root.title("Hard questions")
        self.root.option_add("*Font", "arial 18")
        self.root.geometry("800x400")
        self.questions = QuestionService.open_json_by_tag("hard")
        self.var = StringVar()
        self.pos = -1
        self.root.grid()
        self.render()
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.root.mainloop()

    def create_widgets(self):
        lb = Label(self.root, text=self.questions[self.pos]['text'])
        lb.pack(side=TOP)
        self.var.set('')
        Entry(self.root, textvariable=self.var).pack(side=LEFT)
        Button(self.root, text="Next question", command=self.next_question).pack(side=LEFT)

    def next_question(self):
        if self.var.get() == '':
            warning = Tk()
            warning.geometry("100x50")
            warning.protocol("WM_DELETE_WINDOW", self.root.destroy())
            Label(warning, text='Pick a variant!').pack(side=TOP)
        else:
            if self.var.get().lower() == self.questions[self.pos]['correctAns']:
                QuestionService.answers.append(1)
            else:
                QuestionService.answers.append(0)
            self.render()

    def render(self):
        self.pos += 1
        for w in self.root.winfo_children():
            w.destroy()
        if self.pos == len(self.questions):
            self.root.destroy()
        else:
            self.create_widgets()

    def on_closing(self):
        if messagebox.askokcancel("Quit", "Are you sure?"):
            self.root.destroy()
            exit(0)