import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	
	static char[] s;
	static char[] w;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,csz,wsz,sz,i,j;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			String code = br.readLine();
			String str = br.readLine();
			s = br.readLine().toCharArray();
			HashMap<Character,Integer> convert = new HashMap<Character, Integer>();
			csz = code.length();
			for(i=0;i<csz;i++) convert.put(code.charAt(i),i);
			wsz = str.length();
			w = new char[wsz];
			Queue<Integer> q = new LinkedList<>();
			for(i=0;i<csz;i++) {
				for(j=0;j<wsz;j++) {
					w[j] = code.charAt((convert.get(str.charAt(j))+i)%csz);
				}
				if(KMP()) q.add(i);
			}
			sz = q.size();
			if(sz==0) {
				sb.append("no solution\n");
			}else if(sz==1) {
				sb.append("unique: "+q.poll()+"\n");
			}else {
				sb.append("ambiguous: ");
				while(!q.isEmpty()) sb.append(q.poll()+" ");
				sb.append("\n");
			}
		}
		System.out.println(sb);
	}
	
	public static boolean KMP() {
		int[] pi = getPI();
		int cnt = 0;
		int j = 0;
		int sz = s.length;
		int wsz = w.length;
		for(int i=0;i<sz;i++) {
			while(j>0&&s[i]!=w[j]) j = pi[j-1];
			if(s[i]==w[j]) {
				if(j==wsz-1) {
					cnt++;
					j = pi[j];
					if(cnt==2) break;
				}else {
					j++;
				}
			}
		}
		return cnt==1?true:false;
	}
	
	public static int[] getPI() {
		int sz = w.length;
		int[] pi = new int[sz];
		int j = 0;
		for(int i=1;i<sz;i++) {
			while(j>0&&w[i]!=w[j]) j = pi[j-1];
			if(w[i]==w[j]) pi[i] = ++j;
		}
		return pi;
	}
}
