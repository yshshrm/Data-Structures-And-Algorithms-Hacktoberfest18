import java.util.HashMap;
import java.util.Map;

public class Trie {
	class TrieNode {
	    public char value; 
	    public Map<Character, TrieNode> children; 
	    public boolean isLeaf; 
	    
	    public TrieNode(){
	        isLeaf = false; 
	        children = new HashMap<Character, TrieNode>();    
	    }
	    
	    public TrieNode(char value){
	        isLeaf = false; 
	        children = new HashMap<Character, TrieNode>();  
	        this.value = value; 
	    }  
	}
	
	TrieNode root; 
	
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode(); 
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        char[] toks = word.toCharArray(); 
        TrieNode curr = root; 
        for(int i = 0; i < toks.length; i++){
            if(!curr.children.containsKey(toks[i])) curr.children.put(toks[i], new TrieNode(toks[i])); 
            curr = curr.children.get(toks[i]); 
        }
        curr.isLeaf = true; 
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        char[] toks = word.toCharArray(); 
        TrieNode curr = root; 
        for(int i = 0; i < toks.length; i++){
            if(!curr.children.containsKey(toks[i])) return false; 
            curr = curr.children.get(toks[i]);
        }
        return curr.isLeaf; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        char[] toks = prefix.toCharArray(); 
        TrieNode curr = root; 
        for(int i = 0; i < toks.length; i++){
            if(!curr.children.containsKey(toks[i])) return false; 
            curr = curr.children.get(toks[i]); 
        }
        return curr.children.size() != 0 || curr.isLeaf; 
    }
}
