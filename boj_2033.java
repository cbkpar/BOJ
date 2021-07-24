import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,t;
		n = Integer.parseInt(br.readLine());
		t = 10;
		while(n>t) {
			if(n%t>=t/2) n += t;
			n -= n%t;
			t *= 10;
		}
		System.out.println(n);
	}
}
