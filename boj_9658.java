import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] chk = new boolean[1001];
        chk[2] = chk[4] = true;
        for (int i = 5; i <= 1000; i++) if (!chk[i - 1] || !chk[i - 3] || !chk[i - 4]) chk[i] = true;
        System.out.println(chk[n]?"SK":"CY");
    }
}
