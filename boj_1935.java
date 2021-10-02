import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, sz, i;
        String str;
        n = Integer.parseInt(br.readLine());
        double[] arr = new double[n];
        str = br.readLine();
        for (i = 0; i < n; i++) arr[i] = Double.parseDouble(br.readLine());
        sz = str.length();
        Stack<Double> stack = new Stack<>();
        for (i = 0; i < sz; i++) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                stack.add(arr[str.charAt(i) - 'A']);
            } else if (str.charAt(i) == '+') {
                double a = stack.pop();
                double b = stack.pop();
                stack.add(a + b);
            } else if (str.charAt(i) == '-') {
                double a = stack.pop();
                double b = stack.pop();
                stack.add(b - a);
            } else if (str.charAt(i) == '/') {
                double a = stack.pop();
                double b = stack.pop();
                stack.add(b / a);
            } else {
                double a = stack.pop();
                double b = stack.pop();
                stack.add(a * b);
            }
        }
        System.out.printf("%.2f", stack.peek());
    }
}
