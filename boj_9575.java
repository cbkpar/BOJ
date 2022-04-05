import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int nA = Integer.parseInt(br.readLine());
            int[] A = new int[nA];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < nA; i++) A[i] = Integer.parseInt(st.nextToken());
            int nB = Integer.parseInt(br.readLine());
            int[] B = new int[nB];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < nB; i++) B[i] = Integer.parseInt(st.nextToken());
            int nC = Integer.parseInt(br.readLine());
            int[] C = new int[nC];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < nC; i++) C[i] = Integer.parseInt(st.nextToken());
            HashSet<Integer> set = new HashSet<>();
            int cnt = 0;
            for (int i = 0; i < nA; i++) {
                for (int j = 0; j < nB; j++) {
                    for (int k = 0; k < nC; k++) {
                        int sum = A[i] + B[j] + C[k];
                        if (set.contains(sum)) continue;
                        set.add(sum);
                        cnt += check(sum);
                    }
                }
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }

    private static int check(int num) {
        while (num > 0) {
            if (num % 10 == 5 || num % 10 == 8) {
                num /= 10;

            } else {
                return 0;
            }
        }
        return 1;
    }
}
