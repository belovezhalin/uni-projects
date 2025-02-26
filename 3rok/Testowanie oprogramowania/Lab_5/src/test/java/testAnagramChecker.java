import org.example.*;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class testAnagramChecker {
    private final IAnagramChecker anagramChecker = new AnagramChecker();

    @Test
    void testAnagramsBasic() {
        assertTrue(anagramChecker.isAnagram("save", "vase"));
        assertTrue(anagramChecker.isAnagram("earth", "heart"));
    }

    @Test
    void testAnagramsIgnoreCase() {
        assertTrue(anagramChecker.isAnagram("save", "VASE"));
        assertTrue(anagramChecker.isAnagram("Earth", "Heart"));
    }

    @Test
    void testAnagramsIgnoreSpecialCharacters() {
        assertTrue(anagramChecker.isAnagram("The eyes", "They see!"));
        assertTrue(anagramChecker.isAnagram("School master", "The classroom"));
    }

    @Test
    void testNotAnagramsDifferentLength() {
        assertFalse(anagramChecker.isAnagram("hello", "world"));
        assertFalse(anagramChecker.isAnagram("anagram", "ganaramm"));
        assertFalse(anagramChecker.isAnagram("abc", "cbaa"));
    }

    @Test
    void testAnagramsWithNumbers() {
        assertTrue(anagramChecker.isAnagram("12345", "54321"));
        assertFalse(anagramChecker.isAnagram("12345", "1234"));
    }

    @Test
    void testEmptyOrNullInput() {
        assertThrows(IllegalArgumentException.class, () -> anagramChecker.isAnagram("", "test"));
        assertThrows(IllegalArgumentException.class, () -> anagramChecker.isAnagram("test", ""));
        assertThrows(IllegalArgumentException.class, () -> anagramChecker.isAnagram("", ""));
        assertThrows(NullPointerException.class, () -> anagramChecker.isAnagram(null, null));
        assertThrows(NullPointerException.class, () -> anagramChecker.isAnagram(null, "test"));
        assertThrows(NullPointerException.class, () -> anagramChecker.isAnagram("test", null));
    }
}

