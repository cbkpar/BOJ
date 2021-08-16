import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,x,h,t,m,ans,tx,tm;
		n = Integer.parseInt(br.readLine());
		ArrayList<pos> arr = new ArrayList<pos>();
		m = t = 0;
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			if(h>m) {
				m = h;
				t = x;
			}
			arr.add(new pos(x,h));
		}
		Collections.sort(arr, new Comparator<pos>(){
			@Override
			public int compare(pos o1, pos o2) {
				return o1.x - o2.x;
			}
		});
		ans = m;
		tx = arr.get(0).x;
		tm = arr.get(0).h;
		for(i=1;i<n;i++) {
			pos p = arr.get(i);
			if(p.x>t) break;
			if(p.h>=tm) {
				ans += (p.x-tx)*tm;
				tx = p.x;
				tm = p.h;
			}
		}
		tx = arr.get(n-1).x;
		tm = arr.get(n-1).h;
		for(i=n-2;i>=0;i--) {
			pos p = arr.get(i);
			if(p.x<t) break;
			if(p.h>=tm) {
				ans += (tx-p.x)*tm;
				tx = p.x;
				tm = p.h;
			}
		}
		System.out.println(ans);

	}
}

class pos {
	int x,h;
	
	public pos(int x, int h) {
		this.x = x;
		this.h = h;
	}
}
