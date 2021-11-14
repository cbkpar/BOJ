import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<line> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            arr.add(new line(s, e));
        }
        Collections.sort(arr, new Comparator<line>() {
            @Override
            public int compare(line o1, line o2) {
                return o1.s - o2.s;
            }
        });
        ArrayList<Integer> linenum = new ArrayList<>();
        linenum.add(-1);
        for (int i = 0; i < n; i++) {
            int t = arr.get(i).e;
            if (t > linenum.get(linenum.size() - 1)) {
                arr.get(i).order = linenum.size();
                linenum.add(t);
            } else {
                int left = 0;
                int right = linenum.size() - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (linenum.get(mid) < t) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                arr.get(i).order = left;
                linenum.set(left, t);
            }
        }
        int tmp = linenum.size() - 1;
        Stack<Integer> s = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            if (arr.get(i).order == tmp) {
                tmp--;
            } else {
                s.add(arr.get(i).s);
            }
        }
        sb.append(s.size() + "\n");
        while (!s.isEmpty()) sb.append(s.pop() + "\n");
        System.out.println(sb);
    }
}

class line {
    int s;
    int e;
    int order = 0;

    public line(int s, int e) {
        this.s = s;
        this.e = e;
    }
}
