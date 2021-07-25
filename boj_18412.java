import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int a,b,c,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		String str = br.readLine();
		for(i=0;i<b-1;i++) sb.append(str.charAt(i));
		for(i=c-1;i>=b-1;i--) sb.append(str.charAt(i));
		for(i=c;i<a;i++) sb.append(str.charAt(i));
		System.out.println(sb);
	}
}
