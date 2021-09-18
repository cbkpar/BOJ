import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,t,sz;
		long w,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		ArrayList<Integer> arr = new ArrayList<>();
		s = 0;
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) {
			t = Integer.parseInt(st.nextToken());
			if(t>0) {
				s += t;
				arr.add(t);
			}
		}
		sz = arr.size();
		Collections.sort(arr);
		for(i=0;i<sz;i++) {
			if(s>=w*(sz-i)) {
				System.out.println(i);
				return;
			}
			s -= arr.get(i);
		}
		System.out.println("NIE");
	}
}
