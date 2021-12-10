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
        boolean[] isprime = new boolean[10000];
        for (int i = 2; i * i < 10000; i++) {
            for (int j = i * i; j < 10000; j += i) {
                isprime[j] = true;
            }
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            boolean[] visited = new boolean[10000];
            visited[start] = true;
            Queue<Integer> q = new LinkedList<>();
            q.add(start);
            int cnt = 0;
            boolean find = false;
            while (!q.isEmpty()) {
                int sz = q.size();
                while (sz-- > 0) {
                    int num = q.poll();
                    if (num == end) {
                        find = true;
                        break;
                    }
                    int exp = 1;
                    for (int i = 0; i < 4; i++) {
                        exp *= 10;
                        for (int j = 0; j < 10; j++) {
                            int tmp = (num / exp) * exp + (j * exp / 10) + num % (exp / 10);
                            if (tmp >= 1000 && tmp <= 9999) {
                                if (!isprime[tmp] && !visited[tmp]) {
                                    visited[tmp] = true;
                                    q.add(tmp);
                                }
                            }
                        }
                    }
                }
                if (find) break;
                cnt++;
            }
            if (find) {
                sb.append(cnt + "\n");
            } else {
                sb.append("Impossible\n");
            }
        }
        System.out.println(sb);
    }
}
