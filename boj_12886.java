import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int sum = a + b + c;
        HashSet<Integer> set = new HashSet<>();
        set.add(a * 10000 + b);
        Queue<rock> q = new LinkedList<>();
        q.add(new rock(a, b));
        while (!q.isEmpty()) {
            rock r = q.poll();
            int[] arr = new int[3];
            arr[0] = r.a;
            arr[1] = r.b;
            arr[2] = sum - r.a - r.b;
            if (arr[0] == arr[1] && arr[1] == arr[2]) {
                System.out.println("1");
                return;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    if (arr[i] > arr[j]) {
                        if (set.contains((arr[i] - arr[j]) * 10000 + (arr[j] * 2))) continue;
                        set.add((arr[i] - arr[j]) * 10000 + (arr[j] * 2));
                        q.add(new rock(arr[i] - arr[j], arr[j] * 2));
                    }
                }
            }
        }
        System.out.println("0");
    }
}

class rock {
    int a;
    int b;

    public rock(int a, int b) {
        this.a = a;
        this.b = b;
    }
}
