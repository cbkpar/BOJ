import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,mx;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[m+1];
		st = new StringTokenizer(br.readLine());
		while(n-->0) arr[Integer.parseInt(st.nextToken())]++;
		mx = 0;
		for(i=1;i<=m;i++) mx = Math.max(mx, arr[i]);
		System.out.println(mx);
	}
}
