import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());
        ArrayList<Integer> arrTime = new ArrayList<>();
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iHour = Integer.parseInt(st.nextToken());
            int iMinute = Integer.parseInt(st.nextToken());
            int iSecond = Integer.parseInt(st.nextToken());
            int iTime = iHour * 3600 + iMinute * 60 + iSecond;
            arrTime.add(iTime);
        }
        Collections.sort(arrTime);
        for (int iTime : arrTime) {
            sb.append(iTime / 3600 + " " + (iTime % 3600) / 60 + " " + (iTime % 60) + "\n");
        }
        System.out.println(sb);
    }
}
