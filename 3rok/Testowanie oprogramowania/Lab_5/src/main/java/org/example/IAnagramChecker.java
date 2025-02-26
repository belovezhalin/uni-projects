package org.example;

/**
 * Interfejs obiektu który sprawdza czy dane słowa są anagramami.
 * Anagram jest słowem lub frazą, która powstała
 * przez zmianę kolejności liter w oryginalnym słowie lub frazie.
 * Zobacz kilka przykładów na http://www.wordsmith.org/anagram/hof.html
 */
public interface IAnagramChecker {
    boolean isAnagram(String word1, String word2);
/** Sprawdza czy jedno slowo jest anagramem drugiego.
 * Wszystkie niealfanumeryczne znaki są ignorowane.
 * Wielkość liter nie ma znaczenia.
 * @param word1 dowolny niepusty string różny od null.
 * @param word2 dowolny niepusty string różny od null.
 * @return true wtedy i tylko wtedy gdy word1 jest anagramem word2.
 */
}
