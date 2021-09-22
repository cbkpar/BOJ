import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, k, i;
        n = Integer.parseInt(br.readLine());
        Trie trie = new Trie("");
        while (n-- > 0) {
            Trie node = trie;
            StringTokenizer st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            for (i = 0; i < k; i++) {
                String str = st.nextToken();
                if (!node.map.containsKey(str)) {
                    node.map.put(str, node.node.size());
                    node.node.add(new Trie(str));
                    node = node.node.get(node.node.size() - 1);
                } else {
                    node = node.node.get(node.map.get(str));
                }
            }
        }
        dfs(trie, 0);
        System.out.println(sb);
    }

    public static void dfs(Trie trie, int d) {
        for (String name : trie.map.keySet()) {
            for (int i = 0; i < d; i++) sb.append("--");
            sb.append(name + "\n");
            dfs(trie.node.get(trie.map.get(name)), d + 1);
        }
    }
}

class Trie {
    String str;
    ArrayList<Trie> node;
    TreeMap<String, Integer> map;

    public Trie(String str) {
        this.str = str;
        node = new ArrayList<>();
        map = new TreeMap<>();
    }
}
