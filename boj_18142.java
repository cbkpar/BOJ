import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		boolean chk = false;
		while(st.hasMoreTokens()) {
			String str = st.nextToken();
			if(str.equals("bubble")) continue;
			if(str.equals("tapioka")) continue;
			chk = true;
			sb.append(str+" ");
		}
		if(chk) {
			System.out.println(sb);
		}else {
			System.out.println("nothing");
		}
	}
}
