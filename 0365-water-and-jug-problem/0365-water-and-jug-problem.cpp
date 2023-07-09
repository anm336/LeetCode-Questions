class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
//         queue<pair<int,int>> q;
//         q.push({0, 0});
        
//         int X = jug1Capacity;
//         int Y = jug2Capacity;
//         int target = targetCapacity;
        
//         if(X+Y==target) return true;
//         if(X+Y<target) return false;
//         if(X%2==0 && Y%2==0 && target%2!=0) return false;
        
//         unordered_map<string, int> vis; 
        
//         while(!q.empty()){
//             auto front = q.front();
//             q.pop();
//             int x = front.first;
//             int y = front.second;
//             if(x+y == target) return true;
//             vis[to_string(x)+","+to_string(y)]++;
            
//             int newx, newy;
//             //x-> y
//             newx = x-min(x, Y-y);
//             newy = y+min(x, Y-y);
//             if(vis[to_string(newx)+","+to_string(newy)] == 0) q.push({newx, newy});
//             //y-> x
//             newx = x+min(y, X-x);
//             newy = y-min(y, X-x);
//             if(vis[to_string(newx)+","+to_string(newy)] == 0) q.push({newx, newy});
//             //x empty
//             newx = 0;
//             newy = y;
//             if(vis[to_string(newx)+","+to_string(newy)] == 0) q.push({newx, newy});
//             //y empty
//             newx = x;
//             newy = 0;
//             if(vis[to_string(newx)+","+to_string(newy)] == 0) q.push({newx, newy});
//             //x full
//             newx = X;
//             newy = y;
//             if(vis[to_string(newx)+","+to_string(newy)] == 0) q.push({newx, newy});
//             //y full
//             newx = x;
//             newy = Y;
//             if(vis[to_string(newx)+","+to_string(newy)] == 0) q.push({newx, newy});
//         }
        
//         return false;
        
        return z == 0 || z <= (long long)x + y && z % __gcd(x, y) == 0;
    }
};