(declare binary-chop index-at-half finished? found? too-small?)

(def NOT_FOUND -1)

(defn binary-search
  "Tries to find the needle in the haystack. Returns the
   index of the sought-after element in the haystack,
   otherwise -1."
  [needle haystack]
  (if (empty? haystack)
    NOT_FOUND
    (binary-chop needle haystack 0 (- (count haystack) 1))))

(defn- binary-chop [needle haystack lower-index upper-index]
  (let [mid-index (index-at-half lower-index upper-index)
        element   (nth haystack mid-index)]
    (letfn [(finished?  [] (> lower-index upper-index))
            (found?     [] (= element needle))
            (too-small? [] (< element needle))
            (search-lower [] (binary-chop needle haystack lower-index (- mid-index 1)))
            (search-upper [] (binary-chop needle haystack (+ mid-index 1) upper-index))]
      (cond
        (finished?) NOT_FOUND
        (found?) mid-index
        (too-small?) (search-upper)
        :else (search-lower)))))

(defn- index-at-half [lower-index upper-index]
  (quot (+ lower-index upper-index) 2))
