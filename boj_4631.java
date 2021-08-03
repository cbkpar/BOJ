import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,t;
		t = 1;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n==0) break;
			sb.append("SET "+(t++)+"\n");
			Stack<String> stack = new Stack<>(); 
			for(i=0;i<n;i++) {
				if(i%2==0) {
					sb.append(br.readLine()+"\n");
				}else {
					stack.add(br.readLine());
				}
			}
			while(!stack.isEmpty()) sb.append(stack.pop()+"\n");
		}
		System.out.println(sb);
	}
}
