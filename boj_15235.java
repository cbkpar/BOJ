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
        int n, i, cnt;
        n = Integer.parseInt(br.readLine());
        int[] ans = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        Queue<people> q = new LinkedList<>();
        cnt = 1;
        for (i = 1; i <= n; i++) {
            q.add(new people(i, Integer.parseInt(st.nextToken())));
        }
        while (!q.isEmpty()) {
            people p = q.poll();
            if (--p.rest == 0) {
                ans[p.num] = cnt;
            } else {
                q.add(new people(p.num, p.rest));
            }
            cnt++;
        }
        for (i = 1; i < n; i++) sb.append(ans[i] + " ");
        sb.append(ans[n] + "\n");
        System.out.println(sb);
    }
}

class people {
    int num, rest;

    public people(int num, int rest) {
        this.num = num;
        this.rest = rest;
    }
}
