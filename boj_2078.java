import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int a,b,l,r;
    	l = r = 0;
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	a = Integer.parseInt(st.nextToken());
    	b = Integer.parseInt(st.nextToken());
    	while(true) {
    		if(a==1) {
    			r += b-1;
    			break;
    		}
    		if(b==1) {
    			l += a-1;
    			break;
    		}
    		if(a>b) {
    			l += a/b;
    			a -= (a/b)*b;
    		}else {
    			r += b/a;
    			b -= (b/a)*a;
    		}
    	}
    	System.out.println(l+" "+r);
    }
}
