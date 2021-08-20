import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int s,n,k;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int r1,r2,c1,c2,i,j;
		StringTokenizer st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		r1 = Integer.parseInt(st.nextToken());
		r2 = Integer.parseInt(st.nextToken());
		c1 = Integer.parseInt(st.nextToken());
		c2 = Integer.parseInt(st.nextToken());
		for(i=r1;i<=r2;i++) {
			for(j=c1;j<=c2;j++) {
				if(chk(i,j,s-1)) {
					sb.append("1");
				}else {
					sb.append("0");
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
	
	public static boolean chk(int y, int x, int t) {
		if(t==-1) return false;
		int dist,dy,dx;
		dist = (int)Math.pow(n, t);
		dy = y/dist; 
		dx = x/dist;
		if(dy>=(n-k)/2&&dy<n-(n-k)/2&&dx>=(n-k)/2&&dx<n-(n-k)/2) {
			return true;
		}else {
			return chk(y%dist,x%dist,t-1);
		}
	}
}
