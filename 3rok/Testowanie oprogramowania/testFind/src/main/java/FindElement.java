import java.util.List;

public class FindElement {
    public static int Find(List<Integer> list, int szukanyElement) {
        if (list == null) {
            throw new IllegalArgumentException("List cannot be null");
        }
        return list.indexOf(szukanyElement);
    }
}