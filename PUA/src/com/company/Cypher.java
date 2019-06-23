package com.company;

import java.io.IOException;

public interface Cypher {
    void createKey(String msg) throws IOException;
    String encryptMsg(String msg);
    String decryptMsg(String msg);
    void writeKeyToFile() throws IOException;
    void createKeyFromFile() throws IOException;
}
