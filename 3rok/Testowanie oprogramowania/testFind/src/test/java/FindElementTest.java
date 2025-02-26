import java.util.Arrays;
import java.util.List;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class FindElementTest {

    @Test
    void testFindElementFound() {
        List<Integer> list = Arrays.asList(10, 20, 30, 40, 50);
        int szukanyElement = 30;
        int result = FindElement.Find(list, szukanyElement);
        assertEquals(2, result);
    }

    @Test
    void testFindElementNotFound() {
        List<Integer> list = Arrays.asList(10, 20, 30, 40, 50);
        int szukanyElement = 60;
        int result = FindElement.Find(list, szukanyElement);
        assertEquals(-1, result);
    }

    @Test
    void testFindEmptyList() {
        List<Integer> list = Arrays.asList();
        int szukanyElement = 10;
        int result = FindElement.Find(list, szukanyElement);
        assertEquals(-1, result);
    }

    @Test
    void testFindNullList() {
        List<Integer> list = null;
        int szukanyElement = 10;
        assertThrows(IllegalArgumentException.class, () -> FindElement.Find(list, szukanyElement));
    }
}
