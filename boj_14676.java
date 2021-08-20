import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,k,i,s,e;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[] cnt = new int[n+1];
		int[] chk = new int[n+1];
		Queue<Integer>[] q = new LinkedList[n+1];
		for(i=1;i<=n;i++) q[i] = new LinkedList<Integer>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			q[s].add(e);
			cnt[e]++;
		}
		while(k-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			if(s==1) {
				if(cnt[e]==0) {
					if(chk[e]++==0)	for(int z:q[e]) cnt[z]--;
				}else {
					System.out.println("Lier!");
					return;
				}
			}else {
				if(chk[e]>0) {
					if(--chk[e]==0)	for(int z:q[e]) cnt[z]++;
				}else {
					System.out.println("Lier!");
					return;
				}
			}
		}
		System.out.println("King-God-Emperor");
	}
}
