from tkinter import Frame, Tk, Label, LEFT, TOP, StringVar, Radiobutton, Button, W, messagebox
from Tkinter1 import QuestionService


class EasyQuestions(Frame):

    def __init__(self, master=None, cnf={}, **kw):
        self.root = Tk()
        self.root.title("Easy questions")
        self.root.option_add("*Font", "arial 18")
        self.root.geometry("800x400")
        self.questions = QuestionService.open_json_by_tag("easy")
        self.var = StringVar()
        self.pos = -1
        self.root.grid()
        self.render()
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.root.mainloop()

    def create_widgets(self):
        lb = Label(self.root, text=self.questions[self.pos]['text'])
        lb.pack(side=TOP)
        variants = self.questions[self.pos]['answers']
        self.var.set("")
        for v in variants.keys():
            Radiobutton(self.root, text=variants[v], variable=self.var, value=variants[v]).pack()
        Button(self.root, text="Next question", command=self.next_question).pack(side=LEFT)

    def next_question(self):
        if self.var.get() == "":
            warning = Tk()
            warning.geometry("100x50")
            Label(warning, text='Pick a variant!').pack(anchor=W)
        else:
            if self.var.get() == self.questions[self.pos]['correctAns']:
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
