import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,n,l,r,m;
		n = Integer.parseInt(br.readLine());
		boolean[] p = new boolean[1003003];
		ArrayList<Integer> palindrome = new ArrayList<>();
		p[0] = p[1] = true;
		for(i=2;i*i<=1003002;i++) if(!p[i]) for(j=i*i;j<=1003002;j+=i) p[j] = true;
		for(i=2;i<=1003002;i++) if(!p[i]) if(ispal(Integer.toString(i))) palindrome.add(i);
		l = 0;
		r = palindrome.size()-1;
		while(l<r) {
			m = (l+r)/2;
			if(palindrome.get(m)>=n) {
				r = m;
			}else {
				l = m+1;
			}
		}
		System.out.println(palindrome.get(l));
	}
	
	static boolean ispal(String num) {
		int sz = num.length();
		boolean chk = true;
		for(int i=0;i<=(sz-1)/2;i++) {
			if(num.charAt(i)!=num.charAt(sz-i-1)) {
				chk = false;
				break;
			}
		}
		return chk;
	}
}
