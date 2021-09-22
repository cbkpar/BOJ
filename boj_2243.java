import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int m, sz;
    static long[] tree;
    static long[] lazy;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        sz = (int) Math.pow(2, (int) Math.ceil(Math.log10(1000000) / Math.log10(2)) + 1);
        tree = new long[sz];
        lazy = new long[sz];
        m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int ans = 1000000;
            if (st.nextToken().equals("1")) {
                int s = Integer.parseInt(st.nextToken());
                int left = 0;
                int right = 1000000;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (sum(0, 999999, 1, 0, mid) >= s) {
                        right = mid;
                        ans = Math.min(ans, mid);
                    } else {
                        left = mid + 1;
                    }
                }
                update(0, 999999, 1, ans, -1);
                sb.append((ans + 1) + "\n");
            } else {
                int s = Integer.parseInt(st.nextToken()) - 1;
                int t = Integer.parseInt(st.nextToken());
                update(0, 999999, 1, s, t);
            }
        }
        System.out.println(sb);
    }

    static void update(int l, int r, int idx, int num, long t) {
        propagate(idx, l, r);
        if (l > num || num > r) return;
        if (l >= num && num >= r) {
            lazy[idx] += t;
            propagate(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, idx * 2, num, t);
        update(mid + 1, r, idx * 2 + 1, num, t);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }

    static long sum(int l, int r, int idx, int start, int end) {
        propagate(idx, l, r);
        if (end < l || start > r) return 0;
        if (l >= start && end >= r) return tree[idx];
        int mid = (l + r) / 2;
        return sum(l, mid, idx * 2, start, end) + sum(mid + 1, r, idx * 2 + 1, start, end);
    }

    static void propagate(int idx, int start, int end) {
        if (lazy[idx] != 0) {
            tree[idx] += (end - start + 1) * lazy[idx];
            if (start != end) {
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
}
