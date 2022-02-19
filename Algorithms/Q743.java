package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class Q743 
{
	
}
class pair{
    int target;
    int weight;
    pair(int target,int weight)
    {
        this.target = target;
        this.weight = weight;
    }
}
class Solution {
    
    public int networkDelayTime(int[][] times, int n, int k) 
    {
        Map<Integer,List<pair>> adj = new HashMap<>();
        for(int[] time : times)
        {
            adj.putIfAbsent(time[0],new ArrayList<>());
            adj.get(time[0]).add(new pair(time[1],time[2]));
        }
        
        int[] minW = new int[n+1];
        Arrays.fill(minW,Integer.MAX_VALUE);
        BFS(minW,adj,k);
        int sol = 0;
        for(int i=1;i<=n;i++)
        {
            sol = Math.max(sol,minW[i]);
        }
        
        return sol==Integer.MAX_VALUE ? -1 : sol;
    }
    
    
    public void BFS(int[] minW,Map<Integer,List<pair>> adj,int sourceNode)
    {
        Queue<Integer> q = new LinkedList<>();
        q.add(sourceNode);
        
        minW[sourceNode] = 0;
        
        while(!q.isEmpty())
        {
            int currentNode = q.remove();
            if(!adj.containsKey(currentNode))
            {
                continue;
            }
            
            for(pair p : adj.get(currentNode))
            {
                int weight = p.weight;
                int target = p.target;
                
                int totelWeight = minW[currentNode]+weight;
                if(minW[target]>totelWeight)
                {
                    minW[target] = totelWeight;
                    q.add(target);
                }
            }
        }
    }
}

