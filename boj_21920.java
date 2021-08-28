import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,x,s;
		long ans;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(br.readLine());
		ans = s = 0;
		for(i=0;i<n;i++) {
			if(arr[i]>x) {
				if(gcd(x,arr[i])==1) {
					ans += arr[i];
					s++;
				}
			}else {
				if(gcd(arr[i],x)==1) {
					ans += arr[i];
					s++;
				}
			}
		}
		System.out.println((double)ans/s);

	}
	public static int gcd(int a, int b) {
		if(b%a==0) return a;
		return gcd(b%a, a);
	}
}
