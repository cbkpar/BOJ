import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        boolean[] chk = new boolean[100001];
        int[][] ways = new int[100001][2];
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        chk[n] = true;
        ways[n][0] = 1;
        int cur = 0;
        int cnt = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int p = q.poll();
                if (p == k) {
                    System.out.println(cnt + "\n" + ways[k][cur]);
                    return;
                }
                if (p - 1 >= 0) {
                    ways[p - 1][(cur + 1) % 2] += ways[p][cur];
                    if (!chk[p - 1]) {
                        chk[p - 1] = true;
                        q.add(p - 1);
                    }
                }
                if (p + 1 <= 100000) {
                    ways[p + 1][(cur + 1) % 2] += ways[p][cur];
                    if (!chk[p + 1]) {
                        chk[p + 1] = true;
                        q.add(p + 1);
                    }
                }
                if (p * 2 <= 100000) {
                    ways[p * 2][(cur + 1) % 2] += ways[p][cur];
                    if (!chk[p * 2]) {
                        chk[p * 2] = true;
                        q.add(p * 2);
                    }
                }
            }
            cnt++;
            cur = (cur + 1) % 2;
        }
    }
}
