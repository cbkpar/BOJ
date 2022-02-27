import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Stack<Integer> ans = new Stack<>();
        int tmp = -1;
        ans.add(-1);
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] == arr[i + 1]) {
                ans.add(tmp == -1 ? -1 : tmp);
            } else {
                tmp = i + 1;
                ans.add(tmp);
            }
        }
        while (!ans.isEmpty()) sb.append(ans.pop() + " ");
        System.out.println(sb);
    }
}
