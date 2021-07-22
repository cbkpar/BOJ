import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,b,i,j,ans,k;
		long p,s,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		ArrayList<fri> arr = new ArrayList<fri>();
		for(i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			arr.add(new fri(p/2+s,p+s));
		}
		Collections.sort(arr, new Comparator<fri>(){
			@Override
			public int compare(fri o1, fri o2) {
				if(o1.s!=o2.s) return (int)(o1.s - o2.s);
				return (int)(o2.p - o1.p);
			}
		});
		ans = 0;
		for(i=0;i<n;i++) {
			if(arr.get(i).p<=b) {
				k = 1;
				t = arr.get(i).p;
				for(j=0;j<n;j++) {
					if(i==j) continue;
					if(arr.get(j).s+t>b) break;
					t += arr.get(j).s;
					k++;
				}
				ans = Math.max(ans, k);
			}
		}
		System.out.println(ans);
	}
	
	public static class fri {
		long p;
		long s;
		
		public fri(long p, long s) {
			this.p = p;
			this.s = s;
		}
	}
}
