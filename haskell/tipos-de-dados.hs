--Escreva a declaracao para o tipo Triple, contendo tres elementos, todos de tipos diferentes.
--Escreva funcoes tripleFst, tripleSnd, tripleThr para extrair respectivamente o primeiro, segundo e terceiro
-- elementos de uma triple.
data Triple a b c = Triple a b c deriving (Eq,Show)

tripleFst (Triple a _ _) = a
tripleSnd (Triple _ b _) = b
tripleThr (Triple _ _ c) = c

--Escreva um tipo Quadruple que contem 4 elementos: dois de um mesmo tipo e outros dois de outro tipo
--Escreva as funcoes frstTwo e secondTwo que retornam os dois primeiros e os dois ultimos, respectivamente
data Quadruple a b = Quadruple a a b b 

firstTwo (Quadruple a b _ _) = (a,b)
secondTwo (Quadruple _ _ c d) = (c,d)

--Escreva um tipo de dados que pode conter um, dois, tres ou quatro elementos, dependendo do construtor
--Implemente funções tuple1 até tuple4 que que retornam Just <valor> ou Nothing se o valor nao existe
data Tuple a b c d = Tuple1 a | Tuple2 a b | Tuple3 a b c | Tuple4 a b c d deriving (Eq,Show)

tuple1 (Tuple1 a) = Just a 
tuple1 (Tuple2 a _) = Just a 
tuple1 (Tuple3 a _ _) = Just a 
tuple1 (Tuple4 a _ _ _) = Just a 

tuple2 (Tuple2 _ b) = Just b 
tuple2 (Tuple3 _ b _) = Just b
tuple2 (Tuple4 _ b _ _) = Just b
tuple2 _ = Nothing

tuple3 (Tuple3 _ _ c) = Just c
tuple3 (Tuple4 _ _ c _) = Just c
tuple3 _ = Nothing

tuple4 (Tuple4 _ _ _ d) = Just d
tuple4 _ = Nothing 

data List a = Nil | Cons a (List a) deriving (Eq,Show)

listLength Nil = 0
listLength (Cons x xs) = 1 + listLength xs

listHead Nil = error "Empty list"
listHead (Cons x xs) = x

listTail Nil = Nil
listTail (Cons x xs) = xs

listFoldr f v Nil = v
listFoldr f v (Cons x xs) = f x (listFoldr f v xs)


listFoldl f v Nil = v
listFoldl f v (Cons x xs) = listFoldl f (f v x) xs 

--Escreva as funcoes sobre a estrutura de dados binary tree
data BinaryTree a = NIL | Node a (BinaryTree a) (BinaryTree a)
 deriving (Eq,Show)

sizeBST NIL = 0
sizeBST (Node a left right) = 1 + sizeBST left + sizeBST right

getValue NIL = Nothing
getValue (Node a _ _) = Just a

getLeft NIL = NIL
getLeft (Node _ left _) = left

getRight NIL = NIL
getRight (Node _ _ right) = right

getParent _ NIL = NIL
getParent x (Node a left right) | (Just x == getValue left) || (Just x == getValue right) = (Node a left right)
                                | (x < a) = getParent x left
                                | otherwise = getParent x right

--verifica se uma BT é uma BST
isBST NIL = True
isBST (Node a left right) | (getValue left /= Nothing) && (getValue left > Just a) = False
                          | (getValue right /= Nothing) && (Just a > getValue right) = False 
                          | otherwise = (isBST left) && (isBST right)

--insere uma nova chave na BST retornando a BST modificada
insert x NIL = Node x NIL NIL
insert x (Node a left right) | (x < a) = Node a (insert x left) right
                             | otherwise = Node a left (insert x right) 

--retorna o Node da BST contendo o dado procurado ou entao NIL
search x NIL = NIL
search x (Node a left right) | (x == a) = Node a left right
                             | (x < a) = search x left
                             | otherwise = search x right 

--retorna o elemento maximo da BST
myMaximum NIL = Nothing
myMaximum (Node a left right) | (right == NIL) = Just a
                              | otherwise = myMaximum right 

--retorna o elemento minimo da BST
myMinimum NIL = Nothing 
myMinimum (Node a left right) | (left == NIL) = Just a
                              | otherwise = myMinimum left

--retorna o predecessor de um elemento da BST, caso o elemento esteja na BST
predecessor x (Node a b c) | (node == NIL) = Nothing
                           | (getLeft node == NIL) = firstParentRight node bst
                           | otherwise = myMaximum (getLeft node) 
                           where
                            node = search x bst
                            bst = (Node a b c)

firstParentRight (Node x left right) (Node a b c) | (parent /= NIL) && (getLeft parent == son) = firstParentRight parent bst
                                                  | otherwise = getValue parent
                                                  where
                                                    parent = getParent x bst
                                                    son = (Node x left right)
                                                    bst = (Node a b c)

--retorna o sucessor de um elemento da BST, caso o elemento esteja na BST
successor x (Node a b c) | (node == NIL) = Nothing
                         | (getRight node == NIL) = firstParentLeft node bst
                         | otherwise = myMinimum (getRight node) 
                         where
                           node = search x bst
                           bst = (Node a b c) 

firstParentLeft (Node x left right) (Node a b c) | (parent /= NIL) && (getRight parent == son) = firstParentLeft parent bst
                                                 | otherwise = getValue parent
                                                 where
                                                   parent = getParent x bst
                                                   son = (Node x left right)
                                                   bst = (Node a b c) 

--remove um elemento da BST

-- **Auxiliar para converter Maybe em Int
toInt Nothing = 0
toInt (Just x) = x

-- **Verificar se o valor existe na árvore
remove x (Node a b c) = if (search x (Node a b c)) /= NIL then treeRemove x ((Node a b c)) else (Node a b c)

-- **Verificar se encontrou o nó a ser removido
treeRemove x (Node a left right) | (l == Just x) = treeRemoveAux left parent
                                 | (r == Just x) = treeRemoveAux right parent
                                 | (x == a) = treeRemoveAux parent NIL
                                 | (x < a) = (Node a (treeRemove x left) right)
                                 | otherwise = (Node a left (treeRemove x right))
                                 where
                                   l = getValue left
                                   r = getValue right
                                   parent = (Node a left right)
 
-- **Nó folha

treeRemoveAux (Node x NIL NIL) (Node a left right) | (getValue left == Just x) = (Node a NIL right)
                                                   | otherwise = (Node a left NIL)

-- **Nó raiz com um filho
treeRemoveAux (Node x left NIL) NIL = left
treeRemoveAux (Node x NIL right) NIL = right

-- **Nó não-raiz com um filho
treeRemoveAux (Node x y NIL) (Node a left right) | left == (Node x y NIL) = (Node a y right)
                                                 | otherwise = (Node a left y) 

treeRemoveAux (Node x NIL z) (Node a left right) | left == (Node x NIL z) = (Node a z right)
                                                 | otherwise = (Node a left z)

-- **Nó com dois filhos                                                 
treeRemoveAux (Node x y z) (Node a b c) | b == child = (Node newA (Node next (getLeft newB) (getRight newB)) newC)
                                        | otherwise = (Node newA newB (Node next (getLeft newC) (getRight newC)))
                                        where
                                          child = (Node x y z)
                                          parent = (Node a b c)
                                          next = toInt (successor x parent) 
                                          newParent = treeRemove next parent
                                          newA = toInt (getValue newParent)
                                          newB = getLeft newParent
                                          newC = getRight newParent                                       

--retorna uma lista com os dados da BST nos diversos tipos de caminhamento
preOrder NIL = []
preOrder (Node x left right) = [x] ++ (preOrder left) ++ (preOrder right) 


order NIL = []
order (Node x left right) = (order left) ++ [x] ++ (order right) 

postOrder NIL = []
postOrder (Node x left right) = (postOrder left) ++ (postOrder right) ++ [x] 
