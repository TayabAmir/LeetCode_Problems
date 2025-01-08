/**
 * @param {string[]} words
 * @return {number}
 */
function isPrefixAndSuffix(s, t){
    return s.startsWith(t) && s.endsWith(t);
}

var countPrefixSuffixPairs = function(words) {
    let count = 0;
    for(let i = 0; i < words.length; i++)
        for(let j = i + 1; j < words.length; j++)
            if(isPrefixAndSuffix(words[j], words[i]))
                count++;
    return count;
};