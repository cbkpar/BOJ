import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,j,k,ans;
		char[] str = br.readLine().toCharArray();
		sz = str.length;
		ans = 0;
		for(i=0;i<sz;i++) {
			int[] pi = new int[sz];
			k = 0;
			for(j=i+1;j<sz;j++) {
				while(k>0&&str[j]!=str[i+k]) k = pi[k-1];
				if(str[j]==str[i+k]) pi[j-i] = ++k;
				ans = Math.max(ans, k);
			}
		}
		System.out.println(ans);
	}
}
