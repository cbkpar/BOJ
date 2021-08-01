import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,g,x,i,m,p,q;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[] presum = new int[1000001];
		while(n-->0) {
			st = new StringTokenizer(br.readLine());
			g = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			presum[x] = g;
		}
		for(i=1;i<=1000000;i++) presum[i] += presum[i-1];
		m = 0;
		for(i=0;i<=1000000;i++) {
			p = presum[Math.min(i+k,1000000)];
			q = (i-k-1>=0?presum[i-k-1]:0);
			m = Math.max(m, p-q);
		}
		System.out.println(m);
	}
}
