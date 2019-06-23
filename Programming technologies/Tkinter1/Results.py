from tkinter import Frame, Tk, Label, Button, LEFT, TOP, messagebox
from Tkinter1 import QuestionService


class Results(Frame):

    def __init__(self, master=None, cnf={}, **kw):
        self.root = Tk()
        self.root.title("Test")
        self.root.option_add("*Font", "arial 18")
        self.root.geometry("800x400")
        self.root.grid()
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.create_widgets()
        self.root.mainloop()

    def create_widgets(self):
        Label(self.root, text='Your answers').pack(side=TOP)
        points = 0
        i = 0
        answers = QuestionService.answers
        for a in answers:
            Label(self.root, text='Question' + str(i + 1) + ": " + str(a) + " point(s)").pack()
            if a:
                points += a
            i += 1
        Label(self.root, text="Right answers: " + str(points) + "/" + str(14)).pack(side=LEFT)
        if len(answers) > 0 and points < 7:
            Button(self.root, text="Retry", command=self.retry).pack(side=LEFT)

    def retry(self):
        QuestionService.flag = 1
        self.root.destroy()

    def exit(self):
        QuestionService.flag = 2
        self.root.destroy()

    def on_closing(self):
        if messagebox.askokcancel("Quit", "Are you sure?"):
            self.root.destroy()
            exit(0)