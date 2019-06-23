package com.andyyyha;

import com.andyyyha.graph.Graph;
import com.andyyyha.graph.Vertex;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.SQLOutput;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String fileName;
        Graph<Integer> graph = null;
        BufferedReader bf;
        Scanner sc = new Scanner(System.in);

        while (graph == null) {
            try {
               // System.out.println("Enter filename ");
                fileName = "graph.txt";
                bf = new BufferedReader(new FileReader(fileName));

                String line = null;
                String[] vertices = null;
                int u, v;

                graph = new Graph<Integer>();

                while ((line = bf.readLine()) != null) {
                    vertices = line.split(" ");
                    if (vertices.length != 2) {
                        System.out.println("Incorrect file format");
                        bf.close();
                        graph = null;
                        break;
                    }
                    u = Integer.parseInt(vertices[0]);
                    v = Integer.parseInt(vertices[1]);
                    //   double w = Double.parseDouble(vertices[2]);
                    graph.addEdge(u, v);
                }
                bf.close();
            } catch (IOException e) {

            }
        }
        sc.close();
   //     graph.findComps();
        graph.print();
    }
}
