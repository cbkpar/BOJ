import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int k,sz;
    	br.readLine();
    	String m = br.readLine();
    	sz = m.length();
    	k = Integer.parseInt(br.readLine());
    	while(sz-->0) {
    		if(k--<=0) break;
    		if(m.charAt(sz)=='1') {
    			System.out.println("NO");
    			return;
    		}
    		
    	}
    	System.out.println("YES");
    }
}
