import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i;
		t = Integer.parseInt(br.readLine());
		ArrayList<chr> arr = new ArrayList<chr>();
		for(i=0;i<t;i++) {
			String str = br.readLine();
			arr.add(new chr(str,num(str)));
		}
		Collections.sort(arr, new Comparator<chr>() {
			@Override
			public int compare(chr o1, chr o2) {
				if(o1.str.length()!=o2.str.length()) {
					return o1.str.length()-o2.str.length();
				}else if(o1.n!=o2.n){
					return o1.n-o2.n;
				}else{
					return o1.str.compareTo(o2.str);
				}
			}
		});
		for(chr s:arr) sb.append(s.str+"\n");
		System.out.println(sb);
	}
	
	static int num(String str) {
		int n = 0;
		for(int i=0;i<str.length();i++) if(str.charAt(i)>='0'&&str.charAt(i)<='9') n+=str.charAt(i)-'0';
		return n;
	}
	
	public static class chr {
		String str;
		int n;
		
		public chr(String str, int n) {
			this.str = str;
			this.n = n;
		}
	}
}
