import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n,i,j,t,sz;
    	boolean[] p = new boolean[1000001];
    	p[0] = p[1] = true;
    	for(i=2;i*i<=1000000;i++) for(j=i*i;j<=1000000;j+=i) p[j] = true;
    	n = Integer.parseInt(br.readLine());
    	StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> arr = new ArrayList<Integer>();
    	while(n-->0) {
    		t = Integer.parseInt(st.nextToken());
    		if(!p[t]) arr.add(t);
    	}
    	if(arr.size()==0) {
    		System.out.println("-1");
    	}else {
    		Collections.sort(arr);
    		BigInteger ans = new BigInteger(Integer.toString(arr.get(0)));
    		sz = arr.size();
    		for(i=1;i<sz;i++) if(arr.get(i-1)<arr.get(i)) ans = ans.multiply(new BigInteger(Integer.toString(arr.get(i))));
    		System.out.println(ans);
    	}
    }
}
