package djikstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Djikstra {

    static int[][] Adj;
    static int[] Label;
    static boolean[] isVisited;
    static int n, a, z;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = sc.nextInt();
        z = sc.nextInt();
        Adj = new int[n + 1][n + 1];
        Label = new int[n + 1];
        isVisited = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                Adj[i][j] = sc.nextInt();
            }
        }

        int path_len = CalcShortestPath();
        System.out.println(path_len);
    }

    static int CalcShortestPath() {
        //initilazition process
        for (int i = 1; i <= n; i++) {
            Label[i] = Integer.MAX_VALUE;
        }
        Label[a] = 0;

        while (!isVisited[z]) {
            int v = getVertex();
            if (v == -1) {
                return -1;
            }
            isVisited[v] = true;

            for (int i = 1; i <= n; i++) {
                if (!isVisited[i] && Adj[v][i] > 0) {
                    if ((Label[v] + Adj[v][i]) < Label[i]) {
                        Label[i] = Label[v] + Adj[v][i];
                    }
                }
            }
        }

        return Label[z];

    }

    static int getVertex() {
        int labelvalue = Integer.MAX_VALUE;
        int v_no = -1;
        for (int i = 1; i <= n; i++) {
            if (Label[i] < labelvalue && !isVisited[i]) {
                labelvalue = Label[i];
                v_no = i;
            }
        }
        return v_no;
    }

}
