import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,k,x,i,j,s,e,t,p,sz,qsz;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		ArrayList<Integer>[] node = new ArrayList[n+1];
		boolean[] visited = new boolean[n+1];
		for(i=1;i<=n;i++) node[i] = new ArrayList<Integer>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			node[s].add(e);
		}
		Queue<Integer> q = new LinkedList<>();
		q.add(x);
		visited[x] = true;
		t = 0;
		while(!q.isEmpty()) {
			if(t++==k) break;
			sz = q.size();
			for(i=0;i<sz;i++) {
				p = q.poll();
				qsz = node[p].size();
				for(j=0;j<qsz;j++) {
					if(!visited[node[p].get(j)]) {
						visited[node[p].get(j)] = true;
						q.add(node[p].get(j));
					}
				}
			}
		}
		if(q.isEmpty()) {
			sb.append("-1");
		}else {
			ArrayList<Integer> ans = new ArrayList<Integer>();
			while(!q.isEmpty()) ans.add(q.poll());
			Collections.sort(ans);
			for(int num:ans) sb.append(num+"\n");
		}
		System.out.println(sb);
	}
}
