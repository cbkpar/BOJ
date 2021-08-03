import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a,d,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		t = 0;
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		map.put(a,t++);
		while(true) {
			a = pow(a,d);
			if(!map.containsKey(a)) {
				map.put(a, t++);
			}else {
				System.out.println(map.get(a));
				return;
			}
		}
	}
	
	static int pow(int n, int k) {
		int s = 0;
		while(n>0) {
			s += Math.pow(n%10, k);
			n /= 10;
		}
		return s;
	}
}
