/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graphrep;

import java.util.ArrayList;


 class Edge  {
    private int weight;
    private ArrayList<Vertex> endpoints;

    public Edge(Vertex u, Vertex v, int weight) {
        this.weight = weight;
        this.endpoints = new ArrayList<>();
        endpoints.add(u);
        endpoints.add(v);
    }

    public int getWeight() {
        return this.weight;
    }

    public ArrayList<Vertex> getEndPoints() {
        return this.endpoints;
    }

    @Override
    public String toString() {
        return "{"+ endpoints.get(0)+","+endpoints.get(1)+" "+weight +"}";
    }

}