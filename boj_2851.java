import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,d,ans;
		int[] arr = new int[11];
		d = 100;
		ans = 0;
		for(i=1;i<=10;i++) {
			arr[i] = arr[i-1] + Integer.parseInt(br.readLine());
			if(d>=Math.abs(arr[i]-100)) {
				d = Math.abs(arr[i]-100);
				ans = arr[i];
			}
		}
		System.out.println(ans);
	}
}
