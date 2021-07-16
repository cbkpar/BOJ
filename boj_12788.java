import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i;
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		m *= Integer.parseInt(st.nextToken());
		Integer[] arr = new Integer[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr,Collections.reverseOrder());
		for(i=0;i<n;i++) {
			m -= arr[i];
			if(m<=0) break;
		}
		System.out.println(i==n?"STRESS":(i+1));
	}
}
