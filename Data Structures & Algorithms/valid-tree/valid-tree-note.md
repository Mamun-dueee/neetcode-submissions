## Graph Valid Tree: 
### Language: 
1. When data in private, no need to pass the data to helper functions. 
2. If we declare adjacency list in private area, We need to initialize the adj list before using. (before creating the graph) 

### DSA related: 
1. If we need to find cycles in a graph, in that case we have to also pass parent node into dfs() function. 
2. When we call dfs() with first element like 0, we usually use -1 as a parent. ( if -1 can not be a node, in graph problem nodes are usually 0 to n-1. )  

### Algorithm to solve the problem by BFS: 
1. Check weather number of edges == node number -1 ( if not return false).
2. Make the adj list. (create the graph)[private data adj vector of vector] 
3. START BFS: 
4. Take a queue of pair<int, int> (because we need to track the parent) < node, par>
5. while(not empty q ){curNode, parent, if in visited(curNode) return false, for every nei of curNode: check if it is parent (if true: continue), push into the queue with parent}
6. Return visited.size() == n. ( all node are visited or not: cycle exist)  
