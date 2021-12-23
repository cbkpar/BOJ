import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), "/");
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            int idx = 1;
            Stack<Integer> stack = new Stack<>();
            while (true) {
                if (p == 1 && q == 1) break;
                if (p > q) {
                    stack.add(1);
                    p -= q;

                } else {
                    stack.add(0);
                    q -= p;
                }
            }
            while (!stack.isEmpty()) {
                if (stack.pop() == 0) {
                    idx = idx * 2;
                } else {
                    idx = idx * 2 + 1;
                }
            }
            sb.append(idx + "\n");
        }
        System.out.println(sb);
    }
}
