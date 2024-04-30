/**
 * @param {string[]} words
 * @param {number[][]} queries
 * @return {number[]}
 */
var vowelStrings = function(words, queries) {
    const vowels = "aeiou";
    const n = words.length;
    
    const prefixCounts = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        let word = words[i-1]
        prefixCounts[i] = prefixCounts[i - 1] + (vowels.includes(word[0]) && vowels.includes(word[word.length - 1]) ? 1 : 0);
    }
    
    const getCountInRange = (left, right) => {
        return prefixCounts[right + 1] - prefixCounts[left];
    };
    
    const ans = [];
    for (const [l, r] of queries) {
        ans.push(getCountInRange(l, r));
    }
    
    return ans;
};
