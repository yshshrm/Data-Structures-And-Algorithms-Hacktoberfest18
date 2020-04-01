function palindrome(str) {
  let arr = str.split('');

  //reverse arr now that it is split
  let reversed = arr.reverse();

  //join the individual letters back into a single string
  let joined = reversed.join('');

  //remove special characters //dont forget g after trailing slash
  let simpleRev = joined
    .replace(/[&\/\\#,+()$~%'":*?<>{}|]/g, '')
    .replace(/_|\-|\./g, '')
    .replace(/\s+/g, '');

  let simpleFwd = str
    .replace(/[&\/\\#,+()$~%'":*?<>{}|]/g, '')
    .replace(/_|\-|\./g, '')
    .replace(/\s+/g, '');

  //compare simpleFwd in lowercase to simpleRev in lowercase
  if (simpleFwd.toLowerCase() == simpleRev.toLowerCase()) {
    return true;
  }
  return false;
}

palindrome('eye');
