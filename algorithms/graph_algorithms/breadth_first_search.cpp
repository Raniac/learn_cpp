/*
# Breadth-First Search #

Discovery Edges: The edges used to discover new vertices.
Cross Edges: The edges led to already visited vertices.

Algorithm BFS(s):
initialize collection L(0) to contain vertex s
i <- 0
while L(i) is not empty do
    create collection L(i+1) to initially be empty
    for all vertices v in L(i) do
        for all edges e in v.incidentEdges() do
            if edge e is unexplored then
                w <- e.opposite(v)
                if vertex w is unexplored then
                    label e as a discovery edge
                    insert w into L(i+1)
                else
                    label e as a cross edge
    i <- i + 1
*/