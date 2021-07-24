import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,i,sz;
		s = 0;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			sz = str.length();
			Stack<Character> stack = new Stack<>(); 
			for(i=0;i<sz;i++) {
				if(stack.isEmpty()) {
					stack.add(str.charAt(i));
				}else {
					if(str.charAt(i)==stack.peek()) {
						stack.pop();
					}else {
						stack.add(str.charAt(i));
					}
				}
			}
			if(stack.isEmpty()) s++;
		}
		System.out.println(s);
	}
}
