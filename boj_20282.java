import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,mx,i;
		n = Integer.parseInt(br.readLine());
		mx = 0;
		int[] arr = new int[n+1];
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(br.readLine());
		for(i=0;i<=n;i++) mx = Math.max(mx, arr[i]);
		System.out.println(mx+100);
	}
}
