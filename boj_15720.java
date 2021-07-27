import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,r,mi,s,d,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		mi = Math.min(Math.min(n, m), r);
		int[] a = new int[n];
		int[] b = new int[m];
		int[] c = new int[r];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) a[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(i=0;i<m;i++) b[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(i=0;i<r;i++) c[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(a);
		Arrays.sort(b);
		Arrays.sort(c);
		s = d = 0;
		for(i=0;i<n-mi;i++) {
			s += a[i];
			d += a[i];
		}
		for(i=n-mi;i<n;i++) {
			s += a[i];
			d += (a[i]/10)*9;
		}
		for(i=0;i<m-mi;i++) {
			s += b[i];
			d += b[i];
		}
		for(i=m-mi;i<m;i++) {
			s += b[i];
			d += (b[i]/10)*9;
		}
		for(i=0;i<r-mi;i++) {
			s += c[i];
			d += c[i];
		}
		for(i=r-mi;i<r;i++) {
			s += c[i];
			d += (c[i]/10)*9;
		}
		System.out.println(s+"\n"+d);
	}
}
