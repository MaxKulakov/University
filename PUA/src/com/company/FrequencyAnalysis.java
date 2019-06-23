package com.company;

import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.HashMap;

public class FrequencyAnalysis {
    private HashMap<Character, Integer> letterCount = new HashMap<>(); // мап для подсчета букв в тексте
    private HashMap<Character, Double> frequency = new HashMap<>(); // мап для подсчета частот

    public void processText() throws Exception {
        String alphabet = "йцукенгшщзхъфывапролджэёячсмитьбю";
        for (int i = 0; i < alphabet.length(); i++) { // инициализация мапов нулями
            letterCount.put(alphabet.charAt(i), 0);
            frequency.put(alphabet.charAt(i), 0.0);
        }
        String filename = "msg.txt";
        String text = new BufferedReader(new FileReader(filename)).readLine();
        for (int i = 0; i < text.length(); i++) { // считываю сообщение и подсчитваю буквы в тексте
            if (letterCount.containsKey(text.charAt(i))) {
                letterCount.put(text.charAt(i), letterCount.get(text.charAt(i)) + 1);
            }
        }
        // нахожу частоту появленя символа в тексте(варинт для ленивых
        // я делю на длинну текста с пробелами и знаками препинания, однако можно
        // с помощью регулярного выражения можно заменить пробелы и знаки препинания на пустые строки
        for (Character c : frequency.keySet()) {
            double v = letterCount.get(c) / (double) text.length();
            frequency.put(c, new BigDecimal(v).setScale(3, RoundingMode.HALF_UP).doubleValue());
        }
        // вывод в файл
        FileOutputStream out = new FileOutputStream("FreqOut.txt");
        for (Character c : frequency.keySet()) {
            String res = c + " " + frequency.get(c).toString() + "\n";
            byte[] b = res.getBytes();
            out.write(b);
            System.out.print(res);
        }
    }
}
