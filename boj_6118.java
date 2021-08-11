import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,s,e,t,sz,num,p,qsz,number;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[] chk = new boolean[n+1];
		ArrayList<Integer>[] arr = new ArrayList[n+1];
		for(i=1;i<=n;i++) arr[i] = new ArrayList<Integer>(); 
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			arr[s].add(e);
			arr[e].add(s);
		}
		Queue<Integer> q = new LinkedList<>();
		q.add(1);
		chk[1] = true;
		t = sz = num =  0;
		number = 0;
		while(!q.isEmpty()) {
			sz = q.size();
			t++;
			num = 99999;
			for(i=0;i<sz;i++) {
				p = q.poll();
				qsz = arr[p].size();
				for(j=0;j<qsz;j++) {
					if(!chk[arr[p].get(j)]) {
						chk[arr[p].get(j)] = true;
						q.add(arr[p].get(j));
						num = Math.min(num, arr[p].get(j));
					}
				}
			}
			if(num==99999) break;
			number = num;
		}
		System.out.println(number+" "+(t-1)+" "+sz);
	}
}
