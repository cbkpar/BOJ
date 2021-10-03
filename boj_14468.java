import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, j, s, a, b, c, d;
        ArrayList<Integer>[] arr = new ArrayList[26];
        for (i = 0; i < 26; i++) arr[i] = new ArrayList<Integer>();
        String str = br.readLine();
        for (i = 0; i < 52; i++) arr[str.charAt(i) - 'A'].add(i);
        s = 0;
        for (i = 0; i < 25; i++) {
            a = arr[i].get(0);
            b = arr[i].get(1);
            for (j = i + 1; j < 26; j++) {
                c = arr[j].get(0);
                d = arr[j].get(1);
                if (a < c && b > c && b < d) s++;
                if (a > c && d > a && d < b) s++;
            }
        }
        System.out.println(s);
    }
}
