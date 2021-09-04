import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sz;
	static int[] arr;
	static int[][] tree;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken())%2;
		sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
		tree = new int[sz][2];
		init(0,n-1,1,0);
		init(0,n-1,1,1);
		m = Integer.parseInt(br.readLine());
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			if(t==1) {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken())%2;
				arr[a] = b;
				update(0,n-1,1,a,0);
				update(0,n-1,1,a,1);
			}else {
				int a = Integer.parseInt(st.nextToken())-1;
				int b = Integer.parseInt(st.nextToken())-1;
				sb.append(sum(a,b,1,0,n-1,(t+1)%2)+"\n");
			}
		}
		System.out.println(sb);
	}
	
	static int init(int l, int r, int idx, int n) {
		if(l==r) return tree[idx][n] = (arr[l]+n)%2;
		int mid = (l+r)/2;
		return tree[idx][n] = init(l,mid,idx*2,n) + init(mid+1,r,idx*2+1,n);
	}
	
	static int update(int l, int r, int idx, int node, int n) {
		if(l>node||node>r) return tree[idx][n];
		if(l==r) return tree[idx][n] = (arr[l]+n)%2;
		int mid = (l+r)/2;
		return tree[idx][n] = update(l,mid,idx*2,node,n)+update(mid+1,r,idx*2+1,node,n);
	}
	
	static int sum(int l, int r, int idx, int start, int end, int n) {
		if(r<start||end<l) return 0;
		if(l<=start&&end<=r) return tree[idx][n];
		int mid = (start+end)/2;
		return sum(l,r,idx*2,start,mid,n)+sum(l,r,idx*2+1,mid+1,end,n);
	}
}
