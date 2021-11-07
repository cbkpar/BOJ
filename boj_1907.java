import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), "+=");
        int[][] arr = new int[3][3];
        for (int i = 0; i < 3; i++) {
            char[] ch = st.nextToken().toCharArray();
            int sz = ch.length;
            int tmp = 0;
            for (int j = 0; j < sz; j++) {
                if (ch[j] == 'C') {
                    tmp = 0;
                    arr[i][tmp]++;
                } else if (ch[j] == 'H') {
                    tmp = 1;
                    arr[i][tmp]++;
                } else if (ch[j] == 'O') {
                    tmp = 2;
                    arr[i][tmp]++;
                } else {
                    arr[i][tmp] += ch[j] - '1';
                }
            }
        }
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                for (int k = 1; k <= 10; k++) {
                    if (arr[0][0] * i + arr[1][0] * j != arr[2][0] * k) continue;
                    if (arr[0][1] * i + arr[1][1] * j != arr[2][1] * k) continue;
                    if (arr[0][2] * i + arr[1][2] * j != arr[2][2] * k) continue;
                    System.out.println(i + " " + j + " " + k);
                    return;
                }
            }
        }
    }
}
