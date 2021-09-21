import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long ans = 0;
        int n = Integer.parseInt(br.readLine())-1;
        Stack<num> s = new Stack<>();
        s.add(new num(Integer.parseInt(br.readLine()),1));
        while(n-->0) {
            int t = Integer.parseInt(br.readLine());
            while(!s.isEmpty()) {
                if(s.peek().n>t) {
                    ans++;
                    s.add(new num(t,1));
                    break;
                }else if(s.peek().n==t) {
                    ans += s.peek().cnt;
                    s.add(new num(t,s.pop().cnt+1));
                    if(s.size()>=2) ans++;
                    break;
                }else{
                    ans += s.pop().cnt;
                    if(s.isEmpty()) {
                        s.add(new num(t,1));
                        break;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}

class num {
    int n, cnt;
    public num (int n, int cnt){
        this.n = n;
        this.cnt = cnt;
    }
}
