import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int iN, iM;
    static long[] arr;
    static long[] tree;

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
        init(0, iN - 1, 1);
        while (iM-- > 0) {
            st = new StringTokenizer(br.readLine());
            if (st.nextToken().equals("1")) {
                int s = Integer.parseInt(st.nextToken()) - 1;
                long t = Long.parseLong(st.nextToken());
                long diff = t - arr[s];
                arr[s] = t;
                update(s, s, 0, iN - 1, 1, diff);
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

    private static void update(int l, int r, int start, int end, int idx, long diff) {
        if (l > end || start > r) return;
        tree[idx] += diff;
        if (start != end) {
            int mid = (start + end) / 2;
            update(l, r, start, mid, idx * 2, diff);
            update(l, r, mid + 1, end, idx * 2 + 1, diff);
        }
    }

    private static long search(int l, int r, int start, int end, int idx) {
        if (l > end || start > r) return 0;
        if (l <= start && end <= r) {
            return tree[idx];
        }
        int mid = (start + end) / 2;
        return search(l, r, start, mid, idx * 2) + search(l, r, mid + 1, end, idx * 2 + 1);
    }
}
