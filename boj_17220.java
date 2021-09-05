import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,cnt,i,s,e,sz,p;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<Integer>[] node = new ArrayList[n];
		boolean[] branch = new boolean[n];
		for(i=0;i<n;i++) node[i] = new ArrayList<Integer>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = st.nextToken().charAt(0)-'A';
			e = st.nextToken().charAt(0)-'A';
			node[s].add(e);
			branch[e] = true;
		}
		boolean[] chk = new boolean[n];
		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		while(m-->0) {
			s = st.nextToken().charAt(0)-'A';
			chk[s] = true;
		}
		Queue<Integer> q = new LinkedList<>();
		for(i=0;i<n;i++) {
			if(!branch[i]&&!chk[i]) q.add(i);
		}
		cnt = 0;
		while(!q.isEmpty()) {
			p = q.poll();
			sz = node[p].size();
			for(i=0;i<sz;i++) {
				if(!chk[node[p].get(i)]) {
					chk[node[p].get(i)] = true;
					q.add(node[p].get(i));
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}
}
