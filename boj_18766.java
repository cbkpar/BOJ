import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,i;
		boolean chk;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			n = Integer.parseInt(br.readLine());
			String[] A = new String[n];
			String[] B = new String[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(i=0;i<n;i++) A[i] = st.nextToken();
			st = new StringTokenizer(br.readLine());
			for(i=0;i<n;i++) B[i] = st.nextToken();
			Arrays.sort(A);
			Arrays.sort(B);
			chk = false;
			for(i=0;i<n;i++) {
				if(!A[i].equals(B[i])) {
					chk = true;
					break;
				}
			}
			sb.append(chk?"CHEATER\n":"NOT CHEATER\n");
		}
		System.out.println(sb);
	}
}
