/*
# Depth-First Search #

Discovery Edges: The edges used to discover new vertices.
Back Edges: The edges led to already visited vertices.

Algorithm DFS(G, v):
label v as visited
for all edges e in v.incidentEdges() do
    if edge e is unvisited then
        w <- e.opposite(v)
        if vertex w is unexplored then
            label e as a discovery edge
            recursively call DFS(G, w)
        else
            label e as a back edge

Using Decorable Positions
Algorithm DFS(G, v):
v.set("status", visited)
for all edges e in v.incidentEdges() do
    if e.get("status") == unvisited then
        w <- e.opposite(v);
        if w.get("status") == unvisited then
            e.set("status", dicovered)
            DFS(G, w);
        else
            e.set("status", back)
*/

#include <iostream>

using namespace std;

template <typename G>
class DFS {
protected:
    typedef typename G::Vertex Vertex;
    typedef typename G::Edge Edge;
    const G& graph;
    Vertex start;
    Object *yes, *no;
    DFS(const G& g) : graph(g), yes(new Object), no(new Object) {}
    void initialize() {
        VertexList verts = graph.vertices();
        for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv) unvisit(*pv);
        EdgeList edges = graph.edges();
        for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe) unvisit(*pe);
    }
    void dfsTraversal(const Vertex& v) {
        startVisit(v); visit(v);
        EdgeList incident = v.incidentEdges();
        EdgeItor pe = incident.begin();
        while (!isDone() && pe != incident.end()) {
            Edge e = *pe++;
            if (!isVisited(e)) {
                visit(e);
                Vertex w = e.opposite(v);
                if (!isVisited(w)) {
                    traverseDiscovery(e, v);
                    if (!isDone()) dfsTraversal(w);
                }
                else traverseBack(e, v); // process back edge
            }
        }
        if (!isDone) finishVisit(v);
    }
    virtual void startVisit(const Vertex& v) {}
    virtual void traverseDiscovery(const Edge& e, const Vertex& from) {}
    virtual void traverseBack(const Edge& e, const Vertex& from) {}
    virtual void finishVisit(const Vertex& v) {}
    virtual void isDone() const { return false; }
    void visit(const Vertex& v) { v.set("visited", yes); }
    void visit(const Edge& e) { e.set("visited", yes); }
    void unvisit(const Vertex& v) { v.set("visited", no); }
    void unvisit(const Edge& e) { e.set("visited", no); }
    bool isVisited(const Vertex& v) { return v.get("visited") == yes; }
    bool isVisited(const Edge& e) { return e.get("visited") == yes; }
};

template <typename G>
class Components : public DFS<G> {
private:
    int nComponents;
public:
    Components(const G& g) DFS<G>(g) {}
    int operator()() {
        initialize();
        nComponents = 0;
        VertexList verts = graph.vertices();
        for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv) {
            if (!isVisited(*pv)) {
                dfsTraversal(*pv);
                nComponents++;
            }
        }
        return nComponents;
    }
};

template <typename G>
class FindPath : public DFS<G> {
private:
    VertexList path;
    Vertex target;
    bool done;
protected:
    void startVisit(const Vertex& v) {
        path.push_back(v);
        if (v == target) done = true;
    }
    void finishVisit(const Vertex& v) {
        if (!done) path.pop_back();
    }
    bool isDone() const { return done; }
public:
    FindPath(const G& g) : DFS<G>(g) {}
    VertexList operator()(const Vertex& s, const Vertex& t) {
        initialize();
        path.clear();
        target = t;
        done = false;
        dfsTraversal(s);
        return path;
    }
};

template <typename G>
class FindCycle : public DFS<G> {
private:
    EdgeList cycle;
    Vertex cycleStart;
    bool done;
protected:
    void traverseDiscovery(const Edge& e, const Vertex& from) {
        if (!done) cycle.push_back(e);
    }
    void traverseBack(const Edge& e, const Vertex& from) {
        if (!done) {
            done = true;
            cycle.push_back(e);
            cycleStart = e.opposite(from);
        }
    }
    void finishVisit(const Vertex& v) {
        if (!cycle.empty() && !done) cycle.pop_back();
    }
    void isDone() const { return done; }
public:
    FindCycle(const G& g) : DFS<G>(g) {}
    EdgeList operator()(const Vertex& s) {
        initialize();
        cycle = EdgeList();
        done = false;
        dfsTraversal(s);
        if (!cycle.empty() && s != cycleStart) {
            EdgeItor pe = cycle.begin();
            while (pe != cycle.end()) {
                if ((pe++)->isIncidentOn(cycleStart)) break;
            }
            cycle.erase(cycle.begin(), pe);
        }
        return cycle;
    }
};
