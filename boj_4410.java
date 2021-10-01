import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long a, b, t, c, x,ta,tb,tm;
        int i;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Long.parseLong(st.nextToken());
            b = Long.parseLong(st.nextToken());
            if (a == 0 && b == 0) break;
            if (a == 0) {
                sb.append("0 2\n");
                continue;
            }
            if (a == b) {
                sb.append("2 0\n");
                continue;
            }
            boolean flag = false;
            ta = tb = tm = 99999;
            for (i = 2; i <= 50000; i++) {
                t = (long) i * (i - 1);
                if (t % a == 0) {
                    c = t / a;
                    x = (long) Math.sqrt(b * c);
                    if (x * (x + 1) == b * c) {
                        if (x <= 49999) {
                            if(x+1<tm){
                                tm = x+1;
                                ta = i;
                                tb = x-i+1;
                                flag = true;
                            }else if(x+1==tm){
                                if(i<ta){
                                    ta = i;
                                    tb = x-i+1;
                                    flag = true;
                                }
                            }
                        }
                    }
                }
            }
            if(flag){
                sb.append(ta + " " + tb + "\n");
            }else{
                sb.append("impossible\n");
            }
        }
        System.out.println(sb);
    }
}
