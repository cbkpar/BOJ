import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        int sz = str.length();
        int mi = 'Z';
        for (int i = 0; i < sz; i++) mi = Math.min(mi, str.charAt(i));
        if (mi <= 'C') {
            for (int i = 0; i < sz; i++) {
                sb.append((str.charAt(i) <= 'F' && str.charAt(i) != 'E') ? (char) mi : str.charAt(i));
            }
        } else {
            for (int i = 0; i < sz; i++) sb.append('A');
        }
        System.out.println(sb);
    }
}
