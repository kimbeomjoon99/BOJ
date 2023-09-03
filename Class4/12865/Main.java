import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static final int INF = Integer.MAX_VALUE;

  public static void main(String[] args) throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int[] w = new int[n + 1];
    int[] v = new int[n + 1];
    int[][] dp = new int[k + 1][n + 1];
    for (int i = 1; i <= n; i++){
      st = new StringTokenizer(br.readLine(), " ");
      w[i] = Integer.parseInt(st.nextToken());
      v[i] = Integer.parseInt(st.nextToken());
    }

    for (int i = 1; i <= k; i++){
      for (int j = 1; j <= n; j++){
        if (w[j] > i) dp[i][j] = dp[i][j - 1];
        else dp[i][j] = Math.max(dp[i][j - 1], dp[i - w[j]][j - 1] + v[j]);
      }
    }
    System.out.println(dp[k][n]);
  }
}