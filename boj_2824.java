import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,t;
		long ans;
		String str;
		n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) a[i] = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(br.readLine());
		int[] b = new int[m];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<m;i++) b[i] = Integer.parseInt(st.nextToken());
		ans = 1;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(a[i]<=b[j]) {
					t = gcd(a[i],b[j]);
				}else {
					t= gcd(b[j],a[i]);
				}
				if(t!=1) {
					a[i] /= t;
					b[j] /= t;
					ans = (ans*t)%100000000000L;
				}
			}
		}
		str = Long.toString(ans);
		if(str.length()>9) {
			System.out.println(str.substring(str.length()-9));
		}else {
			System.out.println(str);
		}
	}
	
	static int gcd(int a, int b) {
		if(b%a==0) return a;
		return gcd(b%a,a);
	}
}
