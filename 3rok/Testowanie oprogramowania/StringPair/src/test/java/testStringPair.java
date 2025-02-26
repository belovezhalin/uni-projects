import org.example.StringPair;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class testStringPair {
    @Test
    public void testEqualsAndHashCode() {
        StringPair sp1 = new StringPair("left", "right");
        StringPair sp2 = new StringPair("left", "right");

        assertEquals(sp1, sp2);
        assertEquals(sp1.hashCode(), sp2.hashCode());
    }

    @Test
    public void testHashCodeRecalculation() {
        StringPair sp = new StringPair("left", "right");
        int initialHash = sp.hashCode();

        sp.setRight("newRight");
        assertNotEquals(initialHash, sp.hashCode());
    }

    @Test
    public void testNullSetters() {
        StringPair sp = new StringPair("left", "right");

        try {
            sp.setRight(null);
            fail("Expected IllegalArgumentException");
        } catch (IllegalArgumentException _) {}
    }
}
