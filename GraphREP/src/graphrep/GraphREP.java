package graphrep;

import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class GraphREP {

    public static void main(String[] args) {
        AdjMapGraph G = new AdjMapGraph();
        Vertex Baku = G.insertVertex("Baku");
        Vertex Ganja = G.insertVertex("Ganja");
        Vertex Agstafa = G.insertVertex("Aghstafa");
        Vertex Naxchivan = G.insertVertex("Naxchivan");
        Vertex Astara = G.insertVertex("Astara");
        G.insertEdge(Baku, Agstafa, 400);
        G.insertEdge(Astara, Ganja, 600);
        G.insertEdge(Baku, Ganja, 380);
        G.insertEdge(Ganja, Naxchivan, 500);


    }
    }


