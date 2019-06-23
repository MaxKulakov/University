package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class CaesarCypher implements Cypher {

    private List<Integer> A = new ArrayList<>();
    private List<Integer> B = new ArrayList<>();
    private String alphabet = "йцукенгшщзхъфывапролджэёячсмитьбю1234567890!?.,;:- ";
    private int k;
    private int n;
    private int m;

    public CaesarCypher(String msg) { // создание n и m и заполнение массивов сообщения и зашифрованного сообщения нулями
        n = alphabet.length() + 1;
        m = alphabet.length();
        for (int i = 0; i < msg.length(); i++) {
            A.add(i, 0);
            B.add(i, 0);
        }
    }

    @Override
    public void createKey(String msg) throws IOException {

    }

    // Шифрование
    @Override
    public String encryptMsg(String msg) {
        StringBuilder message = new StringBuilder();
        // Генерация случайного k
        k = new Random().ints(1, 10).findFirst().getAsInt();
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < alphabet.length(); j++) {
                if (msg.charAt(i) == alphabet.charAt(j)) { // Шифрование по формуле
                    B.set(i, (j * n + k) % m);
                    A.set(i, j);
                }
            }
        }
        for (int i = 0; i < msg.length(); i++) {
            message.append(alphabet.charAt(B.get(i)));
        }
        return message.toString();
    }

    // Дешифрование
    @Override
    public String decryptMsg(String msg) {
        StringBuilder message = new StringBuilder();
        for (int i = 0; i < msg.length(); i++) { // Дешифровка
            int l = B.get(i) - k;
            if (l < 0) {
                l = B.get(i) + m - k;
            }
            message.append(alphabet.charAt(l));
        }
        return message.toString();
    }

    // Запись ключа в файл
    @Override
    public void writeKeyToFile() throws IOException {
        // Запись k в отдельный файл
        FileOutputStream fileOutputStream = new FileOutputStream("CaesarK.txt");
        String s = Integer.toString(k);
        byte[] strToBytes = s.getBytes();
        fileOutputStream.write(strToBytes);
        fileOutputStream.close();
        // Запись массива кодов зашифрованного сообщния
        BufferedWriter bw = new BufferedWriter(new FileWriter("CaesarKey.txt"));
        for (int el: B) {
            bw.write(Integer.toString(el));
            bw.newLine();
        }
        bw.close();
    }

    // Считывание ключа из файла
    @Override
    public void createKeyFromFile() throws IOException {
        // При начале новой сессии массив заполнен нулями, поэтому его следует очистить
        B.clear();
        // Считывание k
        BufferedReader br = new BufferedReader(new FileReader("/Users/andryyyha/IdeaProjects/Cryptography/CaesarK.txt"));
        String al = br.readLine();
        k = Integer.parseInt(al);
        br.close();
        // Считывание кодов шифра
        BufferedReader br1 = new BufferedReader(new FileReader("/Users/andryyyha/IdeaProjects/Cryptography/CaesarKey.txt"));
        String line;
        while ((line = br1.readLine()) != null) {
            B.add(Integer.parseInt(line));
        }
        br1.close();
    }
}
