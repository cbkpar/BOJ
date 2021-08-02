import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n;
        long ans, mx, t;
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ans = mx = 0;
        while(n-->0) {
        	t = Long.parseLong(st.nextToken());
        	mx = Math.max(mx, t);
        	ans += t;
        }
        System.out.println((ans+mx)%2==0?(ans+mx)/2:(ans+mx)/2+".5");
	}
}
