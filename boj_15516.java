import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static int n,sz;
    static int[] arr;
    static int[] tree;
    static int[] index;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
        sz = (int)Math.pow(2, (int)Math.ceil(Math.log10(n)/Math.log10(2))+1);
        tree = new int[sz+1];
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<n;i++) map.put(arr[i],i);
        index = arr.clone();
        Arrays.sort(index);
        long ans = 0;
        for(int i=0;i<n;i++) {
            int idx = map.get(index[i]);
            arr[idx] = i - sum(idx+1,n-1,1,0,n-1);
            update(0,n-1,1,idx);
        }
        for(int i=0;i<n;i++) sb.append(arr[i]+"\n");
        System.out.println(sb);
    }
    static int update(int l, int r, int index ,int cindex) {
        if(l>cindex||cindex>r) return tree[index];
        if(l==r) return tree[index] = 1;
        int mid = (l+r)/2;
        return tree[index] = update(l,mid,index*2,cindex)+update(mid+1,r,index*2+1,cindex);
    }

    static int sum(int l, int r, int index, int nodel, int noder) {
        if(r<nodel||noder<l) return 0;
        if(l<=nodel&&noder<=r) return tree[index];
        int mid = (nodel+noder)/2;
        return sum(l,r,index*2,nodel,mid)+sum(l,r,index*2+1,mid+1,noder);
    }
}
