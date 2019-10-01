package main

// trieNode saves trie structure
type trieNode struct {
	childMap map[rune]*trieNode
	isEnd    bool
}

// PrefixDictionary class for dictionary
type PrefixDictionary struct {
	root      *trieNode
	wordCount int
}

// NewPrefixDictionary init function
func NewPrefixDictionary() *PrefixDictionary {
	return &PrefixDictionary{
		root: &trieNode{
			childMap: map[rune]*trieNode{},
			isEnd:    false,
		},
		wordCount: 0,
	}
}

// Size returns size of dictionary
func (pr *PrefixDictionary) Size() int {
	return pr.wordCount
}

// Insert inserts new word in dictionary
// returns false if this word already present
func (pr *PrefixDictionary) Insert(word string) bool {
	node := pr.root
	for _, ch := range word {
		if newNode, ok := node.childMap[ch]; ok {
			node = newNode
		} else {
			node.childMap[ch] = &trieNode{
				childMap: map[rune]*trieNode{},
				isEnd:    false,
			}
			node = node.childMap[ch]
		}
	}
	if node.isEnd {
		return false
	}
	node.isEnd = true
	pr.wordCount++
	return true
}

func allChild(prefix string, node *trieNode) []string {
	if node == nil {
		return []string{}
	}
	var res []string
	for ch, childNode := range node.childMap {
		newStr := prefix + string(ch)
		if childNode.isEnd {
			res = append(res, newStr)
		}
		res = append(res, allChild(newStr, childNode)...)
	}
	return res
}

// Retrieve retrieves all words in dictionary with given prefix
func (pr *PrefixDictionary) Retrieve(prefix string) []string {
	node := pr.root
	for _, ch := range prefix {
		if newNode, ok := node.childMap[ch]; ok {
			node = newNode
		} else {
			return []string{}
		}
	}
	return allChild(prefix, node)
}
