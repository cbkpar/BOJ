import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,i,m,p,q;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[] presum = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) presum[i] = Integer.parseInt(st.nextToken())%2;
		for(i=1;i<=n;i++) presum[i] += presum[i-1];
		m = Integer.MAX_VALUE;
		p = 0;
		q = 1;
		while(q<=n) {
			if(presum[q]-presum[p]>=k) {
				m = Math.min(m, q-p);
				p++;
			}else {
				q++;
			}
		}
		System.out.println(m==Integer.MAX_VALUE?"-1":m);
	}
}
