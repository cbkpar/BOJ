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
		m = Integer.parseInt(st.nextToken());
		arr = new long[n];
		sz = 1;
		for(int i=1;i<n;i*=2) {
			if(i>=n) break;
			sz++;
		}
		sz = (int)Math.pow(2, sz);
		tree = new long[sz+1];
		init(0,n-1,1);
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			if(Integer.parseInt(st.nextToken())==0) {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken())-1;
				if(a>b) {
					int tmp = a;
					a = b;
					b = tmp;
				}
				sb.append(sum(a,b,1,0,n-1)+"\n");
			}else {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken());
				long diff = b-arr[a];
				arr[a] = b;
				update(0,n-1,1,a,diff);
			}
		}
		System.out.println(sb);
	}
	
	static long init(int l, int r, int index) {
		if(l==r) return tree[index] = arr[l];
		int mid = (l+r)/2;
		return tree[index] = init(l,mid,index) + init(mid+1,r,index);
	}
	
	static void update(int l, int r, int idx ,int node, long diff) {
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
