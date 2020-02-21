#ifndef TREE_DRAWING
#define TREE_DRAWING
#include<bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"
#include "ModifiedBresenhamLine.h"
#include "../CircleAlgorithm/BresenhamCircle.h"

using namespace std;

/**
 *  A test class. A more elaborate class description.
 */
class TreeDrawing
{
    private:
        vector<int> L;
        vector<int> R;
        vector<Point> centers;
        vector<int> offset;
        vector<bool> thread;
        vector<int> lmost;
        vector<int> rmost;
        vector<int> level;
        const int printOffset = 512;  
        const int minSep = 60; 
        int n;     

    public:

        
        /**
          * Constructor of the TreeDrawing class.
          * @param adj the adjacency list representation of the tree.
          */
        TreeDrawing(vector<pair<int,int>> &adj)
        {
            n = adj.size();
            for(int i = 0 ; i < n; i++) {
                L.push_back(adj[i].first);
                R.push_back(adj[i].second);
                centers.push_back(Point(0,0));
                lmost.push_back(i);
                rmost.push_back(i);
                offset.push_back(0);
                level.push_back(0);
                thread.push_back(false);
            }
        }

        void setup(int node, int lev)
        {
            if(L[node] != -1)
                setup(L[node], lev+1);
            if(R[node] != -1)
                setup(R[node], lev+1);
            
            // Setting the level of the node
            
            level[node] = lev;

            // If this is a leaf, we're already done
            if(L[node] == -1 && R[node] == -1)
                return;

            // Initializing LL, LR, RL and RR nodes            
            int LL = -1, LR = -1, RL = -1, RR = -1;
            
            if(L[node] != -1) {
                LL = lmost[L[node]];
                LR = rmost[L[node]];
            }

            if(R[node] != -1) {
                RL = lmost[R[node]];
                RR = rmost[R[node]];
            }
            
            // Initializing variables

            int currSep = minSep;
            int rootSep = minSep;
            int l = L[node];
            int r = R[node];
            int lOffSum = 0, rOffSum = 0;

            // Compute the tree seperation

            while(l != -1 && r != -1) {

                if(currSep < minSep) {
                    rootSep = rootSep + (minSep - currSep);
                    currSep = minSep;
                }

                if(R[l] != -1) {
                    lOffSum += offset[l];
                    currSep -= offset[l];
                    l = R[l];
                }
                else
                {
                    lOffSum -= offset[l];
                    currSep += offset[l];
                    l = L[l];
                }

                if(L[r] != -1) {
                    rOffSum -= offset[r];
                    currSep -= offset[r];
                    r = L[r];
                }
                else
                {
                    lOffSum += offset[r];
                    currSep += offset[r];
                    r = R[r];
                }
            }
            
            // Setting the offset of the root and the current l and r nodes.
            
            offset[node] = (rootSep + 1)/2;
            lOffSum -= offset[node];
            rOffSum += offset[node];

            // Update the extreme descendants of the tree

            if(level[RL] > level[LL] || L[node] == -1) {
                lmost[node] = RL;
                offset[lmost[node]] += offset[node];
            }
            else {
                lmost[node] = LL;
                offset[lmost[node]] -= offset[node];
            }

            if(level[LR] > level[RR] || R[node] == -1) {
                rmost[node] = LR;
                offset[rmost[node]] -= offset[node];
            }

            else {
                rmost[node] = RR;
                offset[rmost[node]] += offset[node];
            }

            // Inserting a thread if the subtrees are of unequal height

            if(l != -1 && l != L[node]) {
                thread[RR] = true;
                int temp = offset[RR];
                offset[RR] = abs((offset[RR] + offset[node]) - lOffSum);
                if(lOffSum <= temp + offset[node])
                    L[RR] = l;
                else
                    R[RR] = l;
            }

            else if(r!= -1 && r != R[node]) {
                thread[LL] = true;
                int temp = offset[LL];
                offset[LL] = abs((offset[LL] - offset[node]) - rOffSum);
                if(rOffSum >= temp - offset[node])
                    R[LL] = r;
                else
                    L[LL] = r;
            }

        }


        // Method to compute the coordinates
        void findCoordinates(int node, int lev, int xcoord)
        {
            centers[node].y = (700 - lev * 60);
            centers[node].x = xcoord;
            if(thread[node]) {
                thread[node] = false;
                L[node] = -1;
                R[node] = -1;
            }
            if(L[node] != -1)
                findCoordinates(L[node], lev+1, xcoord - offset[node]);
            if(R[node] != -1)
                findCoordinates(R[node], lev+1, xcoord + offset[node]);
        }

        void plotTree()
        {
            setup(0,0);
            findCoordinates(0,0,0);
            for(int i = 0; i < n; i++) {
                centers[i].x = centers[i].x + printOffset;
            }

            BresenhamCircleDrawing circleDrawer = BresenhamCircleDrawing(Point(0,0),20);
            
            // Drawing all the nodes

            for(int i = 0; i < n ; i++) {
                circleDrawer.changeCenter(centers[i]);
                circleDrawer.bresenhamCircle();
            }

            // Drawing the edges

            ModifiedBresenhamLineDrawing lineDrawer = ModifiedBresenhamLineDrawing(centers[0],centers[0]);
            for(int i = 0; i < n; i++) {
                if(L[i] != -1) {
                    lineDrawer.changeStart(centers[i]);
                    lineDrawer.changeEnd(centers[L[i]]);
                    lineDrawer.modifiedBresenhamLine();
                }
                if(R[i] != -1) {
                    lineDrawer.changeStart(centers[i]);
                    lineDrawer.changeEnd(centers[R[i]]);
                    lineDrawer.modifiedBresenhamLine();
                }
            }
        }
};

#endif