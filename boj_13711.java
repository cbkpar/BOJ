import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer stA = new StringTokenizer(br.readLine());
        StringTokenizer stB = new StringTokenizer(br.readLine());
        int[] B = new int[n];
        for (int i = 0; i < n; i++) B[Integer.parseInt(stB.nextToken()) - 1] = i;
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(-1);
        for (int i = 0; i < n; i++) {
            int t = B[Integer.parseInt(stA.nextToken()) - 1];
            if (t > arr.get(arr.size() - 1)) {
                arr.add(t);
            } else {
                int left = 0;
                int right = arr.size() - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (arr.get(mid) < t) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                arr.set(left, t);
            }
        }
        System.out.println(arr.size() - 1);
    }
}
