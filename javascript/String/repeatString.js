/* ES6 Ternary Operator */
const repeatString = (string, times) => {
  return times > 0 ? string.repeat(times) : "";
}
repeatString("repeated string\n", 7)

/* OUTPUT:
 * ------------------
 *  "repeated string
 *  repeated string 
 *  repeated string
 *  repeated string
 *  repeated string
 *  repeated string
 *  repeated string
 *  "
 * ------------------
 */
 
 /* Before ES6
  * ---------------------------------------
  *
  *  function repeatString(string, times) {
  *    if (times > 0) {
  *      return string.repeat(times);
  *    } else {
  *      return "";
  *    }
  *  }
  *
  * ---------------------------------------
  */
  
