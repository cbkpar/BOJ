import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,j;
		n = Integer.parseInt(br.readLine());
		long[] arr = new long[n];
		for(i=0;i<n;i++) arr[i] = Long.parseLong(br.readLine());
		Arrays.sort(arr);
		HashSet<Long> set = new HashSet<Long>();
		for(i=0;i<n;i++) for(j=0;j<n;j++) set.add(arr[i]+arr[j]);
		for(i=n-1;i>0;i--) {
			for(j=i-1;j>=0;j--) {
				if(set.contains(arr[i]-arr[j])) {
					System.out.println(arr[i]);
					return;
				}
			}
		}
	}
}
