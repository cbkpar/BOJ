import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        boolean chk = false;
        if (a == b) chk = true;
        if (b == c) chk = true;
        if (c == a) chk = true;
        if (a == b + c) chk = true;
        if (b == a + c) chk = true;
        if (c == a + b) chk = true;
        System.out.println(chk ? "S" : "N");
    }
}
