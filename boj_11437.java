import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
    static ArrayList<Integer>[] node;
    static int[] parent;
    static int[] depth;
    static boolean[] chk;
    static int n;
    
	public static void main(String args[]) throws IOException {
		int i,s,e,m,d1,d2;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		chk = new boolean[n+1];
		node = new ArrayList[n+1];
		parent = new int[n+1];
		depth = new int[n+1];
		for(i=1;i<=n;i++) parent[i] = i;
		for(i=1;i<=n;i++) node[i] = new ArrayList<Integer>();
		for(i=1;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			node[s].add(e);
			node[e].add(s);
		}
		m = Integer.parseInt(br.readLine());
		chk[1] = true;
		dfs(1,0,1);
		while(m-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			d1 = depth[s];
			d2 = depth[e];
			if(d1>d2) {
				i = d1-d2;
				while(i-->0) s = parent[s];
			}else if(d2>d1) {
				i = d2-d1;
				while(i-->0) e = parent[e];
			}
			while(true) {
				if(s==e) break;
				s = parent[s];
				e = parent[e];
			}
			sb.append(s+"\n");
		}
		System.out.println(sb);
	}
	
	static void dfs(int k, int d, int p) {
		int sz = node[k].size();
		for(int i=0;i<sz;i++) {
			if(!chk[node[k].get(i)]) {
				chk[node[k].get(i)] = true;
				parent[node[k].get(i)] = k;
				depth[node[k].get(i)] = d+1;
				dfs(node[k].get(i),d+1,k);
			}
		}
	}
}
