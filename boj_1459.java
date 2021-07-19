import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long x,y,t,w,s,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		x = Long.parseLong(st.nextToken());
		y = Long.parseLong(st.nextToken());
		w = Long.parseLong(st.nextToken());
		s = Long.parseLong(st.nextToken());
		ans = 0;
		if(y>x) {
			t = x;
			x = y;
			y = t;
		}
		if((x+y)%2==1) {
			ans += w;
			x--;
		}
		if(s>=2*w) {
			ans += (x+y)*w;
		}else {
			ans += Math.min(x, y)*s + (x-y)*Math.min(s, w);
		}
		System.out.println(ans);
	}
}
