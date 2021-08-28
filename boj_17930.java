import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,t,now,cnt;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		now = cnt = 0;
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			if(st.nextToken().equals("enter")) {
				t = Integer.parseInt(st.nextToken());
				if(now+t>n) {
					cnt++;
				}else {
					now += t;
				}
			}else {
				t = Integer.parseInt(st.nextToken());
				now -= t;
			}
		}
		System.out.println(cnt);
	}
}
