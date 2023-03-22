/*****************************************************************************
*                    
*  Author:           Jorge Santos
*  Title:            Graphviz
*  Course:           2143
*  Semester:         Spring 2021
* 
*  Description:
*        Uses maps and vectors to create output suitable for use
*        in graphviz to generate a graph
* 
*  Usage:
*      create the grap and nodes and modify the attributes of each
* 
*  Files: TBD
*****************************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printHeading(ofstream &fout);

class Attribute
{
protected:
    map<string, string> att; // attributes

public:
    Attribute() {}

    /**
     * Very basic print method to print out some graphviz style
     * code defining an edge.
     */
    // string print() {
    //   return "[color=" + att["color"] + ",arrow_type=" + att["arrow_type"] +
    //   "]";
    // }
    /**
     * Update an edge attribute. Assumes key is valid.
     */
    void addAttribute(string key, string val) { att[key] = val; }

    /**
     * Takes a map of attributes. Loops over them and saves them
     * locally.
     */
    void addAttributes(map<string, string> atts)
    {
        for (auto const &x : atts)
        {
            att[x.first] = x.second;
        }
    }

    /**
     * Use our basic print to dump this class out.
     */
    friend ostream &operator<<(ostream &os, Attribute &e)
    {

        os << "[";

        int i = 0;
        for (auto const &x : e.att)
        {
            os << x.first << "="
               << "\"" << x.second << "\"";

            if (i < e.att.size() - 1)
            {
                os << ", ";
            }
            i++;
        }
        os << "]";

        return os;
    }

    friend fstream &operator<<(fstream &fout, Attribute &e)
    {

        fout << "[";
        int i = 0;
        for (auto const &x : e.att)
        {
            fout << x.first << "="
                 << "\"" << x.second << "\"";
            if (i < e.att.size() - 1)
            {

                fout << ", ";
            }
            i++;
        }

        fout << "]";
        return fout;
    }
    // friend fstream &operator<<(fstream &os, Attribute &e) {
    //   os << "[";
    //   int i = 0;
    //   for (auto const &x : e.att) {
    //     os << x.first << "="
    //        << "\"" << x.second << "\"";
    //     if (i < e.att.size() - 1) {
    //       os << ", ";
    //     }
    //     i++;
    //   }
    //   os << "]";
    //   return os;
    // }
};

class Edge : public Attribute
{
    int eid;
    int start;
    int end;

public:
    Edge()
    {
        att["color"] = "black";    // default color
        att["arrow_type"] = "vee"; // default arrow shape
    }

    Edge(string color, string arrow)
    {
        att["color"] = color;      // default color
        att["arrow_type"] = arrow; // default arrow shape
    }
    Edge(int start, int end)
    {
        this->start = start;
        this->end = end;
    }

    friend ostream &operator<<(ostream &os, Edge &e)
    {
        os << e.start << "->" << e.end << " ";
        os << "[";

        int i = 0;
        for (auto const &x : e.att)
        {
            os << x.first << "="
               << "\"" << x.second << "\"";

            if (i < e.att.size() - 1)
            {
                os << ", ";
            }
            i++;
        }
        os << "]";

        return os;
    }
};

class Node : public Attribute
{
    int nid;

public:
    Node()
    {
        att["color"] = "black";  // default color
        att["shape"] = "record"; // default node shape
        
    }

    Node(map<string, string> atts)
    {
        for (auto const &x : atts)
        {
            att[x.first] = x.second;
        }
    }
};

struct Shape
{
    string shape;
    Shape(string name) { shape = name; }
};

class GraphViz
{
    int edgeId;
    int nodeId;
    vector<Edge> Edges;
    vector<Node> Nodes;
    string graphName;
    string graphShape;
    string Rankdir = "LR";
    string nodeShape;
    //string makeEid(int v, int w) { return to_string(v) + "-" + to_string(w); }

public:
    GraphViz()
    {
        edgeId = 0;
        nodeId = 0;
        graphName = "foo";
    }

    GraphViz(string graph_name, string graph_shape)
    {
        edgeId = 0;
        nodeId = 0;
        graphName = graph_name;
        graphShape = graph_shape;
        if(graph_shape == "LL"){
          nodeShape = "record";
        }
      
          
    }



    /**
   * public : addNode
   *
   * Description:
   *     will stor a node in the vector Nodes
   * Params:
   *      - map<string, string> atts
   * 
   * Returns:
   *      -int
*/
    int addNode()
    {
        Nodes.push_back(Node());
        return Nodes.size() - 1;
    }


    /**
   * public : addNode
   *
   * Description:
   *     will stor a node in the vector Nodes and change a attribute
   * Params:
   *      - map<string, string> atts
   * 
   * Returns:
   *      -int
*/
    int addNode(map<string, string> atts)
    {
        Nodes.push_back(Node(atts));

        return Nodes.size() - 1;
    }


    /**
   * public : updateNode
   *
   * Description:
   *     will change or add an attribute of a node
   * Params:
   *      - int id, string key, string value
   * 
   * Returns:
   *      -void
*/
    void updateNode(int id, string key, string value)
    {
        Nodes[id].addAttribute(key, value);
    }


    /**
   * public : addEdge
   *
   * Description:
   *      will store the start and endpoint of an edge in a vector
   * Params:
   *      - int start, int end
   * 
   * Returns:
   *      -void
*/
    int addEdge(int start, int end)
    {
        // make and edge constructor that receives two ints so you
        // can print them out
        Edges.push_back(Edge(start, end));
        return Edges.size() -1;
    }

  
  /**
   * public : addEdge
   *
   * Description:
   *      will store the start, endpoint, and the attributes
   *of an edge in a vector
   * Params:
   *      - int start, int end, map<string, string> att 
   * 
   * Returns:
   *      -void
*/
    int addEdge(int start, int end, map<string, string> att)
    {

        Edges.push_back(Edge(start, end));
        Edges[Edges.size() - 1].addAttributes(att);
        return Edges.size() -1;
    }

    
  void updateEdge(int id, string key, string value)
    {
        Edges[id].addAttribute(key, value);
    }


  /**
     * Public : overload operator <<
     * 
     * Description:
     *      will print out the nodes and edge info in a way that
     * can be pasted in Graphviz
     * Returns:
     *       ostream os
     *      
     */
    friend ostream &operator<<(ostream &os, GraphViz &g)
    {  
        os << "digraph " << g.graphName << " "; 
        
        os << "{" <<  endl;
      
      if(g.graphName != "BinarySearchTree"){
        os << "rankdir = " << g.Rankdir << ";";
        
      
        os << endl;
        for (int i = 0; i < g.Nodes.size(); i++)
        {
            os << i << " " << g.Nodes[i] << endl;
        }
        }
        for (int i = 0; i < g.Edges.size(); i++)
        {  
          if(g.graphName == "BinarySearchTree"){
            os << g.Edges[i] << endl;
          }
          
          else
            os << i  << ":next:" <<  g.Edges[i] << endl;
            
            if(g.graphName == "DoublyLinkedList")
              
              os << i  << ":prev:" <<  g.Edges[i] << endl;
        }
      os << "}";
        return os;
    }
};

int main()
{
    ofstream fout;
    fout.open("test.out");
    printHeading(fout);
    // create graphviz instances with specific shapes
    GraphViz G("LinkedList", "LL");
    GraphViz D("DoublyLinkedList", "DLL");
    GraphViz B("BinarySearchTree", "BST");

    // used as an example to load attributes for a node
    map<string, string> Box;
    map<string, string> Arrow;
    // example attribute that gets a map of attributes and
    // adds them to "A"
    Attribute A;
    Box["shape"] = "record";
    Box["color"] = "purple";


    //setting default attributes to the edges
    A.addAttributes(Box);
    Arrow["ref"] = "next";
    Arrow["color"] = "orange";
    Arrow["arrowhead"] = "vee";
    Arrow["dir"] = "both";
    Arrow["arrowtail"] = "dot";
    Arrow["tailclip"] = "false";
    A.addAttributes(Arrow);

    // Creating nodes in graphviz and sending in default
    // colors / shapes, etc.
    int nodeId = G.addNode(Box);
    G.updateNode(nodeId, "shape", "record");
    //will seperate reocrd shape into two boxes
    G.updateNode(nodeId, "label", "{ <data> 12 | <next> }");
    nodeId = G.addNode(Box);
    
    G.updateNode(nodeId, "shape", "record");
    G.updateNode(nodeId, "label", "{ <data> 99 | <next> }");
    nodeId = G.addNode(Box);
    G.updateNode(nodeId, "shape", "record");
    G.updateNode(nodeId, "label", "{ <data> 37 | <next> }");
   
    int edgeID = G.addEdge(0, 1, Arrow);
    G.updateEdge(edgeID, "color", "purple");
    G.updateEdge(edgeID, "arrowhead", "crow");
    edgeID = G.addEdge(1, 2, Arrow);
    G.updateEdge(edgeID, "color", "orange");
    G.updateEdge(edgeID, "arrowhead", "inv");
    
    fout << G << endl << endl;

    // making the doubly linked list
    // and sending in default colors and shapes
    nodeId = D.addNode(Box);
    D.updateNode(nodeId, "shape", "record");
    D.updateNode(nodeId, "label", "{ <prev> | <data> 10 | <next> }");
   
    nodeId = D.addNode(Box);
    D.updateNode(nodeId, "shape", "record");
    D.updateNode(nodeId, "label", "{ <prev> | <data> 20 | <next> }");
   
    nodeId = D.addNode(Box);
    D.updateNode(nodeId, "shape", "record");
    D.updateNode(nodeId, "label", "{ <prev> | <data> 30 | <next> }");
   
   
    //for a doubly linked list, a edge to previous will be printed out by the overloaded ostream operator.
    
    D.addEdge(0, 1, Arrow);
    D.addEdge(1, 0, Arrow);
    D.addEdge(1, 2, Arrow);
    D.addEdge(2, 1, Arrow);
   

    fout << D << endl << endl;
    
    Attribute F;

     F.addAttributes(Box);
  
    F.addAttributes(Arrow);

  
   
    nodeId = B.addNode(Box);
    B.updateNode(nodeId, "shape", "polygon");
    nodeId = B.addNode(Box);
    nodeId = B.addNode(Box);
    B.updateNode(nodeId, "shape", "tripleoctagon");
    nodeId = B.addNode(Box);
    nodeId = B.addNode(Box);
    B.updateNode(nodeId, "shape", "invtriangle");
    nodeId = B.addNode(Box);
    nodeId = B.addNode(Box);

    edgeID = B.addEdge(0, 1);
    B.updateEdge(edgeID, "color", "blue");
    B.addEdge(0, 2);
    edgeID = B.addEdge(1, 3);
    B.updateEdge(edgeID, "color", "red");
    edgeID = B.addEdge(1, 4);
    B.updateEdge(edgeID, "arrowhead", "box");
    B.addEdge(2, 5);
    B.addEdge(2, 6);

    fout << B << endl;

    
}
// add and save nodes and edges

//   ofstream fout;
//   fout.open("test.out");
//   printHeading(fout);

//   int start;
//   int end;

//   Edge e;
//   map<string, string> stuff;

//   stuff["fillcolor"] = "red";
//   stuff["nodecolor"] = "purple";
//   stuff["edgestyle"] = "dashed";

//   vector<Node> Nodes;

//   // index = 0-3
//   Nodes.push_back(Node());
//   Nodes.push_back(Node());
//   Nodes.push_back(Node());
//   Nodes.push_back(Node());

//   Nodes[2].addAttribute("fillColor","purple");
//   Nodes[3].addAttribute("fillColor", "red");

//   cout << "digraph" << " someGraph" << "{\n";

//   for(int i=0;i<Nodes.size();i++){
//     cout<<"\t"<<i<<" "<<Nodes[i]<<endl;
//   }
//   cout << "}\n";

//   //   cout<<"=================="<<endl;
//   //   cout<<e<<endl;
//   // cout<<"=================="<<endl;

//   //   GraphViz g;

//   //   start = g.addNode();
//   //   g.updateNode(id,key,value);

//   // g.addEdge(0, 1);
//   // g.addEdge(0, 4);
//   // g.addEdge(1, 2);
//   // g.addEdge(1, 3);
//   // g.addEdge(1, 4);
//   // g.addEdge(2, 3);
//   // g.addEdge(3, 4);
//   // g.addEdge(9, 10);
//   // g.addEdge(4, 9);

//   // g.printGraph();
//   return 0;
// }

 void printHeading(ofstream &fout) {
   fout << "Jorge Santos" << endl;
   fout << "March 2nd, 2023" << endl;
   fout << "Spring 2143" << endl;
   fout << endl;
}