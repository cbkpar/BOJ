import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,t,l,r,m;
		n = Integer.parseInt(br.readLine());
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(-1);
        StringTokenizer st = new StringTokenizer(br.readLine());
        while(n-->0) {
        	t = Integer.parseInt(st.nextToken());
        	if(t>arr.get(arr.size()-1)) {
        		arr.add(t);
        	}else {
        		l = 0;
        		r = arr.size();
        		while(l<r) {
        			m = (l+r)/2;
        			if(arr.get(m)>=t) {
        				r = m;
        			}else {
        				l = m + 1;
        			}
        		}
        		arr.set(l, t);
        	}
        }
        System.out.println(arr.size()-1);
	}
}
