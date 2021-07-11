import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,sz,i,j;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			String str = br.readLine();
			sz = str.length();
			int[] cnt = new int[10];
			for(i=sz-1;i>0;i--)	if(str.charAt(i-1)<str.charAt(i)) {
				for(j=i-1;j<sz;j++) cnt[str.charAt(j)-'0']++;
				sb.append(str.substring(0, i-1));
				for(j=str.charAt(i-1)-'0'+1;j<10;j++) if(cnt[j]>0) {
					cnt[j]--;
					sb.append(j);
					break;
				}
				for(j=0;j<10;j++) while(cnt[j]-->0)	sb.append(j);
				sb.append("\n");
				break;
			}
			if(i==0) sb.append("BIGGEST\n");
		}
		System.out.println(sb);
	}
}
