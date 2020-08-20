/*
	Floyd Warshall's Algorithm is used to find the shortest paths 
	between between all pairs of vertices in a graph, where each edge 
	in the graph has a weight which is positive or negative. 
	The biggest advantage of using this algorithm is that all the 
	shortest distances between any 2 vertices could be calculated 
	in O(V^3) , where V is the number of vertices in a graph.
*/

const int N = 100;
int dp[N][N];
void init(){
  for(ll i=0 ; i<N ; i++){
    for(ll j=0 ; j<N ; j++){
      dp[i][j]=inf;
    }
  }
  for(ll i=0 ; i<N ; i++){
    dp[i][i]=0;
  }
}
void floydWarshall(int n){
  for(int k=0 ; k<n ; k++){
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
          dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }
  }
}
