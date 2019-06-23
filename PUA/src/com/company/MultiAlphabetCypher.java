package com.company;

import javafx.util.Pair;

import java.io.IOException;
import java.util.*;

public class MultiAlphabetCypher implements Cypher {
    private String alphabet = "абвгдежзийклмнопрстуфхчцшщъыьэюя";
    private NavigableMap<Character, List<Character>> key = new TreeMap<>();
    private List<Character> firstHalf = new ArrayList<>();
    private LinkedList<Character> secondHalf = new LinkedList<>();
    private String keyword;

    public MultiAlphabetCypher(String keyword) {
        try {
            this.createKey("");
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.keyword = keyword;
    }

    @Override
    public void createKey(String msg) throws IOException {
        for (int i = 0; i < alphabet.length() / 2; i++) {
            firstHalf.add(alphabet.charAt(i));
        }
        for (int i = (alphabet.length() / 2); i < alphabet.length(); i++) {
            secondHalf.add(alphabet.charAt(i));
        }
        LinkedList<Character> copy = new LinkedList<>(secondHalf);
        key.put(alphabet.charAt(0), firstHalf);
        key.put(alphabet.charAt(1), copy);
        for (int i = 2; i < alphabet.length(); i++) {
            if (i % 2 == 1) {
                LinkedList<Character> c = new LinkedList<>(secondHalf);
                secondHalf = shift(c);
                key.put(alphabet.charAt(i), c);
                int kk = 0;
            } else
                key.put(alphabet.charAt(i), firstHalf);
        }
    }

    private LinkedList<Character> shift(LinkedList<Character> l) {
        char el = l.getFirst();
        l.removeFirst();
        l.addLast(el);
        return l;
    }

    @Override
    public String encryptMsg(String msg) {
        msg = msg.toLowerCase().replaceAll("[^\\p{L}\\p{Nd}]+", "");
        StringBuilder sb = new StringBuilder();
        String newKeyword;
        StringBuilder sb1 = new StringBuilder(keyword);
        int j = 0;
        while (sb1.length() < msg.length()) {
            if (j >= keyword.length())
                j = 0;
            sb1.append(keyword.charAt(j));
            j++;
        }
        newKeyword = sb1.toString();
        String denLetters;
        StringBuilder encryptedMsg = new StringBuilder();
        for (int i = 0; i < alphabet.length(); i++) {
            if (i % 2 == 1)
                sb.append(alphabet.charAt(i));
        }
        denLetters = sb.toString();
        List<Pair<Character, Character>> keywordAndMessage = new ArrayList<>();
        for (int i = 0; i < msg.length(); i++) {

            keywordAndMessage.add(new Pair<>(newKeyword.charAt(i), msg.charAt(i)));
        }
        for (Pair<Character, Character> k : keywordAndMessage) {
            if (denLetters.indexOf(k.getKey()) >= 0)
                encryptedMsg.append(getPrev(k.getKey(), k.getValue()));
            else
                encryptedMsg.append(getNext(k.getKey(), k.getValue()));
        }
        return encryptedMsg.toString();
    }

    private char getPrev(Character c, Character v) {
        List<Character> cur = key.get(c);
        Map.Entry<Character, List<Character>> prev = key.lowerEntry(c);
        if (cur.contains(v)) {
            return prev.getValue().get(cur.indexOf(v));
        }
        else {
            return cur.get((prev.getValue().indexOf(v)));
        }
    }

    private char getNext(Character c, Character v) {
        List<Character> cur = key.get(c);
        Map.Entry<Character, List<Character>> prev = key.higherEntry(c);
        if (cur.contains(v)) {
            return prev.getValue().get(cur.indexOf(v));
        }
        else {
            return cur.get(prev.getValue().indexOf(v));
        }
    }

    @Override
    public String decryptMsg(String msg) {

        return null;
    }

    @Override
    public void writeKeyToFile() throws IOException {

    }

    @Override
    public void createKeyFromFile() throws IOException {

    }
}
