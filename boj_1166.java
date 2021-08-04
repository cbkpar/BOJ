import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n,l,w,h;
		double left,right,mid;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		left = mid = 0;
		right = 1e9;
		for(int i=0;i<1000;i++) {
			mid = (left+right)/2;
			if((long)((double)l/mid)*(long)((double)w/mid)*(long)((double)h/mid)>=n) {
				left = mid;
			}else {
				right = mid;
			}
		}
		System.out.printf("%.19f",left);
	}
}
