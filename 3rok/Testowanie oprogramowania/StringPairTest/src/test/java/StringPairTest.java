import junit.framework.*;
import org.example.StringPair;

import static org.junit.jupiter.api.Assertions.assertNotEquals;

public class StringPairTest extends TestCase {
    private static final StringPair one = new StringPair("One", "Two");
    private static final StringPair oneA = new StringPair("One", "Two");
    private static final StringPair two = new StringPair("Three", "Four");
    private static final StringPair twoA = new StringPair("Three", "Four");

    public static Test suite() {
        return new TestSuite(StringPairTest.class);
    }

    public StringPairTest(String name) {
        super(name);
    }

    /**
     * Test equals method.
     * Naprawy:
     * 1. Dodano sprawdzanie wyników `equals` przy użyciu `assertTrue` i `assertFalse`.
     * 2. Sprawdzono, że obiekt równy samemu sobie zwraca true.
     * 3. Uwzględniono testy dla różnych obiektów, które powinny zwracać false.
     */
    public void testEquals() {
        assertTrue("Equal objects should return true", one.equals(oneA));
        assertTrue("Equal objects should return true", oneA.equals(one));
        assertFalse("Different objects should return false", one.equals(two));
        assertFalse("Different objects should return false", two.equals(one));
        assertTrue("Object should equal itself", one.equals(one));
    }

    /**
     * Test constructor.
     * Naprawy:
     * 1. Dodano `assertNotNull`, aby upewnić się, że konstruktor zwraca nie-nullowy obiekt.
     * 2. Dodano testy na upewnienie się, że wartości lewej i prawej strony nie są null.
     */
    public void testConstructor() {
        StringPair localSubject = new StringPair("One", "Two");
        assertNotNull("Constructor should create non-null object", localSubject);
        assertNotNull("Left value should not be null", localSubject.getLeft());
        assertNotNull("Right value should not be null", localSubject.getRight());
    }

    /**
     * Test setting and getting right value.
     * Naprawy:
     * 1. Dodano sprawdzanie, czy wartość `right` jest poprawnie ustawiana i pobierana.
     * 2. Zastąpiono ogólne `assertTrue` konkretnym `assertEquals` dla lepszej kontroli.
     */
    public void testRightValue() {
        one.setRight("Three");
        assertEquals("Right value should be updated correctly", "Three", one.getRight());
    }

    /**
     * Test setting and getting left value.
     * Naprawy:
     * 1. Analogiczne poprawki jak w `testRightValue` dla `left`.
     */
    public void testLeftValue() {
        one.setLeft("Four");
        assertEquals("Left value should be updated correctly", "Four", one.getLeft());
    }

    /**
     * Test not equals.
     * Naprawy:
     * 1. Usunięto ręczne rzucanie wyjątków i zastąpiono je `assertFalse`.
     * 2. Dodano testy dla nierównych obiektów w obu kierunkach.
     */
    public void testNotEquals() {
        assertFalse("Objects with different values should not be equal", one.equals(two));
        assertFalse("Objects with different values should not be equal", two.equals(one));
    }

    /**
     * Test hashCode contract.
     * Naprawy:
     * 1. Dodano testy weryfikujące kontrakt metody `hashCode`:
     *    - Równe obiekty mają ten sam hash.
     *    - Różne obiekty mają różne hashe.
     */
    public void testHashCode() {
        assertEquals("Equal objects should have the same hash code", one.hashCode(), oneA.hashCode());
        assertNotEquals(Float.parseFloat("Different objects should have different hash codes"), one.hashCode(), two.hashCode());
    }

    /**
     * Test setting values.
     * Naprawy:
     * 1. Usunięto `System.out.println` i zastąpiono go asercjami.
     * 2. Sprawdzono, czy wartości są poprawnie ustawiane dla obu pól.
     */
    public void testSetValues() {
        one.setRight("ROne");
        one.setLeft("LOne");
        assertEquals("Right value should be ROne", "ROne", one.getRight());
        assertEquals("Left value should be LOne", "LOne", one.getLeft());
    }

    /**
     * Test null protection in constructor.
     * Naprawy:
     * 1. Dodano blok `try-catch`, aby upewnić się, że rzucany jest `NullPointerException`.
     * 2. Usunięto błędne założenie, że test z wyjątkiem zawsze kończy się niepowodzeniem.
     */
    public void testNullPointerProtection() {
        try {
            new StringPair(null, "Four");
            fail("Constructor should throw NullPointerException for null left value");
        } catch (NullPointerException e) {
            // expected
        }

        try {
            new StringPair("One", null);
            fail("Constructor should throw NullPointerException for null right value");
        } catch (NullPointerException e) {
            // expected
        }
    }
}
