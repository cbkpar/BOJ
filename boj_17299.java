import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,t;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		int[] ngf = new int[1000001];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			ngf[arr[i]]++;
		}
		Stack<Integer> stack = new Stack<>(); 
		for(i=n-1;i>=0;i--) {
			while(!stack.isEmpty()) {
				if(ngf[arr[i]]<ngf[stack.peek()]) break;
				stack.pop();
			}
			if(stack.isEmpty()) {
				t = -1;
			}else {
				t = stack.peek();
			}
			stack.add(arr[i]);
			arr[i] = t;
		}
		for(i=0;i<n;i++) sb.append(arr[i]+" ");
		System.out.println(sb);
	}
}
