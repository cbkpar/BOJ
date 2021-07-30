import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,a,t;
		long s;
		n = Integer.parseInt(br.readLine());
		Stack<assignment> stack = new Stack<>(); 
		s = 0;
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			if(k==1) {
				a = Integer.parseInt(st.nextToken());
				t = Integer.parseInt(st.nextToken());
				stack.add(new assignment(a,t));
			}
			if(!stack.isEmpty()) {
				assignment w = stack.pop();
				if(w.time>1) {
					stack.add(new assignment(w.score, w.time-1));
				}else {
					s += w.score;
				}
			}
			
		}
		System.out.println(s);
	}
	
	public static class assignment {
		int score;
		int time;
		
		public assignment(int score, int time) {
			this.score = score;
			this.time = time;
		}
	}
}
