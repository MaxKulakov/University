package com.company;

import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        String filename = "msg.txt";
        BufferedReader bf = new BufferedReader(new FileReader(filename));
        BufferedReader br = new BufferedReader(new FileReader("key.txt"));
        String key = br.readLine();
        String line;
        Scanner sc = new Scanner(System.in);
        System.out.println("Выберите опцию");
        System.out.println("1: Создать ключ и зашфровать сообщение");
        System.out.println("2: Дешифровать сообщение");
        switch (sc.nextInt()) {
            case 1:
                while ((line = bf.readLine()) != null) {
                    ADFGVXCypher c = new ADFGVXCypher(key);
                    String encryptedMsg = c.encryptMsg(line);
                    FileOutputStream fo = new FileOutputStream("MAC.txt");
                    fo.write(encryptedMsg.getBytes());
                }
                break;
            case 2:
                BufferedReader bufferedReader = new BufferedReader(new FileReader("MAC.txt"));
                String l;
                while ((l = bufferedReader.readLine()) != null) {
                    ADFGVXCypher mc = new ADFGVXCypher(key);
                    String decryptedMsg = mc.decryptMsg(l);
                    FileOutputStream fo = new FileOutputStream("Decrypted.txt");
                    fo.write(decryptedMsg.getBytes());
                }
        }
    }
}
