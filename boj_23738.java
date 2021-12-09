import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        HashMap<Character, String> map = new HashMap<>();
        map.put('B', "v");
        map.put('E', "ye");
        map.put('H', "n");
        map.put('P', "r");
        map.put('C', "s");
        map.put('Y', "u");
        map.put('X', "h");
        map.put('A', "a");
        map.put('K', "k");
        map.put('M', "m");
        map.put('O', "o");
        map.put('T', "t");
        char[] str = br.readLine().toCharArray();
        for (char c : str) sb.append(map.get(c));
        System.out.println(sb);
    }
}
