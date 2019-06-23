package com.andyyyha.graph;

import javafx.util.Pair;

import java.util.*;

public class Graph<T> {
    protected HashMap<Vertex<T>, List<Pair<Vertex<T>, Double>>> adjactencyList;
    protected List<Pair<Vertex<T>, Vertex<T>>> list = new ArrayList<>();

    public Graph(HashMap<Vertex<T>, List<Pair<Vertex<T>, Double>>> adjactencyList) {
        this.adjactencyList = adjactencyList;
    }

    public Graph() {
        adjactencyList = new HashMap<>();
    }

    public Graph(Graph<T> copy) {
        this.adjactencyList = copy.adjactencyList;
    }

    public Vertex<T> addVertex(T v) {
        if (v == null)
            throw new NullPointerException();
        Vertex<T> adding = new Vertex<T>(v);
        if (!adjactencyList.containsKey(adding)) {
            Pair<Vertex<T>, Double> p = new Pair<>(null, null);
            List<Pair<Vertex<T>, Double>> value = new ArrayList<>();
            adjactencyList.put(adding, value);
        }
        return adding;
    }

    public void addEdge(T el1, T el2) {
        if (el1 == null) throw new NullPointerException();
        Vertex<T> v1 = new Vertex<>(el1);
        Vertex<T> v2 = new Vertex<>(el2);
        if (adjactencyList.containsKey(v1)) {
            List<Pair<Vertex<T>, Double>> value1 = adjactencyList.get(v1);
            Pair<Vertex<T>, Double> p = new Pair<>(v2, 0.0);
            value1.add(p);
            adjactencyList.put(v1, value1);
        } else {

            List<Pair<Vertex<T>, Double>> value = new ArrayList<>();
            Pair<Vertex<T>, Double> p = new Pair<>(v2, 0.0);
            value.add(p);
            adjactencyList.put(v1, value);
        }
    }

    public void addEdge(T el1, T el2, Double w) {
        if (el1 == null) throw new NullPointerException();
        Vertex<T> v1 = new Vertex<>(el1);
        Vertex<T> v2 = new Vertex<>(el2);
        if (adjactencyList.containsKey(v1)) {
            List<Pair<Vertex<T>, Double>> value1 = adjactencyList.get(v1);
            Pair<Vertex<T>, Double> p = new Pair<>(v2, w);
            value1.add(p);
            adjactencyList.put(v1, value1);
        } else {

            List<Pair<Vertex<T>, Double>> value = new ArrayList<>();
            Pair<Vertex<T>, Double> p = new Pair<>(v2, w);
            value.add(p);
            adjactencyList.put(v1, value);
        }
    }

    public void deleteVertex(T el) {
        if (el == null) throw new NullPointerException();
        Vertex<T> v = new Vertex<>(el);
        Iterator<Map.Entry<Vertex<T>, List<Pair<Vertex<T>, Double>>>> iterator = adjactencyList.entrySet().iterator();
        try {
            while (iterator.hasNext()) {
                Map.Entry<Vertex<T>, List<Pair<Vertex<T>, Double>>> e = iterator.next();
                if (e.getKey().equals(v))
                    iterator.remove();
                else if (e.getValue().contains(new Pair<>(v, null)))
                    e.getValue().remove(new Pair<>(v, null));
            }
        } catch (NullPointerException npe) {
            npe.printStackTrace();
        }
    }

    public void deleteEdge(T el1, T el2) {
        if (el1 == null | el2 == null) throw new NullPointerException();
        Vertex<T> v = new Vertex<>(el1);
        Vertex<T> v1 = new Vertex<>(el2);
        Iterator<Map.Entry<Vertex<T>, List<Pair<Vertex<T>, Double>>>> iterator = adjactencyList.entrySet().iterator();
        try {
            while (iterator.hasNext()) {
                Map.Entry<Vertex<T>, List<Pair<Vertex<T>, Double>>> e = iterator.next();
                if (e.getKey().equals(v) & e.getValue().contains(new Pair<>(v1, null)))
                    e.getValue().remove(new Pair<>(v1, null));
            }
        } catch (NullPointerException npe) {
            npe.printStackTrace();
        }
    }

    public void print() {
        System.out.println("Graph");
        for (Vertex<T> p : adjactencyList.keySet()) {
            List<Pair<Vertex<T>, Double>> p1 = adjactencyList.get(p);
            if (p1.size() == 0)
                System.out.println(p.getData().toString());
            else {
                for (Pair<Vertex<T>, Double> pair : p1)
                    System.out.println(p.getData() + " " + pair.getKey().getData().toString());
            }
        }
    }

    public void printWeighedGraph() {
        System.out.println("Weighed graph");
        for (Vertex<T> p : adjactencyList.keySet()) {
            List<Pair<Vertex<T>, Double>> p1 = adjactencyList.get(p);
            if (p1.size() == 0)
                System.out.println(p.getData().toString());
            else {
                for (Pair<Vertex<T>, Double> pair : p1) {
                    System.out.println(p.getData().toString() + " " + pair.getKey().getData().toString() + " " + pair.getValue().toString());
                }
            }
        }
    }

    public void convertToList() {
        for (Vertex<T> v : adjactencyList.keySet()) {
            List<Pair<Vertex<T>, Double>> p1 = adjactencyList.get(v);
            for (Pair<Vertex<T>, Double> pair : p1) {
                Pair<Vertex<T>, Vertex<T>> tmp = new Pair<>(v, pair.getKey());
                list.add(tmp);
            }
        }
    }

    public void aNonOreinted() {
        HashMap<Vertex<T>, Integer> l = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        for (Vertex<T> v : adjactencyList.keySet()) {
            List<Pair<Vertex<T>, Double>> val = adjactencyList.get(v);
            for (Pair<Vertex<T>, Double> pair : val) {
                if (!l.containsKey(v)) {
                    l.put(v, 1);
                } else {
                    int acc = l.get(v);
                    acc++;
                    l.put(v, acc);
                }
                if (!l.containsKey(pair.getKey())) {
                    l.put(pair.getKey(), 1);
                } else {
                    int acc1 = l.get(pair.getKey());
                    acc1++;
                    l.put(pair.getKey(), acc1);
                }
            }
        }
        for (Vertex<T> v : l.keySet()) {
            if (l.get(v) == 1)
                System.out.println(v.getData().toString());
        }
    }

    public void aOriented(T elm) {
        if (elm == null) throw new NullPointerException();
        Vertex<T> vertex = new Vertex<>(elm);
        for (Vertex<T> v : adjactencyList.keySet()) {
            if (v.equals(vertex)) {
                List<Pair<Vertex<T>, Double>> l = adjactencyList.get(v);
                for (Pair<Vertex<T>, Double> iter : l) {
                    System.out.println(iter.getKey().getData().toString());
                }
            }
        }
    }

    public Graph<T> bOriented() {
        Graph<T> r = new Graph<>();
        List<Pair<Vertex<T>, Vertex<T>>> rev = new ArrayList<>();
        for (Pair<Vertex<T>, Vertex<T>> p : list) {
            T u = p.getValue().getData();
            T v = p.getKey().getData();
            r.addEdge(u, v);
            Pair<Vertex<T>, Vertex<T>> revP = new Pair<>(p.getValue(), p.getKey());
            rev.add(revP);
        }
        return r;
    }

    protected HashMap<T, Boolean> visited = new HashMap<>();
    protected List<Pair<T, T>> grph = new ArrayList<>();

    public void preps() {
        convertToList();
        for (Vertex<T> v1 : adjactencyList.keySet()) {
            //List<T> vertices = new ArrayList<>();
            color.put(v1.getData(), false);
            List<Pair<Vertex<T>, Double>> lst = adjactencyList.get(v1);
            for (Pair<Vertex<T>, Double> p : lst) {
                Pair<T, T> adding = new Pair<>(v1.getData(), p.getKey().getData());
                // Pair<T, T> revAdding = new Pair<>(p.getKey().getData(), v1.getData());
                grph.add(adding);
                //  grph.add(revAdding);
                visited.put(v1.getData(), false);
                visited.put(p.getKey().getData(), false);
            }
            for (Pair<Vertex<T>, Double> p : lst) {
                Pair<T, T> revAdding = new Pair<>(p.getKey().getData(), v1.getData());
                grph.add(revAdding);
            }
            // grph.put(v1.getData(), vertices);
        }
    }

    public int dfsModifed(T data) {
        visited.put(data, true);
        //int cc = list.size();
        int cc = visited.size();
        for (int i = 0; i < grph.size(); i++) {
            if (!visited.get(grph.get(i).getValue()) && grph.get(i).getValue() == data) {
                dfsModifed(grph.get(i).getValue());
                //cc++;
            }
        }
       return cc;
    }

    // !!!!
    public void dfsModifed1(T data) {
        Vertex<T> d = new Vertex<>(data);
        visited.put(data, true);
        components.add(data);
        if (adjactencyList.containsKey(d) || color.containsKey(data)) {
           // visited.put(data, true);
           // List<Pair<Vertex<T>, Double>> l = adjactencyList.get(d);
            for (Pair<Vertex<T>, Double> p: adjactencyList.get(d)) {
                if (visited.get(p.getKey().getData()) == false)
                    dfsModifed1(p.getKey().getData());
            }
        }
      //  return visited.size();
    }


    HashMap<T, Boolean> color = new HashMap<>();
    boolean flag = false;

    public boolean cyclesCheck(T data, T pred) {
        Vertex<T> d = new Vertex<>(data);
        if (adjactencyList.containsKey(d) || color.containsKey(data)) {
            color.put(data, true);
            List<Pair<Vertex<T>, Double>> l = adjactencyList.get(d);
            for (Pair<Vertex<T>, Double> p : l) {
                if (color.containsKey(p.getKey().getData())) {
                    if (color.get(p.getKey().getData()) == false)
                        cyclesCheck(p.getKey().getData(), data);
                    else if (p.getKey().getData() != pred) {
                       // System.out.println("Graph has cycles");
                        flag = true;
                        //System.out.println(flag);
                        return true;
                    }
                }
                else return false;
            }
        } else return false;
        return false;
    }

    HashMap<Vertex<T>, Boolean> c = new HashMap<>();
    public void checker1(T p) {
        for (Vertex<T> v: adjactencyList.keySet()) {
            c.put(v, cyclesCheck(v.getData(), p));
            List<Pair<Vertex<T>, Double>> l = adjactencyList.get(v);
            for (Pair<Vertex<T>, Double> p1: l) {
                c.put(p1.getKey(), cyclesCheck(p1.getKey().getData(), p));
            }
        }
        /*if (c.containsValue(false))
            System.out.println("forest has cycles");*/
    }

    //works on specific tests
    public void checker(T data, T pred) {
       // int c = dfsModifed(data);
        dfsModifed1(data);
        cyclesCheck(data, pred);
        if (!visited.containsValue(false) && flag == false)
            System.out.println("This is a tree");
        else if (visited.containsValue(false) && flag == false)
            System.out.println("This is a forest");
        else
            System.out.println("This is nothing else");
    }

    public void checker2(T data, T pred) {
        dfsModifed1(data);
        cyclesCheck(data, pred);
        checker1(pred);
        if (!visited.containsValue(false) && flag == false)
            System.out.println("This is a tree");
        else if (visited.containsValue(false) && c.containsValue(true))
            System.out.println("This is a forest");
        else System.out.println("This is something else");
    }

    ArrayList<Vertex<T>> verts = new ArrayList<>();

   // ArrayList<Pair<Vertex<T>, Vertex<T>>> tree = new ArrayList<>();
    HashMap<Vertex<T>, Vertex<T>> tree = new HashMap<>();

    HashMap<Vertex<T>, List<Pair<Vertex<T>, Double>>> q = new HashMap<>();

    public void Prim(T data) {
        Double min = 100000.0;
        Vertex<T> d = new Vertex<>(data);
        if (adjactencyList.containsKey(d) && visited.containsValue(false)) {
            List<Pair<Vertex<T>, Double>> l = adjactencyList.get(d);
            q.put(d, l);
            for (Vertex<T> p : q.keySet()) {
                List<Pair<Vertex<T>, Double>> t = adjactencyList.get(p);
                for (Pair<Vertex<T>, Double> pr : t) {
                    if (pr.getValue() < min)
                        min = pr.getValue();
                }
            }

            for (Vertex<T> p : q.keySet()) {
                List<Pair<Vertex<T>, Double>> t = adjactencyList.get(p);
                for (Pair<Vertex<T>, Double> pr : t) {
                    if (pr.getValue() == min) {
                       // Pair<Vertex<T>, Vertex<T>> np = new Pair<>(p, pr.getKey());
                        tree.put(p, pr.getKey());
                        visited.put(p.getData(), true);
                        Prim(pr.getKey().getData());
                        //visited.put(p.getData(), true);
                    }
                }
            }
        }
        else return;
    }

    // dfs for finding components

    HashMap<T, Boolean> used = new HashMap<>(); //

    ArrayList<T> components = new ArrayList<>();

    public void  dfs(T data) {
        visited.put(data, true);
        components.add(data);
        for (Pair<Vertex<T>, Double> p : adjactencyList.get(new Vertex<>(data))) {
            if (used.get(p.getKey().getData()) == false)
                dfs(p.getKey().getData());
        }
    }

    // working shit
    public void findComps() {
        preps();

        for (Vertex<T> v: adjactencyList.keySet()) {
            if (visited.get(v.getData()) == false) {
                components.clear();
                dfsModifed1(v.getData());

                for (T c: components) {
                    System.out.println(" " + c);
                    System.out.println("\n");
                }
            }
        }
    }

    public void printTree() {
        for (Vertex<T> p: tree.keySet()) {
            System.out.println(p.getData() + " " + tree.get(p).getData());
        }
    }
}

