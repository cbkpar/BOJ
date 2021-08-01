import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int i,sz;
		while(true) {
			String str = br.readLine();
			if(str.equals("end")) break;
			sz = str.length();
			int[] arr = new int[sz];
			boolean chk = false;
			for(i=0;i<sz;i++) {
				if(str.charAt(i)=='a') arr[i]++;
				if(str.charAt(i)=='e') arr[i]++;
				if(str.charAt(i)=='i') arr[i]++;
				if(str.charAt(i)=='o') arr[i]++;
				if(str.charAt(i)=='u') arr[i]++;
			}
			for(i=0;i<sz;i++) if(arr[i]!=0) chk = true;
			for(i=0;i<sz-2;i++)	if((arr[i]+arr[i+1]+arr[i+2])%3==0) chk = false;
			for(i=0;i<sz-1;i++) {
				if(str.charAt(i)==str.charAt(i+1)) {
					if(str.charAt(i)=='e') continue;
					if(str.charAt(i)=='o') continue;
					chk = false;
				}
			}
			if(chk) {
				sb.append("<"+str+"> is acceptable.\n");
			}else {
				sb.append("<"+str+"> is not acceptable.\n");
			}
		}
		System.out.println(sb);
	}
}
