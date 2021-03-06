import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
		int n,i;
		n = Integer.parseInt(br.readLine());
		Integer[] arr = new Integer[n];
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr, Collections.reverseOrder());
		for(int t:arr) sb.append(t+"\n");
		System.out.println(sb);
	}
}
