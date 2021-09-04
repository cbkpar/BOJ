import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sz;
	static int[] arr;
	static int[] tree;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
		tree = new int[sz];
		init(0,n-1,1);
		m = Integer.parseInt(br.readLine());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			if(st.nextToken().equals("1")) {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken());
				arr[a] = b;
				update(0,n-1,1,a);
			}else {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken())-1;
				sb.append((search(a,b,1,0,n-1))+"\n");
			}
		}
		System.out.println(sb);
	}
	
	static int init(int l, int r, int idx) {
		if(l==r) return tree[idx] = arr[l];
		int mid = (l+r)/2;
		return tree[idx] = Math.min(init(l,mid,idx*2),init(mid+1,r,idx*2+1));
	}
	
	static int update(int l, int r, int idx, int node) {
		if(l>node||node>r) return tree[idx];
		if(l==r) return tree[idx] = arr[l];
		int mid = (l+r)/2;
		return tree[idx] = Math.min(update(l,mid,idx*2,node), update(mid+1,r,idx*2+1,node));
	}
	
	static int search(int l, int r, int idx, int start, int end) {
		if(r<start||end<l) return Integer.MAX_VALUE;
		if(l<=start&&end<=r) return tree[idx];
		int mid = (start+end)/2;
		return Math.min(search(l,r,idx*2,start,mid), search(l,r,idx*2+1,mid+1,end));
	}
}
