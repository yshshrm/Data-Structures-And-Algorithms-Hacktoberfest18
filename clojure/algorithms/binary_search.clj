(defn binary-search [number-list search-target]
  (loop [lower-boundary-index 0
        upper-boundary-index (dec (count number-list))]
    (if (> lower-boundary-index upper-boundary-index) 
      nil
      (let [middle-index (quot (+ lower-boundary-index upper-boundary-index) 2)
            middle-value (nth number-list middle-index)]
       (cond
        (< middle-value search-target) (recur (inc middle-index) upper-boundary-index)
        (> middle-value search-target) (recur lower-boundary-index (dec middle-index))
        (= middle-value search-target) middle-index)))))