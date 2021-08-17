import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m;
	static long[] dist;
	static ArrayList<Node>[] node;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int i,s,e,w;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		node = new ArrayList[n+1];
		for(i=1;i<=n;i++) node[i] = new ArrayList<Node>();
		for(i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			node[s].add(new Node(e,w));
		}
		if(bellman()) {
			for(i=2;i<=n;i++) {
				if(dist[i]==1000000000) {
					sb.append("-1\n");
				}else {
					sb.append(dist[i]+"\n");
				}
			}
		}else {
			sb.append("-1\n");
		}
		System.out.println(sb);
	}
	
	public static boolean bellman() {
		dist = new long[n+1];
		Arrays.fill(dist,1000000000);
		dist[1] = 0;
		for(int i=1;i<n;i++) {
			for(int j=1;j<=n;j++) {
				for(int k=0;k<node[j].size();k++) {
					Node N = node[j].get(k);
					if(dist[j]!=1000000000&&dist[N.e]>dist[j]+N.w) dist[N.e] = dist[j]+N.w;
				}
			}
		}
		for(int j=1;j<=n;j++) {
			for(int k=0;k<node[j].size();k++) {
				Node N = node[j].get(k);
				if(dist[j]!=1000000000&&dist[N.e]>dist[j]+N.w) {
					return false;
				}
			}
		}
		return true;
	}
}

class Node {
	
	int e,w;
	
	public Node(int e, int w) {
		this.e = e;
		this.w = w;
	}
}
