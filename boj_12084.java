import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double v = Double.parseDouble(st.nextToken());
            double d = Double.parseDouble(st.nextToken());
            double k = (9.8 * d) / (v * v);
            if(k>=1) k = 1;
            if(k<0) k = 0;
            double ans = Math.asin(k) * 90.0/ Math.PI;
            sb.append("Case #" + i + ": " + String.format("%.10f",ans) + "\n");
        }
        System.out.println(sb);
    }
}
