import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int sz;
        String str = br.readLine();
        sz = str.length();
        Stack<Integer> stack = new Stack<>();
        long tmp, ans;
        ans = 0;
        tmp = 1;
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == '(') {
                tmp *= 2;
                stack.add(1);
            } else if (str.charAt(i) == '[') {
                tmp *= 3;
                stack.add(2);
            } else if (str.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    System.out.println("0");
                    return;
                } else {
                    if (stack.peek() == 2) {
                        System.out.println("0");
                        return;
                    } else {
                        stack.pop();
                        if (str.charAt(i - 1) == '(') ans += tmp;
                        tmp /= 2;
                    }
                }
            } else {
                if (stack.isEmpty()) {
                    System.out.println("0");
                    return;
                } else {
                    if (stack.peek() == 1) {
                        System.out.println("0");
                        return;
                    } else {
                        stack.pop();
                        if (str.charAt(i - 1) == '[') ans += tmp;
                        tmp /= 3;
                    }
                }
            }
        }
        if(!stack.isEmpty()){
            System.out.println("0");
            return;
        }
        System.out.println(ans);
    }
}
