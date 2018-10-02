namespace Dijkstra
{
    public class Program
    {
        static void Main(string[] args)
        {
            var graph = Dijkstra.SetupExampleGraph();
            var result = graph.GetShortestPath('1', '5');
            Dijkstra.PathPrinter(result);
        }
    }
}