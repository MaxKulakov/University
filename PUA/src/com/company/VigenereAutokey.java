package com.company;

import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

public class VigenereAutokey implements Cypher {
    private String alphabet = "йцукенгшщзфывапролджэёячсмитьбю,.!?:;1234567890 ";
    private String key = "";
    private String encrypyedMsg = "";
    HashMap<Integer, Character> d = new HashMap<>();
    private List<Integer> keyValues = new ArrayList<>();
    private List<Integer> textValues = new ArrayList<>();
    private List<Integer> encryptedCodes = new ArrayList<>();
    private List<Integer> decryptedCodes = new ArrayList<>();

    @Override
    public void createKey(String msg) throws IOException {
        msg = msg.toLowerCase();
        Random r = new Random();

        for (int i = 0; i < alphabet.length(); i++) {
            d.put(i, alphabet.charAt(i));
        }

        char c = alphabet.charAt(r.nextInt(alphabet.length()));
        key += c;

        StringBuilder keySb = new StringBuilder(key);
        int nextLetter;
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < alphabet.length(); j++) {
                if (msg.charAt(i) == alphabet.charAt(j)) {
                    textValues.add(j);
                }
                if (keySb.charAt(i) == alphabet.charAt(j)) {
                    keyValues.add(j);
                }
            }
            nextLetter = (textValues.get(i) + keyValues.get(i) + 1) % alphabet.length();

            keySb.append(alphabet.charAt(nextLetter));
        }
        keySb.deleteCharAt(keySb.length() - 1);
        key = keySb.toString();
    }

    private HashMap<Integer, Pair<Integer, Integer>> comparator(List<Integer> keys, List<Integer> values) {
        HashMap<Integer, Pair<Integer, Integer>> dic = new HashMap<>();
        for (int i = 0; i < key.length(); i++) {
            dic.put(i, new Pair<>(keys.get(i), values.get(i)));
        }
        return dic;
    }

    private String decodeNumbers(List<Integer> numbers) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numbers.size(); i++) {
            for (Integer j: d.keySet()) {
                int i1 = numbers.get(i);
                if (i1 == j)
                    sb.append(d.get(j));
            }
        }
        return sb.toString();
    }
    @Override
    public String encryptMsg(String msg) {
        HashMap<Integer, Pair<Integer, Integer>> dic = comparator(textValues, keyValues);
        comparator(textValues, keyValues);
        for (Integer i: dic.keySet()) {
            int next = (dic.get(i).getKey() + dic.get(i).getValue()) % d.size();
            encryptedCodes.add(next);
        }
        encrypyedMsg = decodeNumbers(encryptedCodes);
        return encrypyedMsg;
    }

    @Override
    public String decryptMsg(String msg) {
        if (encryptedCodes.isEmpty()) {
            for (int i = 0; i < msg.length(); i++) {
                for (int j = 0; j < alphabet.length(); j++) {
                    if (msg.charAt(i) == alphabet.charAt(j))
                        encryptedCodes.add(j);
                }
            }
        }
        HashMap<Integer, Pair<Integer, Integer>> dic = comparator(encryptedCodes, keyValues);
        comparator(encryptedCodes, keyValues);
        for (Integer i: dic.keySet()) {
            int next = (dic.get(i).getKey() - dic.get(i).getValue() + d.size()) % d.size();
            decryptedCodes.add(next);
        }
        return decodeNumbers(decryptedCodes);
    }

    @Override
    public void writeKeyToFile() throws IOException {
        FileOutputStream fileOutputStream = new FileOutputStream("VigenereKey.txt");
        byte[] strToBytes = key.getBytes();
        fileOutputStream.write(strToBytes);
    }

    @Override
    public void createKeyFromFile() throws IOException {
        if (d.isEmpty()) {
            for (int i = 0; i < alphabet.length(); i++) {
                d.put(i, alphabet.charAt(i));
            }
        }
        BufferedReader br = new BufferedReader(new FileReader("/Users/andryyyha/IdeaProjects/Cryptography/VigenereKey.txt"));
        String al = br.readLine();
        key = al;
        for (int i = 0; i < al.length(); i++) {
            for (int j = 0; j < alphabet.length(); j++) {
                if (al.charAt(i) == alphabet.charAt(j))
                    keyValues.add(j);
            }
        }
    }
}
