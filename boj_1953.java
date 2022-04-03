import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] arr = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            while (cnt-- > 0) {
                arr[i].add(Integer.parseInt(st.nextToken()));
            }
        }
        boolean[] chk = new boolean[n + 1];
        ArrayList<Integer> Team_A = new ArrayList<>();
        ArrayList<Integer> Team_B = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (chk[i]) continue;
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            chk[i] = true;
            Team_A.add(i);
            boolean isTeamA = false;
            while (!q.isEmpty()) {
                int sz = q.size();
                while (sz-- > 0) {
                    int p = q.poll();
                    for (int t : arr[p]) {
                        if (chk[t]) continue;
                        chk[t] = true;
                        q.add(t);
                        if (isTeamA) {
                            Team_A.add(t);
                        } else {
                            Team_B.add(t);
                        }
                    }
                }
                isTeamA = !isTeamA;
            }
        }
        Collections.sort(Team_A);
        Collections.sort(Team_B);
        int Asz = Team_A.size();
        int Bsz = Team_B.size();
        sb.append(Asz + "\n");
        for (int i = 0; i < Asz - 1; i++) sb.append(Team_A.get(i) + " ");
        sb.append(Team_A.get(Asz - 1) + "\n");
        sb.append(Bsz + "\n");
        for (int i = 0; i < Bsz - 1; i++) sb.append(Team_B.get(i) + " ");
        sb.append(Team_B.get(Bsz - 1) + "\n");
        System.out.println(sb);
    }
}
