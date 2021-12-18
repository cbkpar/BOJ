import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        Stack<Character> stack = new Stack<>();
        int sz = str.length();
        for (int i = 0; i < sz; i++) {
            if (stack.isEmpty()) {
                stack.add(str.charAt(i));
            } else {
                if (stack.peek() == '(' && str.charAt(i) == ')') {
                    stack.pop();
                } else {
                    stack.add(str.charAt(i));
                }
            }
        }
        System.out.println(stack.size());
    }
}
