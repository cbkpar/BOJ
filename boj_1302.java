import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,m,t,k;
		n = Integer.parseInt(br.readLine());
		String[] arr = new String[n];
		for(i=0;i<n;i++) arr[i] = br.readLine();
		Arrays.sort(arr);
		m = t = 1;
		k = 0;
		for(i=1;i<n;i++) {
			if(arr[i].equals(arr[i-1])) {
				t++;
				if(t>m) {
					k = i;
					m = t;
				}
			}else {
				t = 1;
			}
		}
		System.out.println(arr[k]);
	}
}
