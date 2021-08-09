import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
		int sz,i;
		Queue<Integer> q = new LinkedList<>();
		String str = br.readLine();
		sz = str.length();
		for(i=0;i<sz;i++) q.add(arr[str.charAt(i)-'A']);
		while(q.size()>=2) {
			sz = q.size();
			for(i=0;i<sz/2;i++) q.add((q.poll()+q.poll())%10);
			if(sz%2==1) q.add(q.poll());
		}
		System.out.println(q.poll()%2==1?"I'm a winner!":"You're the winner?");
	}
}
