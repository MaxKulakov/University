package com.company;

import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;

public class ADFGVXCypher implements Cypher {
    private HashMap<Character, HashMap<Character, Character>> encryptyonTable = new HashMap<>();
    private String keyword;
//    private char[] chars;

    public ADFGVXCypher(String keyword) {
        try {
            this.createKey("");
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.keyword = keyword;
    }

    @Override
    public void createKey(String msg) throws IOException {
        HashMap<Character, Character> A = new HashMap<>();
        HashMap<Character, Character> D = new HashMap<>();
        HashMap<Character, Character> F = new HashMap<>();
        HashMap<Character, Character> G = new HashMap<>();
        HashMap<Character, Character> V = new HashMap<>();
        HashMap<Character, Character> X = new HashMap<>();
        A.put('A', '1');
        A.put('D', 'J');
        A.put('F', 'R');
        A.put('G', '4');
        A.put('V', 'H');
        A.put('X', 'D');
        encryptyonTable.put('A', A);
        D.put('A', 'E');
        D.put('D', '2');
        D.put('F', 'A');
        D.put('G', 'V');
        D.put('V', '9');
        D.put('X', 'D');
        encryptyonTable.put('D', D);
        F.put('A', '8');
        F.put('D', 'P');
        F.put('F', 'I');
        F.put('G', 'N');
        F.put('V', 'K');
        F.put('X', 'Z');
        encryptyonTable.put('F', F);
        G.put('A', 'B');
        G.put('D', 'Y');
        G.put('F', 'U');
        G.put('G', 'F');
        G.put('V', '6');
        G.put('X', 'T');
        encryptyonTable.put('G', G);
        V.put('A', '5');
        V.put('D', 'G');
        V.put('F', 'X');
        V.put('G', 'S');
        V.put('V', '3');
        V.put('X', 'O');
        encryptyonTable.put('V', V);
        X.put('A', 'W');
        X.put('D', 'L');
        X.put('F', 'Q');
        X.put('G', '7');
        X.put('V', 'C');
        X.put('X', '0');
        encryptyonTable.put('X', X);
    }

    @Override
    public String encryptMsg(String msg) {
        msg = msg.toUpperCase().replaceAll("[^\\p{L}\\p{Nd}]+", "");
        StringBuilder firstRound = new StringBuilder();
        for (int i = 0; i < msg.length(); i++) {
            firstRound.append(getSymbol(msg.charAt(i)));
        }
//        int n = keyword.length() * keyword.length();
        int n = keyword.length() * 2;
        int m = keyword.length();
        char[][] tmp = new char[n][m];
        int i = 0;
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                if (i != firstRound.length()) {
                    tmp[k][j] = firstRound.charAt(i);
                    i++;
                } else
                    break;
            }
        }
        String alphabet = "adfgvxc".toUpperCase();
        char r = alphabet.charAt(new Random().nextInt(alphabet.length()));
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                if (tmp[k][j] == '\u0000')
                    tmp[k][j] = r;
            }
        }

        char[] chars = new char[m];
        for (int j = 0; j < m; j++) {
            chars[j] = keyword.charAt(j);
        }
        int f = 0;
        Arrays.sort(chars);
        HashMap<Integer, Integer> p = new HashMap<>();
        for (int j = 0; j < chars.length; j++) {
            p.put(j, keyword.indexOf(chars[j]));
        }
        char[][] orderedTable = new char[n][m];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                orderedTable[j][k] = tmp[j][p.get(k)];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                System.out.print(orderedTable[j][k]);
            }
            System.out.println();
        }

        StringBuilder res = new StringBuilder();
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                res.append(orderedTable[k][j]);
            }
        }
        return res.toString();
    }

    private String listToString(List<Character> l) {
        StringBuilder sb = new StringBuilder();
        for (Character c : l) {
            sb.append(c);
        }
        return sb.toString();
    }

    private String getSymbol(Character c) {
        StringBuilder sb = new StringBuilder();
        for (char k : encryptyonTable.keySet()) {
            for (char v : encryptyonTable.get(k).keySet()) {
                if (encryptyonTable.get(k).get(v) == c) {
                    sb.append(k);
                    sb.append(v);
                }
            }
        }
        return sb.toString();
    }

    @Override
    public String decryptMsg(String msg) {
        int n = keyword.length() * 2;
        int m = keyword.length();

        char[][] orderedTable = new char[n][m];
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                orderedTable[j][i] = msg.charAt(k);
                k++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(orderedTable[i][j]);
            }
            System.out.println();
        }

        char[] chars = new char[m];
        for (int j = 0; j < m; j++) {
            chars[j] = keyword.charAt(j);
        }
        Arrays.sort(chars);
        HashMap<Integer, Integer> p = new HashMap<>();
        for (int j = 0; j < chars.length; j++) {
            p.put(keyword.indexOf(chars[j]), j);
        }
        char[][] normTable = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                normTable[i][j] = orderedTable[i][p.get(j)];
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(normTable[i][j]);
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < sb.length() - 1; i+=2) {
            res.append(encryptyonTable.get(sb.charAt(i)).get(sb.charAt(i + 1)));
        }
        return res.toString();
    }



    @Override
    public void writeKeyToFile() throws IOException {
        FileOutputStream fo = new FileOutputStream("ADFKey.txt");
        byte[] b = keyword.getBytes();
        fo.write(b);
        fo.close();
    }

    @Override
    public void createKeyFromFile() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("ADFKey.txt"));
        keyword = br.readLine();
    }
}
