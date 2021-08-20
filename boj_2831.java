import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,t,s,l,r,psz,qsz;
		ArrayList<Integer> A = new ArrayList<Integer>();
		ArrayList<Integer> B = new ArrayList<Integer>();
		ArrayList<Integer> C = new ArrayList<Integer>();
		ArrayList<Integer> D = new ArrayList<Integer>();
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) {
			t = Integer.parseInt(st.nextToken());
			if(t>0) {
				A.add(t);
			}else {
				B.add(t);
			}
		}
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) {
			t = Integer.parseInt(st.nextToken());
			if(t>0) {
				C.add(t);
			}else {
				D.add(t);
			}
		}
		Collections.sort(A);
		Collections.sort(B,Collections.reverseOrder());
		Collections.sort(C);
		Collections.sort(D,Collections.reverseOrder());
		s = 0;
		psz = A.size();
		qsz = D.size();
		l = r = 0;
		while(true) {
			if(l>=psz||r>=qsz) break;
			if(A.get(l)+D.get(r)<0) {
				l++;
				r++;
				s++;
			}else {
				r++;
			}
		}
		psz = C.size();
		qsz = B.size();
		l = r = 0;
		while(true) {
			if(l>=psz||r>=qsz) break;
			if(C.get(l)+B.get(r)<0) {
				l++;
				r++;
				s++;
			}else {
				r++;
			}
		}
		System.out.println(s);
	}
}
