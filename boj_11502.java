import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        boolean[] isprime = new boolean[1001];
        for (int i = 2; i * i <= 1000; i++) {
            for (int j = i * i; j <= 1000; j += i) {
                isprime[j] = true;
            }
        }
        ArrayList<Integer> prime = new ArrayList<>();
        for (int i = 2; i <= 1000; i++) if (!isprime[i]) prime.add(i);
        int[][] answer = new int[1001][3];
        int sz = prime.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i; j < sz; j++) {
                for (int k = j; k < sz; k++) {
                    int sum = prime.get(i) + prime.get(j) + prime.get(k);
                    if (sum < 1000) {
                        answer[sum][0] = prime.get(i);
                        answer[sum][1] = prime.get(j);
                        answer[sum][2] = prime.get(k);
                    }
                }
            }
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            if (answer[k][0] == 0) {
                sb.append("0\n");
            } else {
                sb.append(answer[k][0] + " " + answer[k][1] + " " + answer[k][2] + "\n");
            }
        }
        System.out.println(sb);
    }
}
