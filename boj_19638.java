import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,h,t,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(st.nextToken());
		PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
		while(n-->0) q.add(Integer.parseInt(br.readLine()));
		for(i=0;i<t;i++) {
			if(h>q.peek()) break;
			q.add((Math.max(1, q.poll()/2)));
		}
		if(h>q.peek()) {
			System.out.println("YES\n"+i);
		}else {
			System.out.println("NO\n"+q.peek());
		}
	}
}
