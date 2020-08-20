const int N = 1000;
vector<int> adj[N];
bool vis[N], flag[N];
stack<int> st;

void init(){
  for(int i=0 ; i<N ; i++){
    adj[i].clear();
    vis[i] = 0;
    flag[i] = 0;
  }
}
void dfs(int s) {
    vis[s] = true;
    for(auto i : adj[s]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    st.push(s);
}
void topologicalSort() {
  for(int i=0 ; i<N ; i++) {
    if(!vis[i] && flag[i]==true) {
      dfs(i);
    }
  }
  while(!st.empty()){
    cout<<st.top()<<' ';
    st.pop();
  } 
}
