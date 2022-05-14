import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iN = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iA = Integer.parseInt(st.nextToken());
        int iB = Integer.parseInt(st.nextToken());
        System.out.println(Math.min(iN, (iA / 2 + iB)));
    }
}
