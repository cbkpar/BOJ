import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,k,sz;
		long ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		char[] str = st.nextToken().toCharArray();
		k = Integer.parseInt(st.nextToken());
		sz = str.length;
		int[] pi = new int[sz];
		j = 0;
		for(i=1;i<sz;i++) {
			while(j>0&&str[i]!=str[j]) j = pi[j-1];
			if(str[i]==str[j]) pi[i] = ++j;
		}
		ans = sz + (long)(sz-pi[sz-1])*(k-1);
		System.out.println(ans);
	}
}
