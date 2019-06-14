package graphrep;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

public class AdjMapGraph {

    private ArrayList<Vertex> listOfVertices;
    private ArrayList<Edge> listOfEdges;

    public AdjMapGraph() {
        this.listOfEdges = new ArrayList<Edge>();
        this.listOfVertices = new ArrayList<Vertex>();
    }

    Vertex insertVertex(String eleman) {
        Vertex new_element = new Vertex(eleman);
        listOfVertices.add(new_element);

        return new_element;
    }

    void removeVertex(Vertex deleted) {
        Set<Vertex> neighbours = deleted.getOutgoing().keySet();
        Iterator<Vertex> iter=neighbours.iterator();
        
        while(iter.hasNext()){
            Vertex komsu=iter.next();
//            Edge deleted_edge=deleted.getOutgoing().get(komsu);
//            listOfEdges.remove(deleted_edge);
//            
//            komsu.getOutgoing().remove(deleted);
//            deleted.getOutgoing().remove(komsu);
              rmE(deleted.getOutgoing().get(komsu));
//            System.out.println(komsu.getElement());
        }
        listOfVertices.remove(deleted);
    }

    
    Edge insertEdge(Vertex u, Vertex v, int element) {
        //creating new edge between u and v with weights of "element"
        Edge e = new Edge(u, v, element);

        //constructing hash table for each vertex ,  using other vertex as key , access EDGE
        u.getOutgoing().put(v, e);
        v.getOutgoing().put(u, e);
        listOfEdges.add(e);
        return e;

    }

  // for different purpose  
    private void rmE(Edge e){
        ArrayList<Vertex> alist=e.getEndPoints();
        Vertex a=alist.get(0);
        Vertex b=alist.get(1);
        
        a.getOutgoing().remove(b);
        b.getOutgoing().remove(a);
        listOfEdges.remove(e);
    }
    
    void removeEdge(Vertex u, Vertex v) {
        //finding appropripate edge between u and v
        Edge removed_edge = u.getOutgoing().get(v);
        //clear its endpoints
        //removed_edge.getEndPoints().clear();
        //remove from EdgeList
        listOfEdges.remove(removed_edge);
        //remove  records from hashTable
        u.getOutgoing().remove(v);
        v.getOutgoing().remove(u);

    }

    Set findAllNeighbours(Vertex v) {
        return v.getOutgoing().keySet();
    }

    int findDegree(Vertex v) {
        return v.getOutgoing().size();
    }

    Collection<Edge> findIncidentEdges(Vertex v) {
        return v.getOutgoing().values();
    }

    int getsizeOfAllEdges() {
        return listOfEdges.size();
    }

    int getSizeOfAllVertices() {
        return listOfVertices.size();
    }

    public ArrayList<Vertex> getListOfVertices() {
        return listOfVertices;
    }

    public ArrayList<Edge> getListOfEdges() {
        return listOfEdges;
    }

}
