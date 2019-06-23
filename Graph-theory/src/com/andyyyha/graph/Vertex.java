package com.andyyyha.graph;

import java.util.Objects;

public class Vertex<T> {

    T data;
    boolean visited = false;

    public Vertex(T data, boolean visited) {
        this.data = data;
        this.visited = visited;
    }

    public Vertex() {
    }

    public Vertex(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }

    public Vertex(boolean visited) {
        this.visited = visited;
    }

    public void setData(T data) {
        this.data = data;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vertex<?> vertex = (Vertex<?>) o;
        return visited == vertex.visited &&
                Objects.equals(data, vertex.data);
    }

    @Override
    public int hashCode() {
        return Objects.hash(data, visited);
    }
}

