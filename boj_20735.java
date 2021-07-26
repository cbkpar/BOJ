import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s;
		s = 0;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine().toLowerCase();
			if(str.contains("pink")) {
				s++;
			}else if(str.contains("rose")) {
				s++;
			}
		}
		if(s==0) {
			System.out.println("I must watch Star Wars with my daughter");
		}else {
			System.out.println(s);
		}
	}
}
