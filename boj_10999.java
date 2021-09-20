import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sz;
	static long[] arr;
	static long[] tree;
	static long[] lazy;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		m += Integer.parseInt(st.nextToken());
		arr = new long[n];
		for(int i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
		sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
		tree = new long[sz];
		lazy = new long[sz];
		init(0,n-1,1);
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			if(st.nextToken().equals("1")) {
				int s = Integer.parseInt(st.nextToken())-1;
				int e = Integer.parseInt(st.nextToken())-1;
				int t = Integer.parseInt(st.nextToken());
				update(0,n-1,1,s,e,t);
			}else {
				int s = Integer.parseInt(st.nextToken())-1;
				int e = Integer.parseInt(st.nextToken())-1;
				sb.append(sum(0,n-1,1,s,e)+"\n");
			}
		}
		System.out.println(sb);
	}
	
	static long init(int l, int r, int idx) {
		if(l==r) {
			tree[idx] = arr[l];
			return tree[idx];
		}
		int mid = (l+r)/2;
		return tree[idx] = init(l,mid,idx*2) + init(mid+1,r,idx*2+1);
	}
	
	static void update(int l, int r, int idx, int start, int end, long t) {
		propagate(idx,l,r);
		if(l>end||start>r) return;
		if(l>=start&&end>=r) {
			lazy[idx] += t;
			propagate(idx,l,r);
			return;
		}
		int mid = (l+r)/2;
		update(l,mid,idx*2,start,end,t);
		update(mid+1,r,idx*2+1,start,end,t);
		tree[idx] = tree[idx*2] + tree[idx*2+1];
	}
	
	static long sum(int l, int r, int idx, int start, int end) {
		propagate(idx,l,r);
		if(end<l||start>r) return 0;
		if(l>=start&&end>=r) return tree[idx];
		int mid = (l+r)/2;
		return sum(l,mid,idx*2,start,end)+sum(mid+1,r,idx*2+1,start,end);
	}
	
	static void propagate(int idx, int start, int end) {
		if(lazy[idx]!=0) {
			tree[idx] += (end-start+1)*lazy[idx];
			if(start!=end) {
				lazy[idx*2] += lazy[idx];
				lazy[idx*2+1] += lazy[idx];
			}
			lazy[idx] = 0;
		}
	}
}
