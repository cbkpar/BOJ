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
            int iN = Integer.parseInt(st.nextToken());
            long lDist = Long.parseLong(st.nextToken());
            long lMaxBoost = Long.parseLong(st.nextToken());
            st = new StringTokenizer(br.readLine());
            long lMax = 0;
            for (int i = 0; i < iN - 1; ++i) {
                lMax = Math.max(lMax, Long.parseLong(st.nextToken()));
            }
            long lSpeed = Long.parseLong(st.nextToken());
            if (lMax < lSpeed) {
                sb.append("0\n");
            } else if (lDist * lSpeed > (lDist - lMaxBoost) * lMax + lMax * lSpeed) {
                if ((lDist * lSpeed - lMax * lSpeed) % lMax == 0) {
                    sb.append((lDist - (lDist * lSpeed - lMax * lSpeed) / lMax + 1) + "\n");
                } else {
                    sb.append((lDist - (lDist * lSpeed - lMax * lSpeed) / lMax) + "\n");
                }
            } else {
                sb.append("-1\n");
            }
        }
        System.out.println(sb);
    }
}
