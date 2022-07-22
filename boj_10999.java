import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int iN, iM;
    static long[] arr;
    static long[] tree;
    static long[] lazy;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        iN = Integer.parseInt(st.nextToken());
        iM = Integer.parseInt(st.nextToken());
        iM += Integer.parseInt(st.nextToken());
        arr = new long[iN];
        for (int i = 0; i < iN; i++) arr[i] = Long.parseLong(br.readLine());
        int iTreeSize = (int) Math.pow(2, (int) Math.ceil(Math.log10(iN) / Math.log10(2)) + 1);
        tree = new long[iTreeSize];
        lazy = new long[iTreeSize];
        init(0, iN - 1, 1);
        while (iM-- > 0) {
            st = new StringTokenizer(br.readLine());
            if (st.nextToken().equals("1")) {
                int s = Integer.parseInt(st.nextToken()) - 1;
                int e = Integer.parseInt(st.nextToken()) - 1;
                long t = Long.parseLong(st.nextToken());
                update(s, e, 0, iN - 1, 1, t);
            } else {
                int s = Integer.parseInt(st.nextToken()) - 1;
                int e = Integer.parseInt(st.nextToken()) - 1;
                sb.append(search(s, e, 0, iN - 1, 1) + "\n");
            }
        }
        System.out.println(sb);
    }

    private static long init(int start, int end, int idx) {
        if (start == end) {
            tree[idx] = arr[start];
            return tree[idx];
        }
        int mid = (start + end) / 2;
        return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
    }

    private static void update(int l, int r, int start, int end, int idx, long t) {
        updatelazy(start, end, idx);
        if (l > end || start > r) return;
        if (l <= start && end <= r) {
            tree[idx] += (end - start + 1) * t;
            if (start != end) {
                lazy[idx * 2] += t;
                lazy[idx * 2 + 1] += t;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(l, r, start, mid, idx * 2, t);
        update(l, r, mid + 1, end, idx * 2 + 1, t);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }

    private static void updatelazy(int start, int end, int idx) {
        if (lazy[idx] != 0) {
            tree[idx] += (end - start + 1) * lazy[idx];
            if (start != end) {
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    private static long search(int l, int r, int start, int end, int idx) {
        updatelazy(start, end, idx);
        if (l > end || start > r) return 0;
        if (l <= start && end <= r) {
            return tree[idx];
        }
        int mid = (start + end) / 2;
        return search(l, r, start, mid, idx * 2) + search(l, r, mid + 1, end, idx * 2 + 1);
    }
}
