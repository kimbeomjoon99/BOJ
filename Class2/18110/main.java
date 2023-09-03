import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) throws Exception {
    ArrayList<Integer> arr = new ArrayList<>();
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    int n = Integer.valueOf(st.nextToken());
    for (int i = 0; i < n; i++){
      StringTokenizer tmpst = new StringTokenizer(br.readLine(), " ");
      int m = Integer.valueOf(tmpst.nextToken());
      arr.add(m);
    }
    arr.sort(Comparator.naturalOrder());
    int tmp = (int)Math.round(n * 0.15);
    double sum = 0;
    for (int i = tmp; i < n - tmp; i++){
      sum += arr.get(i);
    }
    System.out.println((int)Math.round(sum / (n - (tmp * 2))));
  }
}
