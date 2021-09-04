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
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
		tree = new int[sz];
		init(0,n-1,1);
		for(int i=m-1;i<=n-m;i++) sb.append(mx(i-m+1,i+m-1,1,0,n-1)+" ");
		System.out.println(sb);
	}
	
	static int init(int l, int r, int idx) {
		if(l==r) return tree[idx] = arr[l];
		int mid = (l+r)/2;
		return tree[idx] = Math.max(init(l,mid,idx*2),init(mid+1,r,idx*2+1));
	}
	
	static int mx(int l, int r, int idx, int start, int end) {
		if(r<start||end<l) return 0;
		if(l<=start&&end<=r) return tree[idx];
		int mid = (start+end)/2;
		return Math.max(mx(l,r,idx*2,start,mid), mx(l,r,idx*2+1,mid+1,end));
	}
}
