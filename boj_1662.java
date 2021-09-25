import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, t, s, i;
        String str = br.readLine();
        n = str.length();
        t = 1;
        s = 0;
        Stack<Integer> stack = new Stack<>();
        for (i = 0; i < n; i++) {
            if (str.charAt(i) == '(') {
                s -= t;
                stack.add(t);
                t *= str.charAt(i - 1) - '0';
            } else if (str.charAt(i) == ')') {
                t = stack.pop();
            } else {
                s += t;
            }
        }
        System.out.println(s);
    }
}
