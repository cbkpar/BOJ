import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	int sz,i,j,q,a,b,c,d;
    	String str = br.readLine();
    	sz = str.length();
    	int[][] presum = new int[sz+1][26];
    	for(i=0;i<sz;i++) {
    		for(j=0;j<26;j++) presum[i+1][j] += presum[i][j];
    		presum[i+1][str.charAt(i)-'a']++;
    	}
    	q = Integer.parseInt(br.readLine());
    	while(q-->0) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		c = Integer.parseInt(st.nextToken());
    		d = Integer.parseInt(st.nextToken());
    		boolean chk = true;
    		for(i=0;i<26;i++) {
    			if(presum[b][i]-presum[a-1][i]<presum[d][i]-presum[c-1][i]) {
    				chk = false;
    				break;
    			}
    		}
    		sb.append(chk?"DA\n":"NE\n");
    	}
    	System.out.println(sb);
    }
}
