import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sz;
	static final long mod = 1000000007;
	static long[] arr;
	static long[] tree;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int i;

		StringTokenizer st = new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		m+=Integer.parseInt(st.nextToken());
		
		arr = new long[n];
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
		
		sz = 1;
		for(i=1;i<n;i*=2) {
			if(i>=n) break;
			sz++;
		}
		sz = (int)Math.pow(2, sz);
		tree = new long[sz+1];
		init(0,n-1,1);

		for(i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			if(Integer.parseInt(st.nextToken())==1) {
				int b = Integer.parseInt(st.nextToken())-1;
				long c = Long.parseLong(st.nextToken());
				arr[b]=c;
				update(0,n-1,1,b,c);
			}else {
				int b = Integer.parseInt(st.nextToken())-1;
				int c = Integer.parseInt(st.nextToken())-1;
				sb.append(tmul(b,c,1,0,n-1)+"\n");
				
			}
		}
		System.out.println(sb.toString());
	}
	
	static long init(int l, int r, int index) {
		if(l==r) {
			tree[index] = arr[l];
		}else {
			int mid = (l+r)/2;
			tree[index] = (init(l,mid,index*2)*init(mid+1,r,index*2+1))%mod;
		}
		return tree[index];
	}
	
	static long update(int l, int r, int index ,int cindex, long val) {
		if(l>cindex||cindex>r) return tree[index];
		if(l==r) return tree[index] = val;
		int mid = (l+r)/2;
		return tree[index] = (update(l,mid,index*2,cindex,val)*update(mid+1,r,index*2+1,cindex,val))%mod;
	}
	
	static long tmul(int l, int r, int index, int nodel, int noder) {
		if(r<nodel||noder<l) return 1;
		if(l<=nodel&&noder<=r) return tree[index];
		int mid = (nodel+noder)/2;
		return (tmul(l,r,index*2,nodel,mid)*tmul(l,r,index*2+1,mid+1,noder))%mod;
	}
}
