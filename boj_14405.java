import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,sz;
		String str = br.readLine();
		sz = str.length();
		i = 0;
		while(true) {
			if(sz-i<2) break;
			if(str.charAt(i)=='p'&&str.charAt(i+1)=='i') {
				i += 2;
				continue;
			}
			if(str.charAt(i)=='k'&&str.charAt(i+1)=='a') {
				i += 2;
				continue;
			}
			if(sz-i<3) break;
			if(str.charAt(i)=='c'&&str.charAt(i+1)=='h'&&str.charAt(i+2)=='u') {
				i += 3;
				continue;
			}
			break;
		}
		if(sz!=i) {
			System.out.println("NO");
		}else {
			System.out.println("YES");
		}
	}
}
