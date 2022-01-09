import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean win = false;
        if (Integer.parseInt(st.nextToken()) % 2 == 0) win = true;
        if (Integer.parseInt(st.nextToken()) % 2 == 0) win = true;
        System.out.println(win ? "A" : "B");
    }
}
