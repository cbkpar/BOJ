import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i;
		t = Integer.parseInt(br.readLine());
		for(i=1;i<=t;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			Stack<String> stack = new Stack<>();
			while(st.hasMoreTokens()) stack.add(st.nextToken());
			sb.append("Case #"+i+":");
			while(!stack.isEmpty()) sb.append(" "+stack.pop());
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
