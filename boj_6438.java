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
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            Stack<Character> stack = new Stack<>();
            while (st.hasMoreTokens()) {
                char[] ch = st.nextToken().toCharArray();
                int sz = ch.length;
                if (!stack.isEmpty()) stack.add(' ');
                for (int i = 0; i < sz; i++) stack.add(ch[i]);
            }
            while (!stack.isEmpty()) sb.append(stack.pop());
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
