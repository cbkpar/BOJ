import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long lN = Long.parseLong(st.nextToken());
        long lR = Long.parseLong(st.nextToken());
        System.out.println(2 * lR + lN - 1);
    }
}
