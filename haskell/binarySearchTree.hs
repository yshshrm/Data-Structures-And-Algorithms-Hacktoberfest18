import Data.List

data BST a = BSTNod a (BST a) (BST a) | BSTNil deriving Show -- a binary search tree, having a node with maximum 2 children, BSTNil represents a null node from BST

-- transforming a list in BST
makeBST :: Ord a => [a] -> BST a
makeBST [] = BSTNil
makeBST listing = BSTNod root (makeBST left) (makeBST right) where
                        sorted = sort listing
                        len = length sorted
                        root = sorted !! (div len 2)
                        left = take (div len 2) sorted
                        right = drop ((div len 2) + 1) sorted

-- searching an element in a given BST
findElem :: (Ord a, Eq a) => a -> BST a -> Maybe a
findElem elem BSTNil = Nothing
findElem elem (BSTNod root left right) 
        | root == elem = Just elem
        | root > elem = findElem elem left
        | root < elem = findElem elem right

-- inorder tree traversal
inorder :: BST a -> [a]
inorder BSTNil = []
inorder (BSTNod root left right) = (inorder left) ++ [root] ++ (inorder right)

-- preorder tree traversal
preorder :: BST a -> [a]
preorder BSTNil = []
preorder (BSTNod root left right) = [root] ++ (preorder left) ++ (preorder right)

-- postorder tree traversal
postorder :: BST a -> [a]
postorder BSTNil = []
postorder (BSTNod root left right) = (postorder left) ++ (postorder right) ++ [root]

-- insert element in BST
insertElem :: Ord a => BST a -> a -> BST a
insertElem BSTNil a = makeBST [a]
insertElem (BSTNod root left right) a = makeBST (sort (postorder (BSTNod root left right)) ++ [a])

-- remove element from BST
removeElem :: Ord a => BST a -> a -> BST a
removeElem BSTNil a = BSTNil
removeElem (BSTNod root left right) a = makeBST (sort (delete a (postorder (BSTNod root left right))))

-- lowest common ancestor between given 2 nodes in a BST
lowestCommonAncestor :: (Ord a, Eq a) => BST a -> a -> a -> Maybe a
lowestCommonAncestor BSTNil n1 n2 = Nothing
lowestCommonAncestor (BSTNod root left right) n1 n2
                    | findElem n1 (BSTNod root left right) == Nothing || findElem n2 (BSTNod root left right) == Nothing = Nothing
                    | root > n1 && root > n2 = lowestCommonAncestor left n1 n2
                    | root < n1 && root < n2 = lowestCommonAncestor right n1 n2
                    | otherwise = Just root

-- distance from the root of a BST and a node, helper function for nodesDistance
rootDistance :: (Ord a, Eq a) => BST a -> a -> Int
rootDistance BSTNil elem = 0
rootDistance (BSTNod root left right) elem
              | elem == root = 0
              | root > elem = 1 + rootDistance left elem
              | otherwise= 1 + rootDistance right elem
                    
-- distance between 2 nodes in a BST
nodesDistance :: (Ord a, Eq a) => BST a -> a -> a-> Maybe Int
nodesDistance BSTNil n1 n2 = Nothing
nodesDistance (BSTNod root left right) n1 n2 
            | findElem n1 (BSTNod root left right) == Nothing || findElem n2 (BSTNod root left right) == Nothing = Nothing
            | root > n1 && root > n2 = nodesDistance left n1 n2
            | root < n1 && root < n2 = nodesDistance right n1 n2
            | otherwise = Just ((rootDistance (BSTNod root left right) n1) + (rootDistance (BSTNod root left right) n2))