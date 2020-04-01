using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
  Tran Tat Huy
  huyict58@gmail.com      
*/

namespace Overoll.Library.ElasticSearch
{
    class DocumentSimilarityAlgorithm
    {
        // find inner product
        // This means that we have the frequencies for both the first and the second document and now we can add these together where the words intersect.
        public int ComputeInnerProduct(Dictionary<string, int> first, Dictionary<string, int> second)
        {
            var sum = 0;
            foreach (var key in first.Keys)
            {
                if (second.ContainsKey(key)) sum += first[key] * second[key];
            }

            return sum;
        }

        // cosine distance of 2 documents
        public double ComputeDistance(Dictionary<string, int> first, Dictionary<string, int> second)
        {
            var numerator = ComputeInnerProduct(first, second);

            var denominator = Math.Sqrt(ComputeInnerProduct(first, first) * ComputeInnerProduct(second, second));

            return Math.Acos(numerator / denominator);
        }

        // compute freq of a document
        public Dictionary<string, int> ComputeFrequency(string[] input)
        {
            var result = new Dictionary<string, int>();

            for (var i = 0; i < input.Length; i++)
            {
                if (result.ContainsKey(input[i]))
                {
                    result[input[i]]++;
                }
                else
                {
                    result.Add(input[i], 1);
                }
            }

            return result;
        }

        // get all the word from a string
        public string[] GetWords(string text)
        {
            var words = new List<string>();
            var characters = new List<char>();

            var input = text;
            var seperators = new List<char> { ' ' };
            seperators.AddRange(Environment.NewLine);
            foreach (var word in input.Split(seperators.ToArray()))
            {
                foreach (var character in word.ToCharArray())
                {
                    if (char.IsLetterOrDigit(character)) characters.Add(character);
                }

                if (characters.Count > 0)
                {
                    words.Add(string.Join("", characters).ToLowerInvariant());
                    characters.Clear();
                }
            }

            return words.ToArray();
        }

        // Final step
        public double SimilarityScore(string doc1, string doc2)
        {
            var first = GetWords(doc1);
            var second = GetWords(doc2);

            var firstFrequencies = ComputeFrequency(first);
            var secondFrequencies = ComputeFrequency(second);

            var distance = ComputeDistance(firstFrequencies, secondFrequencies);
            return distance;
        }

        // For cal doc1 only once
        public double SimilarityScore2(Dictionary<string, int> firstFrequencies, string doc2)
        {
            var second = GetWords(doc2);
            var secondFrequencies = ComputeFrequency(second);

            var distance = ComputeDistance(firstFrequencies, secondFrequencies);
            return distance;
        }
    }
}
