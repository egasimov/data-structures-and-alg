
package graphrep;

import java.util.HashMap;
import java.util.Map;


 class Vertex {

    private String element;
    private Map< Vertex, Edge> outgoing;

    public Vertex(String element) {
        this.element = element;
        outgoing = new HashMap<Vertex, Edge>();
    }

    @Override
    public String toString() {
        return '{' + element + '}';
    }

 
    public String getElement() {
        return this.element;
    }
    
    //get hash table to corresponding vertex
    // i.e a.getOutgoing() , get hash table for vertex "a"
    public Map<Vertex,Edge> getOutgoing(){
        return this.outgoing;
    }

}
