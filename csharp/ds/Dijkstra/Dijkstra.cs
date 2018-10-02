using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Dijkstra
{
    class Dijkstra
    {
        public static Graph SetupExampleGraph()
        {
            Vertex v1 = new Vertex('1'), v2 = new Vertex('2'), v3 = new Vertex('6');
            Vertex v4 = new Vertex('3'), v5 = new Vertex('5'), v6 = new Vertex('4');

            #region Setup Edges

            v1.Edges = new List<Edge>
            {
                new Edge(v2, 7),
                new Edge(v3, 14),
                new Edge(v4, 9)
            };
            v2.Edges = new List<Edge>
            {
                new Edge(v1, 7),
                new Edge(v4, 10),
                new Edge(v6, 15)
            };
            v3.Edges = new List<Edge>
            {
                new Edge(v1, 14),
                new Edge(v4, 2),
                new Edge(v5, 9),
            };
            v4.Edges = new List<Edge>
            {
                new Edge(v1, 9),
                new Edge(v2, 10),
                new Edge(v3, 2),
                new Edge(v6, 11)
            };
            v5.Edges = new List<Edge>
            {
                new Edge(v3, 9),
                new Edge(v6, 6)
            };
            v6.Edges = new List<Edge>
            {
                new Edge(v2, 15),
                new Edge(v4, 11),
                new Edge(v5, 6)
            };

            #endregion
            
            var graph = new Graph();
            graph.AddVertex(v1);
            graph.AddVertex(v2);
            graph.AddVertex(v3);
            graph.AddVertex(v4);
            graph.AddVertex(v5);
            graph.AddVertex(v6);

            return graph;
        }

        public static void PathPrinter(List<Vertex> path)
        {
            var sb = new StringBuilder();
            var charsAsStrings = path.Select(v => v.Key.ToString());
            Console.WriteLine(String.Join(" => ", path.Select(v => v.Key)));
        }
    }

    class Graph
    {
        // Each graph consists of a number of vertices connected by 'edges'.
        private Dictionary<char, Vertex> _vertices;

        public Graph()
        {
            _vertices = new Dictionary<char, Vertex>();
        }

        public void AddVertex(Vertex vertex)
        {
            _vertices[vertex.Key] = vertex;
        }

        public List<Vertex> GetShortestPath(char start, char finish)
        {
            ResetGraphCost();
            CalculateCost(start, finish);
            
            var path = CalculatePath(start, finish);
            // The path is calculated using the "Previous" vertex property.
            // The path is therefore initially the shortest path from finish to start.
            // Reverse the path to get the shortest path from start to finish
            path.Reverse();
            return path;
        }

        private void ResetGraphCost()
        {
            foreach (var vertex in _vertices.Values)
            {
                vertex.Cost = int.MaxValue;
            }
        }

        private void CalculateCost(char start, char finish)
        {
            // Initialize the start vertex
            _vertices[start].Cost = 0;
            var visitQueue = new Queue<Vertex>();
            visitQueue.Enqueue(_vertices[start]);
            do
            {
                var currentNode = visitQueue.Dequeue();
                if (currentNode.Visisted)
                {
                    continue;
                }
                
                // Visit each neighboring vertex
                foreach (var edge in currentNode.Edges)
                {
                    if (currentNode.Cost + edge.Distance < edge.EndVertex.Cost)
                    {
                        edge.EndVertex.Cost = currentNode.Cost + edge.Distance;
                        edge.EndVertex.Previous = currentNode;
                    }

                    visitQueue.Enqueue(edge.EndVertex);
                }
                currentNode.Visisted = true;
            } while (visitQueue.Any());
        }

        private List<Vertex> CalculatePath(char start, char finish)
        {
            var path = new List<Vertex>();
            var currentVertex = _vertices[finish];
            path.Add(currentVertex);
            do
            {
                currentVertex = currentVertex.Previous;
                path.Add(currentVertex);
            } while (currentVertex.Previous != null);

            return path;
        }
    }

    class Vertex
    {
        public Vertex(char key)
        {
            Key = key;
            Cost = int.MaxValue;
            Edges = new List<Edge>();
        }

        public char Key { get; set; }
        public bool Visisted { get; set; } = false;
        public int Cost { get; set; }
        public Vertex Previous { get; set; }
        public List<Edge> Edges { get; set; }
    }

    class Edge
    {
        public Edge(Vertex vertex, int distance)
        {
            EndVertex = vertex;
            Distance = distance;

        }
        public Vertex EndVertex { get; set; }
        public int Distance { get; set; }
    }
}