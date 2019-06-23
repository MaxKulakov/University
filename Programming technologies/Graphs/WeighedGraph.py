from Graphs.Graph import Graph


class WeighedGraph(Graph):

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
            print('Введите веса для вершин(требуется ' + str(len(u)) + ')')
            w = [int(i) for i in input().split()]
            res = set(zip(u, w))
            for el in res:
                self.add_weighed_edge(v, el[0], el[1])

    def add_vertex(self, v):
        self.adjactency_list[v] = None

    def add_edge(self, a, b):
        super().add_edge(a, b)

    def add_weighed_edge(self, a, b, w):
        if a not in self.adjactency_list.keys():
            self.adjactency_list[a] = set()
            self.adjactency_list[a].add((b, w))
        else:
            self.adjactency_list[a].add((b, w))
        if b not in self.adjactency_list.keys():
            self.adjactency_list[b] = set()
            self.adjactency_list[b].add((a, w))
        else:
            self.adjactency_list[b].add((a, w))

    def print(self):
        for k in self.adjactency_list.keys():
            for v in self.adjactency_list[k]:
                print(k, ':', v[0], ',', v[1], sep='')

    def preps(self):
        super().preps()

    INF = 100000

    def dijkstra(self, start, end):
        d = dict()
        used = dict()
        for k in self.adjactency_list.keys():
            # global INF
            d[k] = self.INF
            used[k] = False
        d[start] = 0

        for k in self.adjactency_list.keys():
            # nonlocal v
            v = -1
            if used[k] == False and (v is -1 or d[k] < d[v]):
                v = k
            if d[v] is self.INF:
                break
            used[v] = True

            for val in self.adjactency_list[v]:
                to = val[0]
                len = val[1]
                if d[v] + len < d[to]:
                    d[to] = d[v] + len
        return d[end]

    def prim(self):
        self.preps()
        carcase = dict()
        d = dict()
        tmp = tuple()
        counter = 0
        visited = dict()
        for k in self.adjactency_list.keys():
            visited[k] = False
        for k in self.adjactency_list.keys():
            d[k] = 0
        for k in self.adjactency_list.keys():
            self.used[k] = True
            break
        val = 0
        for k in self.adjactency_list.keys():
            if counter == len(self.adjactency_list.keys()):
                break
            # global INF
            min = self.INF
            for v in self.adjactency_list[k]:
                if v[1] < min:
                    tmp = v
                    min = v[1]
                    val = d[v[0]]
                    d[v[0]] = v[1] + val
            self.used[tmp[0]] = True
            carcase[k] = tmp
            d[tmp[0]] = val + tmp[1]
            counter += 1
        for k in carcase.keys():
            print(k, carcase[k][0], carcase[k][1], sep=' ')
            # print(carcase[k][0], k, carcase[k][1], sep=' ')