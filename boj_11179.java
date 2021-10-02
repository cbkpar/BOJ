import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, t, ans;
        n = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        while (n > 0) {
            stack.add(n % 2);
            n /= 2;
        }
        ans = 0;
        t = 1;
        while (!stack.isEmpty()) {
            ans += stack.pop() * t;
            t *= 2;
        }
        System.out.println(ans);
    }
}
