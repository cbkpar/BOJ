import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int asz = Integer.parseInt(st.nextToken());
        int bsz = Integer.parseInt(st.nextToken());
        String a = br.readLine();
        String b = br.readLine();
        int[] arr = new int[52];
        int[] tarr = new int[52];
        int cnt = 1;
        for (int i = 0; i < asz; i++) {
            if (a.charAt(i) >= 'a' && a.charAt(i) <= 'z') {
                arr[a.charAt(i) - 'a']++;
            } else {
                arr[a.charAt(i) - 'A' + 26]++;
            }
        }
        for (int i = 0; i < asz; i++) {
            if (b.charAt(i) >= 'a' && b.charAt(i) <= 'z') {
                tarr[b.charAt(i) - 'a']++;
            } else {
                tarr[b.charAt(i) - 'A' + 26]++;
            }
        }
        for (int i = 0; i < 52; i++) {
            if (arr[i] != tarr[i]) {
                cnt--;
                break;
            }
        }
        for (int i = asz; i < bsz; i++) {
            if (b.charAt(i) >= 'a' && b.charAt(i) <= 'z') {
                tarr[b.charAt(i) - 'a']++;
            } else {
                tarr[b.charAt(i) - 'A' + 26]++;
            }
            if (b.charAt(i - asz) >= 'a' && b.charAt(i - asz) <= 'z') {
                tarr[b.charAt(i - asz) - 'a']--;
            } else {
                tarr[b.charAt(i - asz) - 'A' + 26]--;
            }
            for (int j = 0; j < 52; j++) {
                if (arr[j] != tarr[j]) break;
                if (j == 51) cnt++;
            }
        }
        System.out.println(cnt);
    }
}
