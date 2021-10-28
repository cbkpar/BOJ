import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        HashMap<Integer, Integer> mapinit = new HashMap<>();
        HashMap<Integer, Integer> mapcnt = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int t = Integer.parseInt(st.nextToken());
            if (mapinit.containsKey(t)) {
                mapcnt.put(t, mapcnt.get(t) + 1);
            } else {
                mapinit.put(t, i);
                mapcnt.put(t, 1);
            }
        }
        ArrayList<number> arr = new ArrayList<>();
        for (int t : mapinit.keySet()) arr.add(new number(t, mapinit.get(t), mapcnt.get(t)));
        Collections.sort(arr, new Comparator<number>() {
            @Override
            public int compare(number o1, number o2) {
                if (o1.cnt != o2.cnt) return o2.cnt - o1.cnt;
                return o1.init - o2.init;
            }
        });
        for (number N : arr) for (int i = N.cnt; i > 0; i--) sb.append(N.num + " ");
        System.out.println(sb.toString().trim());
    }
}

class number {
    int num;
    int init;
    int cnt;

    public number(int num, int init, int cnt) {
        this.num = num;
        this.init = init;
        this.cnt = cnt;
    }
}
