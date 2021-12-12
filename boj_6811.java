import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int bt = Integer.parseInt(br.readLine());
        int np = Integer.parseInt(br.readLine());
        int yp = Integer.parseInt(br.readLine());
        int tp = Integer.parseInt(br.readLine());
        int cnt = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                for (int k = 0; k <= 100; k++) {
                    if (i == 0 && j == 0 && k == 0) continue;
                    int sum = i * bt + j * np + k * yp;
                    if (sum <= tp) {
                        cnt++;
                        sb.append(i + " Brown Trout, " + j + " Northern Pike, " + k + " Yellow Pickerel\n");
                    }
                }
            }
        }
        sb.append("Number of ways to catch fish: " + cnt + '\n');
        System.out.println(sb);
    }
}
