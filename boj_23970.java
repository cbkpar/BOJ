import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] A = new int[n];
        int[] B = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) B[i] = Integer.parseInt(st.nextToken());
        int cnt = 0;
        for (int i = 0; i < n; i++) if (A[i] == B[i]) cnt++;
        if (cnt == n) {
            System.out.println("1");
            return;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (A[j] > A[j + 1]) {
                    if (A[j] == B[j]) cnt--;
                    if (A[j + 1] == B[j + 1]) cnt--;
                    int tmp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = tmp;
                    if (A[j] == B[j]) cnt++;
                    if (A[j + 1] == B[j + 1]) cnt++;
                    if (cnt == n) {
                        System.out.println("1");
                        return;
                    }
                }
            }
        }
        System.out.println("0");
    }
}
