package com.company;

import java.io.*;
import java.util.*;

public class BlockCypher implements Cypher {

    public HashMap<Character, Character> key = new HashMap<>();

    @Override
    public void createKey(String msg) throws IOException {
        msg = msg.toLowerCase();
        HashSet<Character> alpabet = new HashSet<>();
        for (int i = 0; i < msg.length(); i++) {
            alpabet.add(msg.charAt(i));
        }

        ArrayList<Character> listOfChars = new ArrayList<>(alpabet);
        for (int i = 0; i < (listOfChars.size() / 2) + 1; i++) {
            key.put(listOfChars.get(i), null);
        }

        ArrayList<Character> diff = new ArrayList<>();
        for (Character c : listOfChars) {
            if (!key.containsKey(c))
                diff.add(c);
        }

        java.util.Collections.sort(diff);

        for (Character c : diff) {
            for (Character c1 : key.keySet()) {
                if (!key.containsValue(c) && key.get(c1) == null)
                    key.put(c1, c);
            }
        }

    }

    @Override
    public void writeKeyToFile() throws IOException {
        BufferedWriter bf = new BufferedWriter(new FileWriter("/Users/andryyyha/IdeaProjects/Cryptography/key.txt"));
        for (Character c : key.keySet()) {
            if (c == ' ') {
                String s = "_" + " " + key.get(c).toString();
                bf.write(s);
                bf.write("\n");
            } else if (key.get(c) == null) {
                String s = c.toString() + " " + "n";
                bf.write(s);
                bf.write("\n");
            } else {
                String s = c.toString() + " " + key.get(c).toString();
                bf.write(s);
                bf.write("\n");
            }
        }
        bf.close();
    }

    @Override
    public void createKeyFromFile() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/Users/andryyyha/IdeaProjects/Cryptography/key.txt"));
        String line;
        String[] keyValue;
        while ((line = br.readLine()) != null) {
            keyValue = line.split(" ");
            if (keyValue[0].equals("_")) {
                Character k = ' ';
                Character v = keyValue[1].charAt(0);
                key.put(k, v);
            } else {
                Character k = keyValue[0].charAt(0);
                Character v = keyValue[1].charAt(0);
                key.put(k, v);
            }
        }
    }

    public String encryptAndDecryptMessage(String msg) throws IOException {
        msg = msg.toLowerCase();
        createKeyFromFile();
        StringBuilder encryptedMsg = new StringBuilder();

        for (int i = 0; i < msg.length(); i++) {
            Character c = msg.charAt(i);
            if (key.containsKey(c) && key.get(c) == null)
                encryptedMsg.append(c);
            else {
                for (Map.Entry<Character, Character> cc : key.entrySet()) {
                    if (c.equals(cc.getKey())) {
                        encryptedMsg.append(cc.getValue());
                        break;
                    }
                    if (c.equals(cc.getValue())) {
                        encryptedMsg.append(cc.getKey());
                        break;
                    }
                }
            }
        }
        return encryptedMsg.toString();
    }

    @Override
    public String encryptMsg(String msg) {
        return null;
    }

    @Override
    public String decryptMsg(String msg) {
        return null;
    }
}
