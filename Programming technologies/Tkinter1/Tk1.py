from Tkinter1 import EasyQuestions as eq, MediumQuestions as mq, HardQuestions as hq, QuestionService as qs, Results as r
from Tkinter1 import StartRender as sr


class Tk1:
    def __init__(self) -> None:
        sr.StartRender()
        self.render()
        while qs.flag != 2:
            self.render()
        exit(0)

    def render(self):
        qs.answers = list()
        qs.flag = 0
        eq.EasyQuestions()
        mq.MediumQuestions()
        hq.HardQuestions()
        r.Results()

def some_func():
    pass


if __name__ == "__main__":
    t = Tk1()

