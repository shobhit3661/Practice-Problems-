class Pair implements Comparable<Pair>{
        int row,col,val;
        public Pair(int row,int col, int val){
            this.row = row;
            this.col = col;
            this.val = val;
        }
        public int compareTo(Pair other){
            return this.val - other.val;
        }
        
}
class Solution {
    public int trapRainWater(int[][] heightMap) 
    {
        int h = heightMap.length;
        int w = heightMap[0].length;
        int ans = bfs(h,w,heightMap);
        return ans;
    }
    
    public int bfs(int h,int w,int[][] map)
    {
        int ans =0;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        int[][] visited = new int[h][w];
        for (int i = 0, len = visited.length; i < len; i++)
            Arrays.fill(visited[i], 0);
        
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(i==0 || j==0 || i==h-1 || j==w-1)
                {
                    visited[i][j] = -1;
                    pq.add(new Pair(i,j,map[i][j]));
                }
            }
        }
        
        int[] x = {0,1,0,-1};
        int[] y = {1,0,-1,0};
        
        while(!pq.isEmpty())
        {
            Pair min = pq.remove();
            
            for(int i=0;i<=3;i++)
            {
                int row = min.row+x[i];
                int col = min.col+y[i];
                
                //check
                if(row>=0 && col >=0 && row <h && col<w && visited[row][col]==0)
                {
                    if(map[row][col] < min.val)
                    {
                        ans += (min.val-map[row][col]);
                        pq.add(new Pair(row,col,min.val));   
                    }
                    else
                    {
                        pq.add(new Pair(row,col,map[row][col]));
                    }
                    visited[row][col] = -1;
                }
            }
        }
        return ans;
    }
}
