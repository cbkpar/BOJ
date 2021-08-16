import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,k;
	static long ans;
	static int[] arr;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[k];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<k;i++) arr[i] = Integer.parseInt(st.nextToken());
		ans = 0;
		dfs(0);
		System.out.println(ans);
	}
	
	public static void dfs(long num) {
		if(num>n) return;
		ans = Math.max(ans, num);
		for(int t : arr) dfs(num*10+t);
	}
}
