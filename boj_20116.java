import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long center,l;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		l = Long.parseLong(st.nextToken());
		long[] arr = new long[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		center = 0;
		boolean chk = true;
		for(i=n-1;i>0;i--) {
			center += arr[i];
			if(center-l*(n-i)<arr[i-1]*(n-i)&&center+l*(n-i)>arr[i-1]*(n-i)) continue;
			chk = false;
			break;
		}
		System.out.println(chk?"stable":"unstable");
	}
}
