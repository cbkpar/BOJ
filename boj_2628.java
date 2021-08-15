import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int y,x,t,a,b,m,i,j;
		StringTokenizer st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(br.readLine());
		ArrayList<Integer> arry = new ArrayList<Integer>();
		ArrayList<Integer> arrx = new ArrayList<Integer>();
		arry.add(0);
		arrx.add(0);
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(a==0) {
				arry.add(b);
			}else {
				arrx.add(b);
			}
		}
		arry.add(y);
		arrx.add(x);
		Collections.sort(arry);
		Collections.sort(arrx);
		m = 0;
		for(i=1;i<arry.size();i++) {
			for(j=1;j<arrx.size();j++) {
				m = Math.max(m, (arry.get(i)-arry.get(i-1))*(arrx.get(j)-arrx.get(j-1)));
			}
		}
		System.out.println(m);
	}
}
