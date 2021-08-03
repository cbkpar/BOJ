import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,t;
		String str = br.readLine();
		sz = str.length();
		Stack<Integer> stack = new Stack<>(); 
		for(i=0;i<sz;i++) {
			if(str.charAt(i)>='0'&&str.charAt(i)<='9') {
				stack.add(str.charAt(i)-'0');
			}else if(str.charAt(i)=='+') {
				stack.add(stack.pop() + stack.pop());
			}else if(str.charAt(i)=='-') {
				stack.add(-stack.pop() + stack.pop());
			}else if(str.charAt(i)=='*') {
				stack.add(stack.pop() * stack.pop());
			}else {
				t = stack.pop();
				stack.add(stack.pop()/t);
			}
		}
		System.out.println(stack.pop());
	}
}
