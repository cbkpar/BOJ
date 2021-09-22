import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, k, mi, cnt, t, sz, ny, nx;
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        mi = Integer.MAX_VALUE;
        boolean[][] chk = new boolean[n][n];
        boolean[][] chk2;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (!chk[i][j] && map[i][j] == 1) {
                    Queue<pos> q = new LinkedList<>();
                    Queue<pos> island = new LinkedList<>();
                    chk2 = new boolean[n][n];
                    q.add(new pos(i, j));
                    chk[i][j] = true;
                    chk2[i][j] = true;
                    while (!q.isEmpty()) {
                        pos p = q.poll();
                        island.add(p);
                        for (k = 0; k < 4; k++) {
                            ny = p.y + dy[k];
                            nx = p.x + dx[k];
                            if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) continue;
                            if (chk[ny][nx] || map[ny][nx] == 0) continue;
                            chk2[ny][nx] = chk[ny][nx] = true;
                            q.add(new pos(ny, nx));
                        }
                    }
                    cnt = 0;
                    boolean exit = false;
                    while (!island.isEmpty()) {
                        if(exit) break;
                        sz = island.size();
                        for (t = 0; t < sz; t++) {
                            if(exit) break;
                            pos p = island.poll();
                            for(k=0;k<4;k++){
                                ny = p.y + dy[k];
                                nx = p.x + dx[k];
                                if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) continue;
                                if (chk2[ny][nx]) continue;
                                chk2[ny][nx] = true;
                                if(map[ny][nx]==0){
                                    island.add(new pos(ny,nx));
                                }else{
                                    mi = Math.min(mi,cnt);
                                    exit = true;
                                    break;
                                }
                            }
                        }
                        cnt++;
                    }
                }
            }
        }
        System.out.println(mi);
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
