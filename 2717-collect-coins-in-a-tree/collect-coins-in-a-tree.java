  class Solution {
    void degree(int[][] edges, int[] degree) {
      for (int[] e : edges) {
        degree[e[0]]++;
        degree[e[1]]++;
      }
    }

    public int collectTheCoins(int[] coins, int[][] edges) {
      int n = coins.length;
      int totalEdges = 2 * edges.length;
      int deletedEdges = 0;

      int[][] g = new int[n][];

      int[] degree = new int[n];

      degree(edges, degree);

      Arrays.setAll(g, i -> new int[degree[i]]);

      for (int[] e : edges) {
        g[e[0]][--degree[e[0]]] = e[1];
        g[e[1]][--degree[e[1]]] = e[0];
      }
      degree(edges, degree);

      int mn = n + 1;
      int[] queue = new int[mn];
      int left = 0;
      int right = -1;
      int sz = 0;

      for (int i = 0; i < n; i++)
        if (degree[i] == 1 && coins[i] == 0)
          queue[++right] = i;

      sz = right + 1;

      while (sz > 0) {

        int cur = queue[left];
        left = (left + 1) % mn;
        sz--;

        if (degree[cur] == 0)
          continue;

        degree[cur]--;

        for (int node : g[cur]) {

          int nei = node;

          if (degree[nei] > 0) {

            degree[nei]--;

            if (degree[nei] == 1 && coins[nei] == 0) {
              right = (right + 1) % mn;
              queue[right] = nei;
              sz++;

            }
            deletedEdges += 2;
            break;
          }
        }
      }
      left = 0;
      right = -1;
      sz = 0;

      for (int i = 0; i < n; i++)
        if (degree[i] == 1)
          queue[++right] = i;

      sz = right + 1;
      int rounds = 2;

      while (rounds-- > 0) {

        int size = sz;

        while (size-- > 0) {

          int cur = queue[left];
          left = (left + 1) % mn;
          sz--;

          if (degree[cur] == 0)
            continue;

          degree[cur]--;

          for (int node : g[cur]) {

            int nei = node;

            if (degree[nei] > 0) {

              degree[nei]--;

              if (degree[nei] == 1) {
                right = (right + 1) % mn;
                queue[right] = nei;
                sz++;
              }

              deletedEdges += 2;
              break;
            }
          }
        }
      }

      return totalEdges - deletedEdges;
    }
  }