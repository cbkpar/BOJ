import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        String T = br.readLine();
        int Ssz = S.length();
        int Tsz = T.length();
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < Tsz; i++) map.put(T.charAt(i), i + 1);
        int[] arr = new int[Tsz + 1];
        arr[0] = Ssz;
        for (int i = 0; i < Ssz; i++) {
            if(!map.containsKey(S.charAt(i))) continue;
            int t = map.get(S.charAt(i));
            if (arr[t - 1] == 0) continue;
            arr[t - 1]--;
            arr[t]++;
        }
        System.out.println(arr[Tsz]);
    }
}
