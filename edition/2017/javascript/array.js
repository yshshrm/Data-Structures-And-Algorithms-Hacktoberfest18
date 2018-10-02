
//++++ Implement array data structure in javascript++++


function this_array() {
  this.array = [];
}

this_array.prototype.add = function(data) {
  this.array.push(data);
};
this_array.prototype.remove = function(data) {
  this.array = this.array.filter(function(current) {
    return current !== data;
  });
};
this_array.prototype.search = function(data) {
  var foundIndex = this.array.indexOf(data);
  if(~foundIndex) {
    return foundIndex;
  }

  return null;
};
this_array.prototype.getAtIndex = function(index) {
  return this.array[index];
};
this_array.prototype.length = function() {
  return this.array.length;
};
this_array.prototype.print = function() {
  console.log(this.array.join(' '));
};

var array = new this_array();
array.add(1);
array.add(2);
array.add(3);
array.add(4);
array.print(); // => 1 2 3 4
console.log('search 3 gives index 2:', array.search(3)); // => 2
console.log('getAtIndex 2 gives 3:', array.getAtIndex(2)); // => 3
console.log('length is 4:', array.length()); // => 4
array.remove(3);
array.print(); // => 1 2 4
array.add(5);
array.add(5);
array.print(); // => 1 2 4 5 5
array.remove(5);
array.print(); // => 1 2 4
