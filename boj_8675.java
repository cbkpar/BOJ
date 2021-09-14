import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,cnt;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		long[] a = new long[n+1];
		long[] b = new long[m+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) a[i] = a[i-1] + Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=m;i++) b[i] = b[i-1] + Integer.parseInt(st.nextToken());
		cnt = 0;
		while(true) {
			if(a[n]==b[m]) break;
			if(a[n]>b[m]) {
				n--;
			}else {
				m--;
			}
			cnt++;
		}
		System.out.println(cnt);
	}
}
