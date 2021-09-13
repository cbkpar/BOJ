import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,ans;
		n = Integer.parseInt(br.readLine());
		int[] A = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) A[i] = Integer.parseInt(st.nextToken());
		int[] B = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) B[i] = Integer.parseInt(st.nextToken());
		ans = 0;
		for(i=1;i<=n;i++) {
			A[i] += A[i-1];
			B[i] += B[i-1];
			if(A[i]==B[i]) ans = i;
		}
		System.out.println(ans);
	}
}
