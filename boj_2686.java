import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int p = Integer.parseInt(br.readLine());
        while (p-- > 0) {
            int b = Integer.parseInt(br.readLine());
            int cnt = 0;
            char[] ch = new char[b * 2];
            for (int i = 0; i < (b + 39) / 40; i++) {
                String str = br.readLine();
                int sz = str.length();
                for (int j = 0; j < sz; j++) ch[cnt++] = str.charAt(j);
            }
            int sz = 0;
            String ans = "";
            StringBuilder tsb = new StringBuilder();
            for (int i = 0; i < b; i++) {
                if (i + 2 < b) {
                    if ((ch[i * 2] == ch[i * 2 + 2]) && (ch[i * 2 + 1] == ch[i * 2 + 3]) && (ch[i * 2] == ch[i * 2 + 4]) && (ch[i * 2 + 1] == ch[i * 2 + 5])) {
                        if (sz != 0) {
                            ans = ans + numtoch(sz - 1) + tsb.toString();
                            sz = 0;
                            tsb = new StringBuilder();
                        }
                        sz = 3;
                        while (true) {
                            if (i + sz >= b || sz == 130) break;
                            if (ch[i * 2] == ch[i * 2 + sz * 2] && ch[i * 2 + 1] == ch[i * 2 + sz * 2 + 1]) {
                                sz++;
                            } else {
                                break;
                            }
                        }
                        ans = ans + numtoch(sz + 125) + ch[i * 2] + ch[i * 2 + 1];
                        i += sz - 1;
                        sz = 0;

                    } else {
                        sz++;
                        tsb.append(ch[i * 2] + "" + ch[i * 2 + 1]);
                        if (sz == 128) {
                            ans = ans + numtoch(sz - 1) + tsb.toString();
                            sz = 0;
                            tsb = new StringBuilder();
                        }
                    }
                } else {
                    sz++;
                    tsb.append(ch[i * 2] + "" + ch[i * 2 + 1]);
                    if (sz == 128) {
                        ans = ans + numtoch(sz - 1) + tsb.toString();
                        sz = 0;
                        tsb = new StringBuilder();
                    }
                }
            }
            if (sz != 0) ans = ans + numtoch(sz - 1) + tsb.toString();
            sb.append(ans.length() / 2 + "\n");
            for (int i = 0; i < (ans.length() + 79) / 80; i++) {
                sb.append(ans.substring(i * 80, Math.min((i + 1) * 80, ans.length())) + "\n");
            }
        }
        System.out.println(sb);
    }

    private static String numtoch(int n) {
        int a = n / 16;
        int b = n % 16;
        char A = ' ';
        char B = ' ';
        if (a >= 10) {
            A = (char) ('A' + a - 10);
        } else {
            A = (char) ('0' + a);
        }
        if (b >= 10) {
            B = (char) ('A' + b - 10);
        } else {
            B = (char) ('0' + b);
        }
        return A + "" + B;
    }
}
