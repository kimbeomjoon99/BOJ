import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static final int INF = Integer.MAX_VALUE;
  static int n, m, ans;
  static ArrayList<loc> person;
  static ArrayList<loc> chicken;
  static int[] visited;

  static class loc{
    int x;
    int y;

    public loc(int x, int y){
      this.x = x;
      this.y = y;
    }
  }

  static void BT(int st, int depth){
    
    if (depth == m){
      int sum = 0;
      for (int i = 0; i < person.size(); i++){
        int tmp = INF;
        for (int j = 0; j < chicken.size(); j++){
          if (visited[j] == 1){
            int dist = Math.abs(person.get(i).x - chicken.get(j).x) +
              Math.abs(person.get(i).y - chicken.get(j).y);
            tmp = Math.min(dist, tmp);
          }
        }
        sum += tmp;
      }
      ans = Math.min(ans, sum);
      return;
    }
    for (int i = st; i < chicken.size(); i++){
      visited[i] = 1;
      BT(i + 1, depth + 1);
      visited[i] = 0;
    }
    
  }
  
  public static void main(String[] args) throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    ans = INF;
    person = new ArrayList<>();
    chicken = new ArrayList<>();
    for (int i = 0; i < n; i++){
      st = new StringTokenizer(br.readLine(), " ");
      for (int j = 0; j < n; j++){
        int tmp = Integer.parseInt(st.nextToken());
        if (tmp == 1) person.add(new loc(i, j));
        else if (tmp == 2) chicken.add(new loc(i, j));
      }
    }
    visited = new int[chicken.size()];
    BT(0, 0);
    System.out.println(ans);
  }
}