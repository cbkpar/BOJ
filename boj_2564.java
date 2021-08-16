import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t,a,b,k,sum;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(br.readLine());
		ArrayList<Integer> arr = new ArrayList<Integer>();
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			arr.add(trans(a,b));
		}
		st = new StringTokenizer(br.readLine());
		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		k = trans(a,b);
		sum = 0;
		for(int tmp:arr) sum += Math.min(Math.abs(tmp-k), n*2+m*2-Math.abs(tmp-k));
		System.out.println(sum);
	}
	
	public static int trans(int a, int b) {
		if(a==1) {
			return b;
		}else if(a==2) {
			return 2*n+m-b;
		}else if(a==3) {
			return 2*n+2*m-b;
		}else {
			return n+b;
		}
	}
}
