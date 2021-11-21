import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static boolean ispossible = false;
    static int asz;
    static String A;
    static String B;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        A = br.readLine();
        B = br.readLine();
        asz = A.length();
        search(0, B.length() - 1, false);
        System.out.println(ispossible ? 1 : 0);
    }

    private static void search(int s, int e, boolean swap) {
        if (ispossible) return;
        if (e - s + 1 == asz) {
            StringBuilder sb = new StringBuilder();
            if (swap) {
                for (int i = e; i >= s; i--) sb.append(B.charAt(i));
            } else {
                for (int i = s; i <= e; i++) sb.append(B.charAt(i));
            }
            if (sb.toString().equals(A)) ispossible = true;
            return;
        }
        if (swap) {
            if (B.charAt(e) == 'B') search(s, e - 1, !swap);
            if (B.charAt(s) == 'A') search(s + 1, e, swap);
        } else {
            if (B.charAt(s) == 'B') search(s + 1, e, !swap);
            if (B.charAt(e) == 'A') search(s, e - 1, swap);
        }
    }
}
