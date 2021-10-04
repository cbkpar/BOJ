import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n, sz, i;
        n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        sz = str.length();
        for (i = 0; i < sz; i += n) sb.append(str.charAt(i));
        System.out.println(sb);
    }
}
