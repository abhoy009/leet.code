/**
 * @param {number} x
 * @return {boolean}
 */
function isPalindrome(x) {
    if (x < 0) return false;
    let original = x;
    let reverse = 0;
    
    while (x > 0) {
        reverse = reverse * 10 + x % 10;
        x = Math.floor(x / 10);
    }
    
    return reverse === original;
}