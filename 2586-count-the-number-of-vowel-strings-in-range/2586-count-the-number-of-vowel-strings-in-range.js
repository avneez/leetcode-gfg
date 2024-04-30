/**
 * @param {string[]} words
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var vowelStrings = function(words, left, right) {
    const vowels = "aeiou";
    let count = 0;
    
    for(let i=left; i<=right; i++){
        word = words[i]
        if (vowels.includes(word[word.length - 1]) && vowels.includes(word[0])) {
            count++;
        }
    };
    
    return count;
};
