import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] dy = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
		int[] dx = {0,4,2,2,2,3,4,5,7,6,7,8,6,5,8,9,0,3,1,4,6,3,1,1,5,0};
		int ly,lx,ry,rx,sz,i,d;
		StringTokenizer st = new StringTokenizer(br.readLine());
		char c = st.nextToken().charAt(0);
		ly = dy[c-'a'];
		lx = dx[c-'a'];
		c = st.nextToken().charAt(0);
		ry = dy[c-'a'];
		rx = dx[c-'a'];
		String str = br.readLine();
		sz = str.length();
		d = sz;
		for(i=0;i<sz;i++) {
			c = str.charAt(i);
			if(c=='y'||c=='u'||c=='i'||c=='o'||c=='p'||c=='h'||c=='j'||c=='k'||c=='l'||c=='b'||c=='n'||c=='m') {
				d += Math.abs(ry-dy[c-'a']);
				d += Math.abs(rx-dx[c-'a']);
				ry = dy[c-'a'];
				rx = dx[c-'a'];
			}else {
				d += Math.abs(ly-dy[c-'a']);
				d += Math.abs(lx-dx[c-'a']);
				ly = dy[c-'a'];
				lx = dx[c-'a'];
			}
		}
		System.out.println(d);
	}
}
