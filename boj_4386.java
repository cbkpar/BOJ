import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	
	static int[] par;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j,cnt,sz;
		double ans;
		n = Integer.parseInt(br.readLine());
		par = new int[n+1];
		for(i=1;i<=n;i++) par[i] = i;
		double[][] pos = new double[n][2];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			pos[i][0] = Double.parseDouble(st.nextToken());
			pos[i][1] = Double.parseDouble(st.nextToken());
		}
		ArrayList<node> arr = new ArrayList<>();
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				arr.add(new node(i,j,Math.sqrt(Math.pow(pos[i][0]-pos[j][0], 2)+Math.pow(pos[i][1]-pos[j][1], 2))));
			}
		}
		Collections.sort(arr, new Comparator<node>() {
			@Override
			public int compare(node o1, node o2) {
				if(o1.w < o2.w) {
					return -1;
				}else {
					return 1;
				}
			}
		});
		cnt = 0;
		ans = 0;
		sz = arr.size();
		for(i=0;i<sz;i++) {
			if(cnt==n-1) break;
			node N = arr.get(i);
			if(find(N.s)==find(N.e)) continue;
			union(N.s,N.e);
			ans += N.w;
			cnt++;
		}
		System.out.println(ans);
	}
	
	public static int find(int x) {
		if(par[x]==x) return x;
		return find(par[x]);
	}
	
	public static void union(int a, int b) {
		a = find(a);
		b = find(b);
		par[a] = b;
	}
}

class node {
	int s,e;
	double w;
	public node(int s, int e, double w) {
		this.s = s;
		this.e = e;
		this.w = w;
	}
}
