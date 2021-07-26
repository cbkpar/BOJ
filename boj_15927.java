import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i;
		String str = br.readLine();
		sz = str.length();
		for(i=0;i<sz/2;i++) {
			if(str.charAt(i)!=str.charAt(sz-i-1)) {
				System.out.println(sz);
				return;
			}
		}
		for(i=0;i<sz-2;i++) {
			if(str.charAt(i)!=str.charAt(i+1)) {
				System.out.println(sz-1);
				return;
			}
		}
		System.out.println("-1");
	}
}
