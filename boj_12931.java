import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,s,t;
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		Queue<Integer> q = new LinkedList<>();
		for(i=0;i<n;i++) {
			t = Integer.parseInt(st.nextToken());
			if(t!=0) q.add(t);
		}
		s = 0;
		while(true) {
			n = q.size();
			for(i=0;i<n;i++) {
				t = q.poll();
				if(t%2==1) s++;
				t/=2;
				if(t!=0) q.add(t);
			}
			if(q.isEmpty()) break;
			s++;
		}
		System.out.println(s);
	}
}
