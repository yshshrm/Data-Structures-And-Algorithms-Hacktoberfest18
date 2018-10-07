-- implementation of basic algebraic operations using binary trees
data Exp = Lit Int
          |Exp :+: Exp
          |Exp :-: Exp
          |Exp :*: Exp
          |Exp :/: Exp


evalExp :: Exp -> Int -- evaluates an expression
evalExp (Lit x) = x
evalExp (x :+: y) = evalExp x + evalExp y
evalExp (x :-: y) = evalExp x - evalExp y
evalExp (x :*: y) = evalExp x * evalExp y
evalExp (x :/: y) = evalExp x `div` evalExp y

showExp :: Exp -> String --show the expression as a String
showExp (Lit x) = show x
showExp (x :+: y) = "(" ++ showExp x ++ "+" ++ showExp y ++ ")"
showExp (x :-: y) = "(" ++ showExp x ++ "-" ++ showExp y ++ ")"
showExp (x :*: y) = "(" ++ showExp x ++ "*" ++ showExp y ++ ")"
showExp (x :/: y) = "(" ++ showExp x ++ "/" ++ showExp y ++ ")"

-- example expression:
-- e0 = Lit 2 :-: Lit 3
-- e1 = (Lit 2 :+: Lit 3) :*: Lit 3
