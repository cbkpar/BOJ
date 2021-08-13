import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,s,e,t;
		ArrayList<Integer>[] arr = new ArrayList[13];
		for(i=1;i<=12;i++) arr[i] = new ArrayList<Integer>();
		for(i=1;i<=12;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			arr[s].add(e);
			arr[e].add(s);
		}
		for(i=1;i<=12;i++) {
			if(arr[i].size()==3) {
				t = 0;
				for(j=0;j<3;j++) {
					t += arr[arr[i].get(j)].size();
				}
				if(t==6) {
					System.out.println(i);
					return;
				}
			}
		}
	}
}
