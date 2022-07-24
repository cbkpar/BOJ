import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int iN, iM;
    static long[] arr;
    static long[] treeSum;
    static long[] lazySum;
    static long[] treeMin;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        iN = Integer.parseInt(st.nextToken());
        iM = Integer.parseInt(st.nextToken());
        arr = new long[iN];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < iN; i++) arr[i] = Long.parseLong(st.nextToken());
        int iTreeSize = (int) Math.pow(2, (int) Math.ceil(Math.log10(iN) / Math.log10(2)) + 1);
        treeSum = new long[iTreeSize];
        lazySum = new long[iTreeSize];
        treeMin = new long[iTreeSize];
        init(0, iN - 1, 1);
        while (iM-- > 0) {
            st = new StringTokenizer(br.readLine());
            switch (st.nextToken().charAt(0)) {
                case 'M': {
                    int s = Integer.parseInt(st.nextToken()) - 1;
                    int e = Integer.parseInt(st.nextToken()) - 1;
                    sb.append(searchMin(s, e, 0, iN - 1, 1) + "\n");
                    break;
                }
                case 'P': {
                    int s = Integer.parseInt(st.nextToken()) - 1;
                    int e = Integer.parseInt(st.nextToken()) - 1;
                    int t = Integer.parseInt(st.nextToken());
                    update(s, e, 0, iN - 1, 1, t);
                    break;
                }
                case 'S': {
                    int s = Integer.parseInt(st.nextToken()) - 1;
                    int e = Integer.parseInt(st.nextToken()) - 1;
                    sb.append(searchSum(s, e, 0, iN - 1, 1) + "\n");
                    break;
                }
            }
        }
        System.out.println(sb);
    }

    private static void init(int start, int end, int idx) {
        if (start == end) {
            treeSum[idx] = arr[start];
            treeMin[idx] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        init(start, mid, idx * 2);
        init(mid + 1, end, idx * 2 + 1);
        treeSum[idx] = treeSum[idx * 2] + treeSum[idx * 2 + 1];
        treeMin[idx] = Math.min(treeMin[idx * 2], treeMin[idx * 2 + 1]);
    }

    private static void update(int l, int r, int start, int end, int idx, long t) {
        updatelazy(start, end, idx);
        if (l > end || start > r) return;
        if (l <= start && end <= r) {
            treeSum[idx] += (end - start + 1) * t;
            treeMin[idx] += t;
            if (start != end) {
                lazySum[idx * 2] += t;
                lazySum[idx * 2 + 1] += t;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(l, r, start, mid, idx * 2, t);
        update(l, r, mid + 1, end, idx * 2 + 1, t);
        treeSum[idx] = treeSum[idx * 2] + treeSum[idx * 2 + 1];
        treeMin[idx] = Math.min(treeMin[idx * 2], treeMin[idx * 2 + 1]);
    }

    private static void updatelazy(int start, int end, int idx) {
        if (lazySum[idx] != 0) {
            treeSum[idx] += (end - start + 1) * lazySum[idx];
            treeMin[idx] += lazySum[idx];
            if (start != end) {
                lazySum[idx * 2] += lazySum[idx];
                lazySum[idx * 2 + 1] += lazySum[idx];
            }
            lazySum[idx] = 0;
        }
    }

    private static long searchSum(int l, int r, int start, int end, int idx) {
        updatelazy(start, end, idx);
        if (l > end || start > r) return 0;
        if (l <= start && end <= r) {
            return treeSum[idx];
        }
        int mid = (start + end) / 2;
        return searchSum(l, r, start, mid, idx * 2) + searchSum(l, r, mid + 1, end, idx * 2 + 1);
    }

    private static long searchMin(int l, int r, int start, int end, int idx) {
        updatelazy(start, end, idx);
        if (l > end || start > r) return Long.MAX_VALUE;
        if (l <= start && end <= r) {
            return treeMin[idx];
        }
        int mid = (start + end) / 2;
        return Math.min(searchMin(l, r, start, mid, idx * 2), searchMin(l, r, mid + 1, end, idx * 2 + 1));
    }
}
