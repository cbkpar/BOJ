import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i,j,m;
		t = Integer.parseInt(br.readLine());
		for(i=1;i<=t;i++) {
			String str = br.readLine();
			int[] arr = new int[26];
			for(j=0;j<str.length();j++) {
				if(str.charAt(j)>='a'&&str.charAt(j)<='z') arr[str.charAt(j)-'a']++;
				if(str.charAt(j)>='A'&&str.charAt(j)<='Z') arr[str.charAt(j)-'A']++;
			}
			m = 3;
			for(j=0;j<26;j++) m = Math.min(m, arr[j]);
			if(m==0) {
				sb.append("Case "+i+": Not a pangram\n");
			}else if(m==1) {
				sb.append("Case "+i+": Pangram!\n");
			}else if(m==2) {
				sb.append("Case "+i+": Double pangram!!\n");
			}else {
				sb.append("Case "+i+": Triple pangram!!!\n");
			}
		}
		System.out.println(sb);
	}
}
