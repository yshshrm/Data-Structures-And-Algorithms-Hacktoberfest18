using System;
using System.Collections.Generic;

public class Trie
{
    private class TrieNode
    {
        public TrieNode(char value, bool isWord)
        {
            this.Value = value;
            this.IsWord = isWord;
            this.Children = new Dictionary<char, TrieNode>();

            if (isWord)
            {
                this.Count = 1;
            }
            else
            {
                this.Count = 0;
            }
        }

        public TrieNode(char value)
            : this(value, false)
        {
        }

        public TrieNode(bool isWord)
            : this(' ', isWord)
        {
        }

        public char Value { get; private set; }

        public bool IsWord { get; private set; }

        public int Count { get; private set; }

        public Dictionary<char, TrieNode> Children { get; set; }

        public void AddChild(char value, bool isWord)
        {
            if (this.Children.ContainsKey(value))
            {
                if (isWord)
                {
                    this.Children[value].IsWord = true;
                    this.Children[value].Count++;
                }
            }
            else
            {
                this.Children.Add(value, new TrieNode(value, isWord));
            }
        }
    }

    private const char RootSymbol = '\0';
    private readonly char[] Separators = { ' ', ',', '!', '.', ',', '?', '-', '\r', '\n' };

    private TrieNode root;

    public Trie()
    {
        this.root = new TrieNode(RootSymbol, false);
    }

    public void BuildTrie(string text)
    {
        var wordsInText = text.Split(Separators, StringSplitOptions.RemoveEmptyEntries);

        foreach (var word in wordsInText)
        {
            this.AddWord(word.ToLower());
        }
    }

    public void AddWord(string word)
    {
        var currentNode = this.root;

        bool isWord = false;

        for (int i = 0; i < word.Length; i++)
        {
            if (i == word.Length - 1)
            {
                isWord = true;
            }

            currentNode.AddChild(word[i], isWord);

            currentNode = currentNode.Children[word[i]];
        }
    }

    public int GetWordOccurences(string word)
    {
        var currentNode = this.root;
        string wordToLower = word.ToLower();

        for (int i = 0; i < wordToLower.Length; i++)
        {
            if (!currentNode.Children.ContainsKey(wordToLower[i]))
            {
                return -1;
            }

            currentNode = currentNode.Children[wordToLower[i]];

            if (i == wordToLower.Length - 1 && currentNode.IsWord)
            {
                return currentNode.Count;
            }
        }

        return -1;
    }

    public bool ContainsWord(string word)
    {
        if (this.GetWordOccurences(word) == -1)
        {
            return false;
        }

        return true;
    }
}
