import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,i,j,ans,t,mx;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		ArrayList<Integer>[] arr = new ArrayList[k+1];
		for(i=1;i<=k;i++) arr[i] = new ArrayList<Integer>();
		ArrayList<Integer> plug = new ArrayList<Integer>();
		st = new StringTokenizer(br.readLine());
		int[] order = new int[k];
		for(i=0;i<k;i++) {
			order[i] = Integer.parseInt(st.nextToken());
			arr[order[i]].add(i);
		}
		ans = 0;
		for(i=0;i<k;i++) {
			if(plug.contains(order[i])) {
				arr[order[i]].remove(0);
				continue;
			}
			if(plug.size()<n) {
				plug.add(order[i]);
				arr[order[i]].remove(0);
			}else {
				t = mx = -1;
				for(j=0;j<n;j++) {
					if(arr[plug.get(j)].size()==0) {
						t = j;
						break;
					}else {
						if(arr[plug.get(j)].get(0)>mx) {
							t = j;
							mx = arr[plug.get(j)].get(0);
						}
					}
				}
				ans++;
				plug.set(t, order[i]);
				arr[order[i]].remove(0);
			}
		}
		System.out.println(ans);
	}
}
