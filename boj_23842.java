import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i <= 49; i++) {
            for (int j = i; i + j <= 99; j++) {
                int a = arr[i / 10] + arr[i % 10];
                int b = arr[j / 10] + arr[j % 10];
                int c = arr[(i + j) / 10] + arr[(i + j) % 10];
                if (a + b + c + 4 == n) {
                    System.out.println((i / 10) + "" + (i % 10) + "+" + (j / 10) + "" + (j % 10) + "=" + ((i + j) / 10) + "" + ((i + j) % 10));
                    return;
                }
            }
        }
        System.out.println("impossible");
    }
}
