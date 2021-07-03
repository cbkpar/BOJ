import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,l,r,i,m,t,s;
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		s = l = 0;
		r = n-1;
		while(true) {
			if(l>=r) break;
			t = arr[l] + arr[r];
			if(t==m) {
				s++;
				l++;
				r--;
			}else if(t<m) {
				l++;
			}else {
				r--;
			}
		}
		System.out.println(s);
	}
}
