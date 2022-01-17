import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        Stack<Integer>[] stack = new Stack[7];
        for (int i = 1; i <= 6; i++) stack[i] = new Stack<Integer>();
        for (int i = 1; i <= 6; i++) stack[i].add(-1);
        int ans = 0;
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int prat = Integer.parseInt(st.nextToken());
            while (!stack[num].isEmpty()) {
                if (stack[num].peek() <= prat) break;
                ans++;
                stack[num].pop();
            }
            if (stack[num].peek() != prat) {
                ans++;
                stack[num].add(prat);
            }
        }
        System.out.println(ans);
    }
}
