import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<Integer>[] arr;
    static int[] num;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int k = Integer.parseInt(br.readLine());
        arr = new ArrayList[k];
        for (int i = 0; i < k; i++) arr[i] = new ArrayList<Integer>();
        int sz = (1 << k) - 1;
        num = new int[sz];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < sz; i++) num[i] = Integer.parseInt(st.nextToken());
        divide(0, sz - 1, 0);
        for (int i = 0; i < k; i++) {
            sz = arr[i].size();
            sb.append(arr[i].get(0));
            for (int j = 1; j < sz; j++) sb.append(" " + arr[i].get(j));
            sb.append("\n");
        }
        System.out.println(sb);
    }

    private static void divide(int l, int r, int d) {
        arr[d].add(num[(l + r) / 2]);
        if (l == r) return;
        divide(l, (l + r) / 2 - 1, d + 1);
        divide((l + r) / 2 + 1, +r, d + 1);
    }
}
