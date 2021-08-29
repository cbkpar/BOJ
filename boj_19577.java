import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,ans,i,j,sq,p,q,tsq;
		n = Integer.parseInt(br.readLine());
		sq = (int)Math.sqrt(n);
		ans = Integer.MAX_VALUE;
		for(i=1;i<=sq;i++) {
			if(n%i==0) {
				p = q = i;
				tsq = (int)Math.sqrt(p);
				for(j=2;j<=tsq;j++) {
					if(p%j==0) {
						q /= j;
						q *= j-1;
						while(p%j==0) p/=j;
					}
				}
				if(p!=1) {
					q /= p;
					q *= p-1;
				}
				if(q*i==n) ans = Math.min(ans, i);
			}
			if(n%i==0) {
				p = q = n/i;
				tsq = (int)Math.sqrt(p);
				for(j=2;j<=tsq;j++) {
					if(p%j==0) {
						q /= j;
						q *= j-1;
						while(p%j==0) p/=j;
					}
				}
				if(p!=1) {
					q /= p;
					q *= p-1;
				}
				if(q*(n/i)==n) ans = Math.min(ans, (n/i));
			}
		}
		System.out.println(ans==Integer.MAX_VALUE?"-1":ans);
	}
}
