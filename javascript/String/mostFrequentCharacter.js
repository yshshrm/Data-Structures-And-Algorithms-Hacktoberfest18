function mostFrequentChar(str) {
  const hash = {};
  str.split('').forEach(function(c) {
    if (!hash[c]){
      hash[c] = 0;
    }
    hash[c]+=1;
  });
  // console.log(hash);

  // sort
  const sorted = Object.entries(hash).sort(function(a,b)
    {
      return b[1]-a[1];
    }
  );

// highest is first
  return sorted[0][0];
}

//test
// console.log(mostFrequentChar("lenny"));
