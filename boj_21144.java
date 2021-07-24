import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		n = Integer.parseInt(br.readLine());
		String str = br.readLine();
		for(i=1;i<Math.min(n, 10);i++) {
			if(str.charAt(i-1)!='0'+i) {
				System.out.println(i);
				return;
			}
		}
		for(i=10;i<n;i++) {
			if(str.charAt(2*i-11)!='0'+i/10||str.charAt(2*i-10)!='0'+i%10) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(n);
	}
}
