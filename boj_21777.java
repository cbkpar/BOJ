import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,cnt,tmp,prior,i;
		t = Integer.parseInt(br.readLine());
		int[][] process = new int[1000001][2];
		StringTokenizer st = new StringTokenizer(br.readLine());
		cnt = 0;
		prior = t+1;
		tmp = 1000001;
		while(t-->0) {
			n = Integer.parseInt(st.nextToken());
			if(n<=tmp) prior--;
			tmp = n;
			process[n][0]++;
			if(process[n][1]==0) {
				cnt++;
				process[n][1] = prior;
			}
		}
		sb.append(cnt+"\n");
		for(i=1;i<=1000000;i++) {
			if(process[i][0]!=0) {
				sb.append(i+" "+process[i][0]+" "+process[i][1]+"\n");
			}
		}
		System.out.println(sb);
	}
}
