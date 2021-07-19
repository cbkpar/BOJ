import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

	static int ans,sz,l;
	static int[] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,j,s;
		String str;
		str = br.readLine();
		l = str.length();
        Stack<Integer> stack = new Stack<>();
        for(i=0;i<26;i++) {
        	s = 0;
        	for(j=0;j<l;j++) if(str.charAt(j)=='a'+i) s++;
        	if(s!=0) stack.add(s);
        }
        sz = stack.size();
        arr = new int[sz];
        for(i=0;i<sz;i++) arr[i] = stack.pop();
        ans = 0;
        dfs(0,-1);
		System.out.println(ans);
	}
	
	static void dfs(int k, int n) {
		if(k==l) {
			ans++;
			return;
		}
		for(int i=0;i<sz;i++) {
			if(arr[i]==0) continue;
			if(i!=n) {
				arr[i]--;
				dfs(k+1,i);
				arr[i]++;
			}
		}
	}
}
