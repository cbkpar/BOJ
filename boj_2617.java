import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m;
	static ArrayList<Integer>[] arrmx;
	static ArrayList<Integer>[] arrmi;
	static int[] dpmx;
	static int[] dpmi;
	static boolean[] chk;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,p,q,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arrmx = new ArrayList[n+1];
		arrmi = new ArrayList[n+1];
		dpmx = new int[n+1];
		dpmi = new int[n+1];
		for(i=1;i<=n;i++) arrmx[i] = new ArrayList<Integer>();
		for(i=1;i<=n;i++) arrmi[i] = new ArrayList<Integer>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken());
			q = Integer.parseInt(st.nextToken());
			arrmx[p].add(q);
			arrmi[q].add(p);
		}
		ans = 0;
		for(i=1;i<=n;i++) {
			chk = new boolean[n+1];
			if(dfsmx(i)>(n+1)/2) {
				ans ++;
				continue;
			}
			chk = new boolean[n+1];
			if(dfsmi(i)>(n+1)/2) {
				ans ++;
				continue;
			}
		}
		System.out.println(ans);
	}
	
	public static int dfsmx(int k) {
		if(chk[k]) return dpmx[k];
		chk[k] = true;
		int sz = arrmx[k].size();
		dpmx[k] = 1;
		for(int i=0;i<sz;i++) {
			if(chk[arrmx[k].get(i)]) continue;
			dpmx[k] += dfsmx(arrmx[k].get(i));
		}
		return dpmx[k];
	}
	
	public static int dfsmi(int k) {
		if(chk[k]) return dpmi[k];
		chk[k] = true;
		int sz = arrmi[k].size();
		dpmi[k] = 1;
		for(int i=0;i<sz;i++) {
			if(chk[arrmi[k].get(i)]) continue;
			dpmi[k] += dfsmi(arrmi[k].get(i));
		}
		return dpmi[k];
	}
}
