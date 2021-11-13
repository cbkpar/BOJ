import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static String str;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        int sz = str.length();
        for (int i = 0; i < sz; i++) {
            if (ispal(i, sz - 1)) {
                System.out.println(sz + i);
                return;
            }
        }
    }

    private static boolean ispal(int left, int right) {
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
}
