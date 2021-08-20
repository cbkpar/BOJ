import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,s,e,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] cnt = new int[n+1];
		Queue<Integer>[] q = new LinkedList[n+1];
		for(i=1;i<=n;i++) q[i] = new LinkedList<Integer>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			q[s].add(e);
			cnt[e]++;
		}
		Queue<Integer> qu = new LinkedList<Integer>();
		for(i=1;i<=n;i++) if(cnt[i]==0) qu.add(i);
		while(!qu.isEmpty()) {
			t = qu.poll();
			sb.append(t+" ");
			for(int k:q[t]) {
				cnt[k]--;
				if(cnt[k]==0) qu.add(k);
			}
		}
		System.out.println(sb);
	}
}
