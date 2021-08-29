import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,cnt,i;
		n = Integer.parseInt(br.readLine());
		String str = br.readLine();
		cnt = 0;
		for(i=0;i<n;i++) cnt += str.charAt(i)-'0';
		System.out.println(cnt);
	}
}
