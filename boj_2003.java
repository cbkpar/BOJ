import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		s = 0;
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++) if(arr[j]-arr[i]==m) s++;
		System.out.println(s);
	}
}
