import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<node>[] arr = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<>();
        int q = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            arr[s].add(new node(e, w));
            arr[e].add(new node(s, w));
        }
        while (q-- > 0) {
            int cnt = 0;
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            boolean[] chk = new boolean[n + 1];
            Queue<Integer> qu = new LinkedList<>();
            qu.add(v);
            chk[v] = true;
            while (!qu.isEmpty()) {
                int num = qu.poll();
                for (node N : arr[num]) {
                    if (N.w >= k && !chk[N.e]) {
                        chk[N.e] = true;
                        cnt++;
                        qu.add(N.e);
                    }
                }
            }
            sb.append(cnt + "\n");
        }
        System.out.println(sb);
    }
}

class node {
    int e;
    int w;

    public node(int e, int w) {
        this.e = e;
        this.w = w;
    }
}
