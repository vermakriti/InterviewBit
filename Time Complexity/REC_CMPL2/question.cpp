// What is the worst case time complexity of the following code:

int findMinPath(vector<vector<int> > &V, int r, int c) {
  int R = V.size();
  int C = V[0].size();
  if (r >= R || c >= C) return 100000000; // Infinity
  if (r == R - 1 && c == C - 1) return 0;
  return V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
}
// Assume R = V.size() and C = V[0].size().
/*
time complexity = O(2^(R+C))
Explaination:
                              findMinPath(0,0)                                  2^0

          findMinPath(1,0)                        findMinPath(0,1)              2^1

    findMinPath(2,0)    findMinPath(1,1)    findMinPath(1,1)   findMinPath(1,2) 2^2

                                                                                2^3

                                                                                2^4
                                                                                .
                                                                                .
                                                                                .
                                                                                .
      Here function call are made exponetially.That's y time complexity would be O(2^(R+c))                                                                          


*/
