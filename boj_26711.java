import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i,j,m;
		int[] aa = new int[10001];
		int[] bb = new int[10001];
		int[] c = new int[10001];
		String a;
		String b;
		a = sc.next();
		b = sc.next();
		for(i=0;i<a.length();i++) {
			aa[i]=a.charAt(a.length()-i-1)-48;
		}
		for(i=0;i<b.length();i++) {
			bb[i]=b.charAt(b.length()-i-1)-48;
		}
		for(j=0;j<=10000;j++) {
			c[j]=aa[j]+bb[j];
		}
		for(j=0;j<=10000;j++) {
			if(c[j]>=10) {
				c[j+1]+=1;
				c[j]-=10;
			}
		}
		for(j=10000;j>=0;j--) {
			if(c[j]!=0) {
				for(;j>=0;j--) {
					System.out.printf("%d",c[j]);
				}
				break;
			}
		}
	}
}
