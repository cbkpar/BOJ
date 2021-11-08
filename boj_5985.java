import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static int[] arr;
    static int ans = 0;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = (int) Math.pow(2, Integer.parseInt(br.readLine()));
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        partition(0, n - 1, n * n / 2);
        sb.append(ans + "\n");
        for (int i = 0; i < n; i++) sb.append(arr[i] + "\n");
        System.out.println(sb);
    }

    private static void sort(int left, int right, int cnt) {
        Queue<Integer> q = new LinkedList<>();
        int mid = (left + right) / 2;
        if (arr[mid + 1] < arr[left]) {
            ans += cnt;
            for (int i = mid + 1; i <= right; i++) q.add(arr[i]);
            for (int i = left; i <= mid; i++) q.add(arr[i]);
            for (int i = left; i <= right; i++) arr[i] = q.poll();
        }
    }

    private static void partition(int left, int right, int cnt) {
        if (left < right) {
            int mid = (left + right) / 2;
            partition(left, mid, cnt / 4);
            partition(mid + 1, right, cnt / 4);
            sort(left, right, cnt);
        }
    }
}
