from Graphs.Graph import Graph
from Graphs.NonOrientedGraph import NonOrientedGraph


class OrientedGraph(Graph):

    def __init__(self, adj: dict) -> None:
        super().__init__()
        self.adjactency_list = adj

    def create(self):
        print('Введите количество вершин')
        n = int(input())
        for i in range(n):
            print('Введите вершину')
            v = int(input())
            print('Введите вершины смежные с ней')
            u = {int(i) for i in input().split()}
            for el in u:
                self.add_edge(v, el)

    def add_vertex(self, v):
        self.adjactency_list[v] = None

    def add_edge(self, a, b):
        if a not in self.adjactency_list.keys():
            self.adjactency_list[a] = set()
            self.adjactency_list[a].add(b)
        else:
            self.adjactency_list[a].add(b)

    def print(self):
        for k in self.adjactency_list.keys():
            for v in self.adjactency_list[k]:
                print(k, v, sep=':')

    def preps(self):
        for k in self.adjactency_list.keys():
            for v in self.adjactency_list[k]:
                self.used[k] = False
                self.used[v] = False
                self.transponted_list[k] = set()
                self.transponted_list[v] = set()

    def is_weak_connected(self, v):
        d = dict()
        for k in self.adjactency_list.keys():
            for v in self.adjactency_list[k]:
                d[k] = set()
                d[v] = set()
        for k in self.adjactency_list:
            for v in self.adjactency_list[k]:
                d[k].add(v)
                d[v].add(k)
        g = NonOrientedGraph(d)
        return g.isconnected(v)

    def dfs1(self, v):
        self.used[v] = True
        for val in self.adjactency_list:
            if self.used[val] == False:
                self.dfs1(val)
        self.order.append(v)

    transponted_list = dict()

    def dfs2(self, v):
        self.used[v] = True
        self.component.append(v)
        for val in self.transponted_list[v]:
            if self.used[val] == False:
                self.dfs2(val)

    def is_strong_connected(self):
        self.preps()
        self.order = list()
        self.component = list()
        count = 0
        for k in self.adjactency_list.keys():
            if self.adjactency_list[k] == {}:
                continue
            for v in self.adjactency_list[k]:
                # yield v
                self.transponted_list[v].add(k)
        # self.preps()
        for k in self.adjactency_list.keys():
            if self.used[k] == False:
                self.dfs1(k)
        self.preps()
        for i in range(len(self.adjactency_list.keys())):
            v = self.order[len(self.adjactency_list.keys()) - 1 - i]
            if self.used[v] == False:
                self.dfs2(v)
                count += 1
                self.component.clear()
        if count == 1:
            return True
        else:
            return False

    def outdeg(self, v):
        return len(self.adjactency_list[v])

    def indeg(self, vert):
        count = 0
        for k in self.adjactency_list.keys():
            for v in self.adjactency_list[k]:
                if v == vert:
                    count += 1
        return count
