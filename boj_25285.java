import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iT = Integer.parseInt(br.readLine());
        while (iT-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iHeight = Integer.parseInt(st.nextToken());
            int iWeight = Integer.parseInt(st.nextToken());
            if (iHeight <= 140) {
                sb.append("6\n");
            } else if (iHeight <= 145) {
                sb.append("5\n");
            } else if (iHeight <= 158) {
                sb.append("4\n");
            } else if (iHeight <= 160) {
                float fBMI = (float) iWeight * 10000.0f / (float) (iHeight * iHeight);
                if (16.0f <= fBMI && fBMI < 35.0f) {
                    sb.append("3\n");
                } else {
                    sb.append("4\n");
                }
            } else if (iHeight <= 203) {
                float fBMI = (float) iWeight * 10000.0f / (float) (iHeight * iHeight);
                if (20.0f <= fBMI && fBMI < 25.0f) {
                    sb.append("1\n");
                }
                if (18.5f <= fBMI && fBMI < 20.0f) {
                    sb.append("2\n");
                }
                if (25.0f <= fBMI && fBMI < 30.0f) {
                    sb.append("2\n");
                }
                if (16.0f <= fBMI && fBMI < 18.5f) {
                    sb.append("3\n");
                }
                if (30.0f <= fBMI && fBMI < 35.0f) {
                    sb.append("3\n");
                }
                if (16.0f > fBMI || fBMI >= 35.0f) {
                    sb.append("4\n");
                }
            } else {
                sb.append("4\n");
            }
        }
        System.out.println(sb);
    }
}
