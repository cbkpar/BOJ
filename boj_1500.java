import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s,k,i;
		long ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		ans = 1;
		for(i=0;i<k;i++) ans *= (s/k) + (s%k>i?1:0);
		System.out.println(ans);
	}
}
