import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long c,o,w;
		n = Integer.parseInt(br.readLine());
		String str = br.readLine();
		c = o = w = 0;
		for(i=0;i<n;i++) {
			if(str.charAt(i)=='C') {
				c++;
			}else if(str.charAt(i)=='O') {
				o += c;
			}else {
				w += o;
			}
		}
		System.out.println(w);
	}
}
