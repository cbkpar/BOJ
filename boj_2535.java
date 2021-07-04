import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,country,num,score,t;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
	    PriorityQueue<student> pq = new PriorityQueue<>();
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			country = Integer.parseInt(st.nextToken());
			num = Integer.parseInt(st.nextToken());
			score = Integer.parseInt(st.nextToken());
			pq.add(new student(country, num, score));
		}
		t = 0;
		while(!pq.isEmpty()) {
			if(arr[pq.peek().country]!=2) {
				arr[pq.peek().country]++;
				sb.append(pq.peek().country+" "+pq.peek().num+"\n");
				t++;
			}
			pq.poll();
			if(t==3) break;
		}
		System.out.println(sb);
	}
	
	public static class student implements Comparable<student> {
		int country;
		int num;
		int score;
		
		public student(int country, int num, int score) {
			this.country = country;
			this.num = num;
			this.score = score;
		}
		
		@Override
		public int compareTo(student o) {
			return  o.score - this.score;
		}
	}
}
