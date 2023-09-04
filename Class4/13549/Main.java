import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static final int INF = Integer.MAX_VALUE;
  static int n, k;
  static int[] visited;

  static class pii{
    int loc;
    int time;

    public pii(int loc, int time){
      this.loc = loc;
      this.time = time;
    }
  }

  static void BFS(){
    Queue<pii> q = new LinkedList<>();
    visited[n] = 0;
    pii cur = new pii(n, 0);
    q.add(cur);
    while(!q.isEmpty()){
      cur = q.peek();
      if (cur.loc != 0 && cur.loc * 2 <= 100000 && cur.time < visited[cur.loc * 2]){
        visited[cur.loc * 2] = cur.time;
        q.add(new pii(cur.loc * 2, cur.time));
      }
      if (cur.loc != 0 && cur.time + 1 < visited[cur.loc - 1]){
        visited[cur.loc - 1] = cur.time + 1;
        q.add(new pii(cur.loc - 1, cur.time + 1));
      }
      if (cur.loc + 1 <= 100000 && cur.time + 1 < visited[cur.loc + 1]){
        visited[cur.loc + 1] = cur.time + 1;
        q.add(new pii(cur.loc + 1, cur.time + 1));
      }
      q.remove();
    }
    return;
  }

  public static void main(String[] args) throws Exception {
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    n = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    visited = new int[100001];
    for (int i = 0; i <= 100000; i++) visited[i] = INF;
    BFS();
    System.out.println(visited[k]);
  }
}