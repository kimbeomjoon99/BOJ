import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static final int INF = Integer.MAX_VALUE;

  public static void main(String[] args) throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    String strFirst = st.nextToken();
    String strSecond = br.readLine();
    int idxFirst = strFirst.length();
    int idxSecond = strSecond.length();
    int[][] arr = new int[idxFirst + 1][idxSecond + 1];
    for (int i = 0; i <= idxFirst; i++){
      for (int j = 0; j <= idxSecond; j++){
        arr[i][j] = 0;
      }
    }
    for (int i = 1; i <= idxFirst; i++){
      for (int j = 1; j <= idxSecond; j++){
        if (strFirst.charAt(i - 1) == strSecond.charAt(j - 1)){
          arr[i][j] = arr[i - 1][j - 1] + 1;
        }
        else{
          arr[i][j] = Integer.max(arr[i - 1][j], arr[i][j - 1]);
        }
      }
    }
    System.out.println(arr[idxFirst][idxSecond]);
  }
}
