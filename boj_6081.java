import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,s,e;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+1];
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(br.readLine());
		for(i=2;i<=n;i++) arr[i] += arr[i-1];
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			sb.append((arr[e]-arr[s-1])+"\n");
		}
		System.out.println(sb);
	}
}
