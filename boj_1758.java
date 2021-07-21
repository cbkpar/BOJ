import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long ans;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		ans = 0;
		for(i=0;i<n;i++) ans += Math.max(0, arr[i]-n+i+1);
		System.out.println(ans);
	}
}
