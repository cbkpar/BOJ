import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sz;
	static long[] arr;
	static long[] tree;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		arr = new long[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
		tree = new long[sz];
		init(0,n-1,1);
		m = Integer.parseInt(br.readLine());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			if(st.nextToken().equals("1")) {
				int s = Integer.parseInt(st.nextToken())-1;
				int e = Integer.parseInt(st.nextToken())-1;
				int t = Integer.parseInt(st.nextToken());
				update(0,n-1,1,s,e,t);
			}else {
				int s = Integer.parseInt(st.nextToken())-1;
				sb.append(search(0,n-1,1,s,0)+"\n");
			}
		}
		System.out.println(sb);
	}
	
	static void init(int l, int r, int idx) {
		if(l==r) {
			tree[idx] = arr[l];
			return;
		}
		int mid = (l+r)/2;
		init(l,mid,idx*2);
		init(mid+1,r,idx*2+1);
	}
	
	static void update(int l, int r, int idx, int start,int end, int t) {
		if(l>end||start>r) return;
		if(l>=start&&end>=r) {
			tree[idx] += t;
			return;
		}
		int mid = (l+r)/2;
		update(l,mid,idx*2,start,end,t);
		update(mid+1,r,idx*2+1,start,end,t);
	}
	
	static long search(int l, int r, int idx, int node, long sum) {
		if(node<l||node>r) return 0;
		sum += tree[idx];
		if(l==r) return sum;
		int mid = (l+r)/2;
		return search(l,mid,idx*2,node,sum)+search(mid+1,r,idx*2+1,node,sum);
	}
}
