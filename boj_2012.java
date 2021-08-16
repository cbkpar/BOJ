import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,cnt;
		long ans = 0;
		int[] arr = new int[500001];
		n = Integer.parseInt(br.readLine());
		for(i=0;i<n;i++) arr[Integer.parseInt(br.readLine())]++;
		cnt = 1;
		for(i=1;i<=500000;i++) {
			if(cnt==n+1) break;
			while(arr[i]-->0) {
				ans += Math.abs(cnt-i);
				cnt++;
			}
		}
		System.out.println(ans);
	}
}
