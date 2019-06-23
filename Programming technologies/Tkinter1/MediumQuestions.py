from tkinter import Frame, Tk, Label, LEFT, TOP, Button, BooleanVar, Checkbutton, messagebox
from Tkinter1 import QuestionService


class MediumQuestions(Frame):

    def __init__(self, master=None, cnf={}, **kw):
        self.root = Tk()
        self.root.title("Medium questions")
        self.root.option_add("*Font", "arial 18")
        self.root.geometry("800x400")
        self.questions = QuestionService.open_json_by_tag("medium")
        self.var1 = BooleanVar()
        self.var2 = BooleanVar()
        self.var3 = BooleanVar()
        self.var4 = BooleanVar()
        self.pos = -1
        self.root.grid()
        self.render()
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.root.mainloop()

    def create_widgets(self):
        lb = Label(self.root, text=self.questions[self.pos]['text'])
        lb.pack(side=TOP)
        variants = self.questions[self.pos]['answers']
        self.var1.set(0)
        self.var2.set(0)
        self.var3.set(0)
        self.var4.set(0)
        self.checkbuttons = list()
        c1 = Checkbutton(self.root, text=variants["1"], variable=self.var1, onvalue=1, offvalue=0)
        c1.pack()
        self.checkbuttons.append(c1)
        c2 = Checkbutton(self.root, text=variants["2"], variable=self.var2, onvalue=1, offvalue=0)
        c2.pack()
        self.checkbuttons.append(c2)
        c3 = Checkbutton(self.root, text=variants["3"], variable=self.var3, onvalue=1, offvalue=0)
        c3.pack()
        self.checkbuttons.append(c3)
        c4 = Checkbutton(self.root, text=variants["4"], variable=self.var4, onvalue=1, offvalue=0)
        c4.pack()
        self.checkbuttons.append(c4)
        Button(self.root, text="Next question", command=self.next_question).pack(side=LEFT)

    def next_question(self):
        if self.var1.get() == 0 and self.var2.get() == 0 and self.var3.get() == 0 and self.var4.get() == 0:
            warning = Tk()
            warning.geometry("100x50")
            Label(warning, text='Pick a variant!').pack(side=TOP)
        else:
            vars = [self.var1, self.var2, self.var3, self.var4]
            res = zip(self.checkbuttons, vars)
            tmp = list()
            for el in res:
                if el[1].get() == True:
                    tmp.append(el[0].cget('text'))
            print(tmp)
            set_answers = set(tmp)
            set_correct = set(self.questions[self.pos]['correctAns'])
            if set_answers == set_correct:
                QuestionService.answers.append(len(set_correct))
            elif len(set_answers) > len(set_correct):
                QuestionService.answers.append(0)
            elif set_correct - set_answers == {}:
                QuestionService.answers.append(0)
            else:
                QuestionService.answers.append(len(set_correct - (set_correct - set_answers)))
            # QuestionService.answers.append(tmp == self.questions[self.pos]['correctAns'])
            # tmp.clear()
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