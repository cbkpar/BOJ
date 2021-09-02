import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sz;
	static long[] arr;
	static long[] tree;
	static long[] index;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new long[n];
		for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		sz = 1;
		for(int i=1;i<n;i*=2) {
			if(i>=n) break;
			sz++;
		}
		sz = (int)Math.pow(2, sz);
		tree = new long[sz+1];
		Map<Long, Integer> map = new HashMap<>();
		for(int i=0;i<n;i++) map.put(arr[i],i);
		index = arr.clone();
		Arrays.sort(index);
		long ans = 0;
		for(int i=0;i<n;i++) {
			int idx = map.get(index[i]);
			ans += sum(idx+1,n-1,1,0,n-1);
			update(0,n-1,1,idx);
		}
		System.out.println(ans);
	}
	static long update(int l, int r, int index ,int cindex) {
		if(l>cindex||cindex>r) return tree[index];
		if(l==r) return tree[index] = 1;
		int mid = (l+r)/2;
		return tree[index] = update(l,mid,index*2,cindex)+update(mid+1,r,index*2+1,cindex);
	}
	
	static long sum(int l, int r, int index, int nodel, int noder) {
		if(r<nodel||noder<l) return 0;
		if(l<=nodel&&noder<=r) return tree[index];
		int mid = (nodel+noder)/2;
		return sum(l,r,index*2,nodel,mid)+sum(l,r,index*2+1,mid+1,noder);
	}
}
