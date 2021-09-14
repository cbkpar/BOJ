import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,ans,s,e;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+1];
		for(i=2;i<=n;i++) arr[i] = Integer.parseInt(br.readLine())+arr[i-1];;
		ans = 0;
		s = 1;
		while(m-->0) {
			e = Integer.parseInt(br.readLine());
			ans = (ans+Math.abs(arr[s+e]-arr[s]))%100000;
			s += e;
		}
		System.out.println(ans);
	}
}
