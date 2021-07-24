import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t;
		long n;
		n = Integer.parseInt(br.readLine());
		if(n==0) {
			System.out.println("1");
			return;
		}else if(n<0) {
			System.out.println("32");
			return;
		}
		t = 0;
		while(n!=0) {
			t++;
			n/=2;
		}
		System.out.println(t);
	}
}
