const isEqual = (firstObj, secondObj) => {
    if (firstObj === secondObj) return true;
    if (firstObj instanceof Date && secondObj instanceof Date) return firstObj.getTime() === secondObj.getTime();
    if (!firstObj || !secondObj || (typeof firstObj !== 'object' && typeof secondObj !== 'object')) return firstObj === secondObj;
    if (firstObj === null || firstObj === undefined || secondObj === null || secondObj === undefined) return false;
    if (firstObj.prototype !== secondObj.prototype) return false;
    let keys = Object.keys(firstObj);
    if (keys.length !== Object.keys(secondObj).length) return false;
    return keys.every(k => isEqual(firstObj[k], secondObj[k]));
  };