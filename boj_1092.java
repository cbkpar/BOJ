import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,cnt;
		n = Integer.parseInt(br.readLine());
		int[] crain = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) crain[i] = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(br.readLine());
		int[] box = new int[m];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<m;i++) box[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(crain);
		Arrays.sort(box);
		if(crain[n-1]<box[m-1]) {
			System.out.println("-1");
			return;
		}
		cnt = 0;
		ArrayList<Integer> q = new ArrayList<>();
		for(i=m-1;i>=0;i--) q.add(box[i]);
		while(!q.isEmpty()) {
			cnt++;
			for(i=n-1;i>=0;i--) {
				for(j=0;j<q.size();j++) {
					if(crain[i]>=q.get(j)) {
						q.remove(j);
						break;
					}
				}
			}
		}
		System.out.println(cnt);
	}
}
