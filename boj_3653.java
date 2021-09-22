import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, sz;
    static int[] tree;
    static int[] arr;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t, k, i, j;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            sz = (int) Math.pow(2, (int) Math.ceil(Math.log10(n + m + 2) / Math.log10(2)) + 1);
            tree = new int[sz];
            arr = new int[n + 1];
            for (i = 1; i <= n; i++) arr[i] = m + i;
            init(0, n + m + 1, 1);
            st = new StringTokenizer(br.readLine());
            for (j = 0; j < m; j++) {
                k = Integer.parseInt(st.nextToken());
                sb.append(sum(0, n + m + 1, 1, 0, arr[k] - 1));
                update(0, n + m + 1, 1, arr[k], -1);
                update(0, n + m + 1, 1, m - j, 1);
                arr[k] = m - j;
                if (j != m-1) sb.append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static int init(int l, int r, int idx) {
        if (l == r) return tree[idx] = l > m ? 1 : 0;
        int mid = (l + r) / 2;
        return tree[idx] = init(l, mid, idx * 2) + init(mid + 1, r, idx * 2 + 1);
    }

    static void update(int l, int r, int idx, int node, int diff) {
        if (l > node || node > r) return;
        tree[idx] += diff;
        if (l == r) return;
        int mid = (l + r) / 2;
        update(l, mid, idx * 2, node, diff);
        update(mid + 1, r, idx * 2 + 1, node, diff);
    }

    static long sum(int l, int r, int idx, int start, int end) {
        if (end < l || start > r) return 0;
        if (l >= start && end >= r) return tree[idx];
        int mid = (l + r) / 2;
        return sum(l, mid, idx * 2, start, end) + sum(mid + 1, r, idx * 2 + 1, start, end);
    }
}
