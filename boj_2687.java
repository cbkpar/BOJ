import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int p = Integer.parseInt(br.readLine());
        while (p-- > 0) {
            StringBuilder tsb = new StringBuilder();
            int b = Integer.parseInt(br.readLine());
            char[] ch = new char[b * 2];
            int cnt = 0;
            for (int i = 0; i < (b + 39) / 40; i++) {
                String str = br.readLine();
                int sz = str.length();
                for (int j = 0; j < sz; j++) ch[cnt++] = str.charAt(j);
            }
            cnt = 0;
            for (int i = 0; i < b * 2; ) {
                int repeat = 0;
                if (ch[i] >= 'A' && ch[i] <= 'F') {
                    repeat += ch[i] - 'A' + 10;
                } else {
                    repeat += ch[i] - '0';
                }
                repeat *= 16;
                if (ch[i + 1] >= 'A' && ch[i + 1] <= 'F') {
                    repeat += ch[i + 1] - 'A' + 10;
                } else {
                    repeat += ch[i + 1] - '0';
                }
                if (repeat >= 128) {
                    repeat -= 125;
                    while (repeat-- > 0) {
                        if (cnt % 40 == 0) tsb.append("\n");
                        tsb.append(ch[i + 2] + "" + ch[i + 3]);
                        cnt++;
                    }
                    i += 4;
                } else {
                    repeat++;
                    i += 2;
                    while (repeat-- > 0) {
                        if (cnt % 40 == 0) tsb.append("\n");
                        tsb.append(ch[i] + "" + ch[i + 1]);
                        i += 2;
                        cnt++;
                    }
                }
            }
            sb.append(cnt + "" + tsb);
            if (p > 0) sb.append("\n");
        }
        System.out.println(sb);
    }
}
