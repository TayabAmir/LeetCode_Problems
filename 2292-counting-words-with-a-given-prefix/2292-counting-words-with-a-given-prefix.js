/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    let count = 0;
    words.forEach((w) => {
        if(w.startsWith(pref)) count++;
    })
    return count
};