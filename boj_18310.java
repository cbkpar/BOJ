import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long m,a,b;
		int t,i;
		long[] arr = new long[100001];
		long[] cnt = new long[100001];
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n-->0) {
			t = Integer.parseInt(st.nextToken());
			arr[t] += t;
			cnt[t]++;
		}
		for(i=1;i<=100000;i++) arr[i] += arr[i-1];
		for(i=1;i<=100000;i++) cnt[i] += cnt[i-1];
		m = arr[100000]+1;
		t = 0;
		for(i=1;i<=100000;i++) {
			if(cnt[i]-cnt[i-1]==0) continue;
			a = (cnt[i]*i)-arr[i];
			b = arr[100000]-arr[i]-(cnt[100000]-cnt[i])*i;
			if(a+b<m) {
				m = a+b;
				t = i;
			}
		}
		System.out.println(t);
	}
}
