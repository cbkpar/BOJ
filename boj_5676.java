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
		int i;
		String str;
		while((str=br.readLine())!=null) {
			StringTokenizer st = new StringTokenizer(str);
			n=Integer.parseInt(st.nextToken());
			m=Integer.parseInt(st.nextToken());
			arr = new int[n];
			st = new StringTokenizer(br.readLine());
			for(i=0;i<n;i++) {
				int t = Integer.parseInt(st.nextToken());
				if(t>0) {
					arr[i] = 1;
				}else if(t==0) {
					arr[i] = 0;
				}else {
					arr[i] = -1;
				}
			}
			sz = 1;
			for(i=1;i<n;i*=2) {
				if(i>=n) break;
				sz++;
			}
			sz = (int)Math.pow(2, sz);
			tree = new int[sz+1];
			init(0,n-1,1);
			
			for(i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				if(st.nextToken().equals("C")) {
					int b = Integer.parseInt(st.nextToken())-1;
					int t = Integer.parseInt(st.nextToken());
					if(t>0) t = 1;
					if(t<0) t = -1;
					update(0,n-1,1,b,t);
				}else {
					int b = Integer.parseInt(st.nextToken())-1;
					int c = Integer.parseInt(st.nextToken())-1;
					int t = tmul(b,c,1,0,n-1);
					if(t>0) {
						sb.append("+");
					}else if(t==0) {
						sb.append("0");
					}else {
						sb.append("-");
					}
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
	
	static int init(int l, int r, int index) {
		if(l==r) return tree[index] = arr[l];
		int mid = (l+r)/2;
		return tree[index] = init(l,mid,index*2)*init(mid+1,r,index*2+1);
	}
	
	static int update(int l, int r, int idx ,int node, int val) {
		if(l>node||node>r) return tree[idx];
		if(l==r) return tree[idx] = val;
		int mid = (l+r)/2;
		return tree[idx] = update(l,mid,idx*2,node,val)*update(mid+1,r,idx*2+1,node,val);
	}
	
	static int tmul(int l, int r, int index, int start, int end) {
		if(r<start||end<l) return 1;
		if(l<=start&&end<=r) return tree[index];
		int mid = (start+end)/2;
		return tmul(l,r,index*2,start,mid)*tmul(l,r,index*2+1,mid+1,end);
	}
}
