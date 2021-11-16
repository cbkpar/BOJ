import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        boolean[][][] chk = new boolean[A + 1][B + 1][C + 1];
        chk[0][0][C] = true;
        Queue<water> q = new LinkedList<>();
        q.add(new water(0, 0, C));
        while (!q.isEmpty()) {
            water w = q.poll();
            int tmp = Math.min(w.a, B - w.b);
            if (!chk[w.a - tmp][w.b + tmp][w.c]) {
                chk[w.a - tmp][w.b + tmp][w.c] = true;
                q.add(new water(w.a - tmp, w.b + tmp, w.c));
            }
            tmp = Math.min(w.a, C - w.c);
            if (!chk[w.a - tmp][w.b][w.c + tmp]) {
                chk[w.a - tmp][w.b][w.c + tmp] = true;
                q.add(new water(w.a - tmp, w.b, w.c + tmp));
            }
            tmp = Math.min(w.b, A - w.a);
            if (!chk[w.a + tmp][w.b - tmp][w.c]) {
                chk[w.a + tmp][w.b - tmp][w.c] = true;
                q.add(new water(w.a + tmp, w.b - tmp, w.c));
            }
            tmp = Math.min(w.b, C - w.c);
            if (!chk[w.a][w.b - tmp][w.c + tmp]) {
                chk[w.a][w.b - tmp][w.c + tmp] = true;
                q.add(new water(w.a, w.b - tmp, w.c + tmp));
            }
            tmp = Math.min(w.c, A - w.a);
            if (!chk[w.a + tmp][w.b][w.c - tmp]) {
                chk[w.a + tmp][w.b][w.c - tmp] = true;
                q.add(new water(w.a + tmp, w.b, w.c - tmp));
            }
            tmp = Math.min(w.c, B - w.b);
            if (!chk[w.a][w.b + tmp][w.c - tmp]) {
                chk[w.a][w.b + tmp][w.c - tmp] = true;
                q.add(new water(w.a, w.b + tmp, w.c - tmp));
            }
        }
        for (int i = 0; i <= C; i++) {
            for (int j = 0; j <= B; j++) {
                if (chk[0][j][i]) {
                    sb.append(i + " ");
                    break;
                }
            }
        }
        System.out.println(sb.toString().trim());
    }
}

class water {
    int a;
    int b;
    int c;

    public water(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}
