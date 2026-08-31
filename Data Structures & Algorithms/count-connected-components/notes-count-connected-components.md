## Intuition: 
We will go 0 to n-1 and check whether the node already visited (if not visited: increase result run DFS(node)) 

### Algorithm:
1. Take a visited vector with all initially false value.
2. Take a adj matrix for create the graph.
3. Iterate i from 0 to n-1:
   - if not visited: res++ and DFS(i).
4. Return res.

#### DFS(curNode): 
1. If visited: return
2. Mark as visited.
3. Iterate every nei of curNode: run DFS(nei)
4. Return. 
