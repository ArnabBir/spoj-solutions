#include <bits/stdc++.h>
using namespace std;

bool furnitureMoved(vector< vector <bool> > & canAccess, vector<bool> & visited, vector< pair<int, int> > & dx, long long int e,long long int f, long long int a, long long int b) {
    
    if(a >= f || a < 0)  return false;
    if(a == b)  return true;
    for(int i = 0; i < e; ++i) {
        if(canAccess[i][a]) {
            if((b >= dx[i].second) && (abs(b-a) % dx[i].first == 0)) {
                return true;
            }
            if(a+dx[i].first < f  && !visited[a+dx[i].first]) {
                visited[a+dx[i].first] = true;
                if(furnitureMoved(canAccess, visited, dx, e, f, a + dx[i].first, b)) {
                    return true;
                }
            }
            if(a-dx[i].first >= dx[i].second  && !visited[a-dx[i].first]) {
                visited[a-dx[i].first] = true;
                if(furnitureMoved(canAccess, visited, dx, e, f, a - dx[i].first, b)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int t, x, y, a, b, e, f;
    cin>>t;
    while(t--) {
        cin>>f>>e>>a>>b;
        vector< vector<bool>> canAccess(e, vector<bool> (f, false));
        vector< pair<int, int> > dx(e);
        vector<bool> visited(f, false);
        for(int i = 0; i < e; ++i) {
            cin>>x>>y;
            dx[i] = make_pair(x, y);
            while(y < f) {
                canAccess[i][y] = true;
                y += x;
            }
        }
        visited[a] = true;
        if(furnitureMoved(canAccess, visited, dx, e, f, a, b)) {
            cout<<"It is possible to move the furniture."<<endl;
        }
        else {
            cout<<"The furniture cannot be moved."<<endl;
        }
    }
	return 0;
}
