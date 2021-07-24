import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,sq,i;
		n = Integer.parseInt(br.readLine());
		sq = (int)Math.sqrt(n);
		for(i=2;i<=sq;i++) {
			if(n%i==0) {
				System.out.println(n-n/i);
				return;
			}
		}
		System.out.println(n-1);
	}
}
