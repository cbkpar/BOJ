import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,m,k;
		long t,ans;
		n = Integer.parseInt(br.readLine());
		long[] arr = new long[n];
		for(i=0;i<n;i++) arr[i] = Long.parseLong(br.readLine());
		Arrays.sort(arr);
		t = ans = arr[0];
		m = k = 1;
		for(i=1;i<n;i++) {
			if(t==arr[i]) {
				k++;
			}else {
				t = arr[i];
				k = 1;
			}
			if(k>m) {
				m = k;
				ans = t;
			}
		}
		System.out.println(ans);
	}
}
