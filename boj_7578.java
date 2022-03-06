import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    static long[] tree;
    static long[] lazy;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int sz = (int) Math.pow(2, (int) Math.ceil(Math.log10(n) / Math.log10(2)) + 1);
        tree = new long[sz];
        lazy = new long[sz];

        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) map.put(Integer.parseInt(st.nextToken()), i);
        st = new StringTokenizer(br.readLine());
        long total = 0;
        for (int i = 0; i < n; i++) {
            int e = map.get(Integer.parseInt(st.nextToken()));
            total += sum(0, n - 1, 1, e, e);
            update(0, n - 1, 1, 0, e, 1);
        }
        System.out.println(total);
    }

    static void update(int l, int r, int idx, int start, int end, long t) {
        propagate(idx, l, r);
        if (l > end || start > r) return;
        if (l >= start && end >= r) {
            lazy[idx] += t;
            propagate(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, idx * 2, start, end, t);
        update(mid + 1, r, idx * 2 + 1, start, end, t);
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
