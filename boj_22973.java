import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cnt;
		long n;
		n = Math.abs(Long.parseLong(br.readLine()));
		if(n==0) {
			System.out.println("0");
			return;
		}else if(n%2==0) {
			System.out.println("-1");
		}else {
			cnt = 0;
			while(n>0) {
				cnt++;
				n/=2;
			}
			System.out.println(cnt);
		}
	}
}
