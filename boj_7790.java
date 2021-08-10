import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
		int cnt = 0;
		while((str=br.readLine())!=null) {
			StringTokenizer st = new StringTokenizer(str);
			while(st.hasMoreTokens()) {
				String word = st.nextToken();
				int sz = word.length();
				for(int i=0;i<=sz-4;i++) if(word.charAt(i)=='j'&&word.charAt(i+1)=='o'&&word.charAt(i+2)=='k'&&word.charAt(i+3)=='e') cnt++;
			}
		}
		System.out.println(cnt);
	}
}
