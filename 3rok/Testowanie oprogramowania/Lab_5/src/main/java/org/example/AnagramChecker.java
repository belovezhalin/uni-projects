package org.example;
import java.util.Arrays;

public class AnagramChecker implements IAnagramChecker {

    @Override
    public boolean isAnagram(String word1, String word2) {
        if (word1 == null || word2 == null) {
            throw new NullPointerException("Input words cannot be null");
        }
        if (word1.isEmpty() || word2.isEmpty()) {
            throw new IllegalArgumentException("Input words cannot be empty");
        }

        String normalizedWord1 = word1.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        String normalizedWord2 = word2.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

        if (normalizedWord1.length() != normalizedWord2.length()) {
            return false;
        }

        char[] word1Chars = normalizedWord1.toCharArray();
        char[] word2Chars = normalizedWord2.toCharArray();
        Arrays.sort(word1Chars);
        Arrays.sort(word2Chars);

        return Arrays.equals(word1Chars, word2Chars);
    }
}
