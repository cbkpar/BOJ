import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long l = Long.parseLong(st.nextToken());

        long gc = gcd(a, b);
        long lc = a * b / gc;
        if(l%lc!=0){
            System.out.println("-1");
        }else{
            long p = lc;
            long q = l/lc;
            long ans = 1;
            while(true){
                gc = gcd(p,q);
                if(gc==1) break;
                ans *= gc;
                p /= gc;
            }
            ans *= q;
            System.out.println(ans);
        }
    }

    private static long gcd(long a, long b) {
        if (b % a == 0) return a;
        return gcd(b % a, a);
    }
}
