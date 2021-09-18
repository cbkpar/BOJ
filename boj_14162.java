import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s,e,i;
		long ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken())-1;
		e = Integer.parseInt(st.nextToken());
		ans = 0;
		for(i=1;i<=e;i++) ans += (e/i-s/i)*i;
		System.out.println(ans);
	}
}
