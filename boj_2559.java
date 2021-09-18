import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,i,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		ans = Integer.MIN_VALUE;
		for(i=k;i<=n;i++) ans = Math.max(ans, arr[i]-arr[i-k]);
		System.out.println(ans);
	}
}
