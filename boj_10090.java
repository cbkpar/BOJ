import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static long ans = 0;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        partition(0, n - 1);
        System.out.println(ans);
    }

    private static void merge(int left, int right) {
        int mid = (left + right) / 2;
        int[] tmp = new int[right - left + 1];
        int p = left;
        int q = mid + 1;
        int cnt = 0;
        while (p <= mid && q <= right) {
            if (arr[p] < arr[q]) {
                tmp[cnt++] = arr[p++];
            } else if (arr[p] > arr[q]) {
                ans += mid - p + 1;
                tmp[cnt++] = arr[q++];
            } else {
                tmp[cnt++] = arr[q++];
            }
        }
        while (p <= mid) tmp[cnt++] = arr[p++];
        while (q <= right) tmp[cnt++] = arr[q++];
        for (int i = 0; i < right - left + 1; i++) arr[left + i] = tmp[i];
    }

    private static void partition(int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            partition(left, mid);
            partition(mid + 1, right);
            merge(left, right);
        }
    }
}
