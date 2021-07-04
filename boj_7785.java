import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
        ArrayList<String> enter = new ArrayList<String>();
        ArrayList<String> leave = new ArrayList<String>();
		int n,i,l,r,lsz,rsz;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			if(st.nextToken().equals("enter")) {
				enter.add(name);
			}else {
				leave.add(name);
			}
		}
		Collections.sort(enter, Collections.reverseOrder());
		Collections.sort(leave, Collections.reverseOrder());
		lsz = enter.size();
		rsz = leave.size();
		l = r = 0;
		while(true) {
			if(l==lsz) break;
			if(r==rsz) {
				for(i=l;i<lsz;i++) sb.append(enter.get(i)+"\n");
				break;
			}
			if(enter.get(l).equals(leave.get(r))) {
				l++;
				r++;
			}else {
				sb.append(enter.get(l++)+"\n");
			}
		}
		System.out.println(sb);
	}
}
