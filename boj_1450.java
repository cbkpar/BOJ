import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	static int n,lsz,rsz;
	static ArrayList<Long> l = new ArrayList<Long>();
	static ArrayList<Long> r = new ArrayList<Long>();
	static ArrayList<Long> left = new ArrayList<Long>();
	static ArrayList<Long> right = new ArrayList<Long>();
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,e;
		long c,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		c = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n/2;i++) l.add(Long.parseLong(st.nextToken()));
		for(i=n/2;i<n;i++) r.add(Long.parseLong(st.nextToken()));
		lsz = l.size();
		rsz = r.size();
		dfsl(0,0);
		dfsr(0,0);
		Collections.sort(left);
		Collections.sort(right);
		ans = 0;
		e = right.size()-1;
		for(i=0;i<left.size();i++) {
			while(true) {
				if(e==-1) break;
				if(left.get(i)+right.get(e)<=c) break;
				e--;
			}
			ans += e+1;
		}
		System.out.println(ans);
	}
	
	static void dfsl(int k, long sum) {
		if(k==lsz) {
			left.add(sum);
			return;
		}
		dfsl(k+1,sum);
		dfsl(k+1,sum+l.get(k));
	}
	
	static void dfsr(int k, long sum) {
		if(k==rsz) {
			right.add(sum);
			return;
		}
		dfsr(k+1,sum);
		dfsr(k+1,sum+r.get(k));
	}
}
