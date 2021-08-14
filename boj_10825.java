import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,kor,eng,math;
		String name;
		ArrayList<student> stu = new ArrayList<student>();
		n = Integer.parseInt(br.readLine());
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			name = st.nextToken();
			kor = Integer.parseInt(st.nextToken());
			eng = Integer.parseInt(st.nextToken());
			math = Integer.parseInt(st.nextToken());
			stu.add(new student(name, kor, eng, math));
		}
		Collections.sort(stu, new Comparator<student>() {
			@Override
			public int compare(student s1, student s2) {
				if(s1.kor!=s2.kor) {
					return s2.kor - s1.kor;
				}else if(s1.eng!=s2.eng) {
					return s1.eng - s2.eng;
				}else if(s1.math!=s2.math) {
					return s2.math - s1.math;
				}else {
					return s1.name.compareTo(s2.name);
				}
			}
		});
		for(i=0;i<n;i++) sb.append(stu.get(i).name+"\n");
		System.out.println(sb);
	}
	
	public static class student {
		String name;
		int kor, eng, math;
		
		public student(String name, int kor, int eng, int math) {
			this.name = name;
			this.kor = kor;
			this.eng = eng;
			this.math = math;
		}
	}
}
