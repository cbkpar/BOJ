import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,idx,mi;
		n = Integer.parseInt(br.readLine());
		pos[] p = new pos[n];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			p[i] = new pos(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		}
		Arrays.sort(p,(o1,o2)->o1.x-o2.x);
		TreeSet<pos> set = new TreeSet<>((o1,o2)->(o1.y==o2.y)?o1.x-o2.x:o1.y-o2.y);
		mi = dist(p[0],p[1]);
		set.add(p[0]);
		set.add(p[1]);
		idx = 0;
		for(i=2;i<n;i++) {
			pos lpos = p[i];
			while(idx<i) {
				pos rpos = p[idx];
				int dx = lpos.x-rpos.x;
				if(dx*dx<=mi) break;
				set.remove(rpos);
				idx++;
			}
			int sq = (int)Math.sqrt(mi)+1;
			pos plow = new pos(-10001,lpos.y-sq);
			pos phigh = new pos(10001,lpos.y+sq);
			for(pos v:set.subSet(plow, phigh)) mi = Math.min(mi, dist(lpos,v));
			set.add(lpos);
		}
		System.out.println(mi);
		
	}
	
	private static int dist(pos a, pos b) {
		return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	}
	
	private static class pos {
		int x,y;
		public pos (int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
