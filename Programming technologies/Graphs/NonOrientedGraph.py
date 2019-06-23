from collections import deque

from Graphs.Graph import Graph


class NonOrientedGraph(Graph):

    def __init__(self, adj) -> None:
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
        if v not in self.adjactency_list:
            self.adjactency_list[v] = None
        else:
            return 'Vertex is already in list'

    def add_edge(self, a, b):
        if a not in self.adjactency_list.keys():
            self.adjactency_list[a] = set()
            self.adjactency_list[a].add(b)
        else:
            self.adjactency_list[a].add(b)
        if b not in self.adjactency_list.keys():
            self.adjactency_list[b] = set()
            self.adjactency_list[b].add(a)
        else:
            self.adjactency_list[b].add(a)

    def print(self):
        for k in self.adjactency_list.keys():
            for v in self.adjactency_list[k]:
                print(k, v, sep=':')

    def preps(self):
        super().preps()

    def dfs_modifed(self, data):
        if self.used == {}:
            self.preps()
        self.used[data] = True
        for v in self.adjactency_list[data]:
            if self.used[v] == False:
                self.dfs_modifed(v)

    def isconnected(self, data):
        self.dfs_modifed(data)
        if False in self.used.values():
            return False
        else:
            return True

    def isfull(self):
        used = dict()
        keys = set(self.adjactency_list.keys())
        for k in self.adjactency_list.keys():
            if self.adjactency_list[k] == (keys - {k}):
                used[k] = True
            else:
                used[k] = False

        if False in self.adjactency_list.values():
            return True
        else:
            return False

    def find_deg(self, data):
        return len(self.adjactency_list[data])

    def bfs(self, start, end):
        self.preps()
        q = deque()
        q.append(start)
        d = dict()
        for k in self.adjactency_list.keys():
            d[k] = 0
        self.used[start] = True
        while q:
            v = q.popleft()
            if v == end:
                return d[end]
            if v not in self.adjactency_list.keys() and len(q) != 0:
                continue
            l = self.adjactency_list[v]
            for el in l:
                if self.used[el] == False:
                    self.used[el] = True
                    q.append(el)
                    d[el] = d[v] + 1

    def fulness_checker(self):
        all_verts = set(self.adjactency_list.keys())
        for k in self.adjactency_list.keys():
            if self.adjactency_list[k] != (all_verts - k):
                return False
        return True

    comps_count = 0

    def find_comps(self):
        self.preps()
        for k in self.adjactency_list.keys():
            if self.used[k] == False:
                self.comps_count += 1
                self.dfs_modifed(k)
        return self.comps_count

    def bipartite_graph(self, v, c: bool):
        self.preps()
        self.used[v] = c
        for k in self.adjactency_list.keys():
            if self.used[k] == False:
                self.bipartite_graph(k, not c)
            elif self.used[v] == c:
                return 'Graph is not bipartite'
        return 'Graph is bipartite'

    def addition_graph(self):
        adj = dict()
        all_verts = set(self.adjactency_list.keys())
        for k in self.adjactency_list.keys():
            adj[k] = all_verts - {k}

        res = dict()
        for k in self.adjactency_list.keys():
            res[k] = adj[k] - self.adjactency_list[k]
        return NonOrientedGraph(res)
    


