import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
		int n,i;
		n = Integer.parseInt(br.readLine());
		for(i=0;i<n;i++) {
			if(i!=0) sb.append("\n");
			StringTokenizer st = new StringTokenizer(br.readLine());
			boolean chk = false;
			while(st.hasMoreTokens()) {
				if(chk) sb.append(" ");
				String str = st.nextToken();
				sb.append(str.length()==4?"****":str);
				chk = true;
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
