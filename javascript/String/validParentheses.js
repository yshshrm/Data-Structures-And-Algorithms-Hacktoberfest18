const matchingParen = {
    ')': '(',
    '}': '{',
    ']': '[',
}

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * Determine if it contains a balanced set of parentheses
 * @param {String} s string containing just the characters '(', ')', '{', '}', '[' and ']'
 * @returns {Boolean} if the parentheses are balanced
 */
function isValidParentheses(s) {
    stack = []

    for (c of s) {
        // if opening paren, push onto stack
        if ('({['.includes(c)) {
            stack.push(c)
        // if closing paren, check that matching closing paren is on the stack
        } else if (stack.length === 0 || matchingParen[c] !== stack.pop()) {
            return false;
        }
    }

    return stack.length === 0
}

console.log(isValidParentheses('()'), true);
console.log(isValidParentheses('()[]{}'), true);
console.log(isValidParentheses('(]'), false);
console.log(isValidParentheses('([)]'), false);
console.log(isValidParentheses('{[]}'), true);
