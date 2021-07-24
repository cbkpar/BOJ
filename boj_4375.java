import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,t,s;
		String str;
		while((str=br.readLine())!=null) {					
			n = Integer.parseInt(str);
			t = 1;
			s = 1;
			while(true) {
				if(t%n==0) break;
				t = (t*10+1)%n;
				s++;
			}
			sb.append(s+"\n");
		}
		System.out.println(sb);
	}
}
