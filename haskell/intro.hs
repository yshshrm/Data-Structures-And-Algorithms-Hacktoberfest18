{-
- Usando os predicados not, and e or prontos de Haskell, implemente os predicados (funcoes) xor (or exclusivo),
- impl (implicacao A => B é equivalente a (not A or B)) e equiv (A <=> B é definido como A => B and B => A)
- Procure usar casamento de padroes e reutilizar as funcoes.
-}
xor :: Bool -> Bool -> Bool
xor a b = (a && (not b)) || ((not a) && b)

impl :: Bool -> Bool -> Bool
impl a b = (not a) || b

equiv :: Bool -> Bool -> Bool
equiv a b = (impl a b) && (impl b a)

{-
A funcao square esta implementada e eleva ao quadrado um determinado numero
-}

square :: Integer -> Integer
square x = x * x

{-
- Implemente a funcao potencia, que retorna o resultado de x elevado a y
-}

pow :: Float -> Float -> Float
pow x 0 = 1
pow x 1 = x
pow x y | (y > 1) = x * pow x (y-1)
        | (y < 0) = 1/(pow x (-y))

{-
- Implemente a funcao fatorial que calcula o fatorial de um numero
-}

fatorial :: Int -> Int
fatorial 0 = 1
fatorial x = x * fatorial (x-1)

{-
- Determina se um numero eh primo ou nao. Preocupe-se apenas em resolver o problema.
- Nao precisa usar conhecimentos mais sofisticados da teoria dos numeros. Voce pode trabalhar com listas.
-}

isPrime :: Integer -> Bool
isPrime 1 = True
isPrime x = ([1, x] == dividers)
  where
    dividers = [y | y <- [1..x], (x `mod` y == 0)]


{-
- Calcula um termo da sequencia de Fibonnacci. Voce pode trabalhar com listas.
-}

fib :: Integer -> Integer
fib 1 = 1
fib 2 = 1
fib x = fib (x-1) + fib (x-2)

{-
- Calcula um MDC de dois numeros usando o algoritmo de Euclides.
-}

mdc :: Integer -> Integer -> Integer
mdc x 0 = x
mdc 0 y = y
mdc x y | (x > y) = mdc (x-y) y
        | otherwise = mdc x (y-x)

{-
- Calcula um MMC de dois numeros.
-}

mmc :: Integer -> Integer -> Integer
mmc x y = head multiples
        where
          multiples = [z | z <- [(max x y)..(x*y)], (z `mod` x) == 0, (z `mod` y) == 0]

{-
- Determina se dois numeros inteiros positivos sao co-primos. Dois numeros sao co-primos se
- o mdc deles for igual a 1. Ex: coprimo 35 64 = True
-}

coprimo :: Integer -> Integer -> Bool
coprimo x y = (mdc x y == 1)

{-
- Calcula a conjectura de Goldbach, que diz que um numero par maior que 2 pode ser escrito como a soma de dois numeros primos. Ex: 28 = 5 + 23.
-}

goldbach :: Integer -> (Integer, Integer)
goldbach x = head adders
            where
              adders = [(a,b) | a <- [1..x], b <- [1..x], isPrime a, isPrime b, a + b == x]
