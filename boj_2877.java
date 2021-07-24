import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int k,t,i;
		k = Integer.parseInt(br.readLine());
		t = 1;
        Stack<Integer> stack = new Stack<>(); 
		while(true) {
			if(k<=Math.pow(2,t)) {
				k--;
				for(i=0;i<t;i++) {
					if(k%2==0) {
						stack.add(4);
					}else {
						stack.add(7);
					}
					k/=2;
				}
				break;
			}else {
				k -= Math.pow(2,t++);
			}
		}
		while(!stack.isEmpty()) sb.append(stack.pop());
		System.out.println(sb);
	}
}
