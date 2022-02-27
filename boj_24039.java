import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] isprime = new boolean[201];
        for (int i = 2; i * i <= 200; i++) {
            for (int j = i * i; j <= 200; j += i) {
                isprime[j] = true;
            }
        }
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 2; i <= 200; i++) if (!isprime[i]) arr.add(i);
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i <= 100; i++) {
            if (arr.get(i) * arr.get(i + 1) > n) {
                System.out.println(arr.get(i) * arr.get(i + 1));
                return;
            }
        }
    }
}
