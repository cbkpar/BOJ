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
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new long[n];
		sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
		tree = new long[sz];
		init(0,n-1,1);
		m = Integer.parseInt(st.nextToken());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			if(st.nextToken().equals("1")) {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken());
				arr[a] += b;
				update(0,n-1,1,a,b);
			}else {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken())-1;
				sb.append(sum(a,b,1,0,n-1)+"\n");
			}
		}
		System.out.println(sb);
	}
	
	static long init(int l, int r, int idx) {
		if(l==r) return tree[idx];
		int mid = (l+r)/2;
		return tree[idx] = init(l,mid,idx*2)+init(mid+1,r,idx*2+1);
	}
	
	static void update(int l, int r, int idx, int node, long diff) {
		if(l>node||node>r) return;
		tree[idx] += diff;
		if(l==r) return;
		int mid = (l+r)/2;
		update(l,mid,idx*2,node,diff);
		update(mid+1,r,idx*2+1,node,diff);
	}
	
	static long sum(int l, int r, int idx, int start, int end) {
		if(r<start||end<l) return 0;
		if(l<=start&&end<=r) return tree[idx];
		int mid = (start+end)/2;
		return sum(l,r,idx*2,start,mid)+sum(l,r,idx*2+1,mid+1,end);
	}
}
