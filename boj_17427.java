import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long ans;
		n = Integer.parseInt(br.readLine());
		ans = 0;
		for(i=1;i<=n;i++) ans += i * (n/i);
		System.out.println(ans);
	}
}
