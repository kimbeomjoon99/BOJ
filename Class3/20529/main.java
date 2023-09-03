import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) throws Exception {
    int t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++){
      int n = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine(), " ");
      int ans = Integer.MAX_VALUE;
      String arr[] = new String[n];
      for (int j = 0; j < n; j++){
        arr[j] = st.nextToken();
      }
      if (n > 32){
        System.out.println(0);
        continue;
      }
      for (int j = 0; j < n - 2; j++){
        for (int k = j + 1; k < n - 1; k++){
          for (int l = k + 1; l < n; l++){
            int sum = 0;
            for (int x = 0; x < 4; x++){
              if (arr[j].charAt(x) != arr[k].charAt(x)) sum++;
              if (arr[k].charAt(x) != arr[l].charAt(x)) sum++;
              if (arr[l].charAt(x) != arr[j].charAt(x)) sum++;
            }
            if (sum < ans) ans = sum;
          }
        }
      }
      System.out.println(ans);
    }
  }
}
