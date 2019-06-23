package com.company;

import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class PolibiusSquare implements Cypher {
    private char[][] key = new char[6][6];
    private String alphabet = "";

    @Override
    public void createKey(String msg) {
        msg = msg.toLowerCase();
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < msg.length(); i++) {
            set.add(msg.charAt(i));
        }

        for (char c: set) {
            alphabet = alphabet.concat(String.valueOf(c));
        }

        int k = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (k >= alphabet.length())
                    key[i][j] = '~';
                else {
                    key[i][j] = alphabet.charAt(k);
                    k++;
                }
            }
        }
    }

    public String findLetter(char c) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (key[i][j] == c) {
                    res.append(i);
                    res.append(j);
                }
            }
        }
        return res.toString();
    }

    @Override
    public String encryptMsg(String msg) {
        msg = msg.toLowerCase();
        String encryptedMsg = "";

        for (int i = 0; i < msg.length(); i++) {
            encryptedMsg = encryptedMsg.concat(findLetter(msg.charAt(i)));
        }

        return encryptedMsg;
    }

    @Override
    public String decryptMsg(String msg) {
        StringBuilder decryptedMsg = new StringBuilder();

        for (int i = 0; i < msg.length() - 1; i+= 2) {
            int i1 = Integer.parseInt(String.valueOf(msg.charAt(i)));
            int i2 = Integer.parseInt(String.valueOf(msg.charAt(i + 1)));
            decryptedMsg.append(key[i1][i2]);
        }
        return decryptedMsg.toString();
    }

    @Override
    public void writeKeyToFile() throws IOException {
        BufferedWriter bf = new BufferedWriter(new FileWriter("/Users/andryyyha/IdeaProjects/Cryptography/alphabet.txt"));
        bf.write(alphabet);
        bf.close();
    }

    @Override
    public void createKeyFromFile() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/Users/andryyyha/IdeaProjects/Cryptography/alphabet.txt"));
        String al = br.readLine();
        createKey(al);
    }
}
