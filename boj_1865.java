import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static ArrayList<Node> node;
	static int n;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,m,k,i,s,e,w;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			node = new ArrayList<Node>();
			for(i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
				w = Integer.parseInt(st.nextToken());
				node.add(new Node(s,e,w));
				node.add(new Node(e,s,w));
			}
			for(i=0;i<k;i++) {
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
				w = Integer.parseInt(st.nextToken());
				node.add(new Node(s,e,-w));
			}
			sb.append(bellman()+"\n");
		}
		System.out.println(sb);
	}
	
	public static String bellman() {
		int[] dist = new int[n+1];
		Arrays.fill(dist,1000000000);
		dist[1] = 0;
		for(int i=1;i<=n;i++) {
			for(Node N : node) {
				if(dist[N.e]>dist[N.s]+N.w) dist[N.e] = dist[N.s]+N.w;
			}
		}
		for(Node N : node) {
			if(dist[N.e]>dist[N.s]+N.w) {
				return "YES";
			}
		}
		return "NO";
	}
}

class Node {
	int s,e,w;
	
	public Node(int s, int e, int w) {
		this.s = s;
		this.e = e;
		this.w = w;
	}
}
