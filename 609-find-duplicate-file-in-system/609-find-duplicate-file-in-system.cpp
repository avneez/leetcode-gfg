// So we scan the paths and store the content and the file name in the hash table.
// Then we can find the files with same content.
// We can use the stringstream to split the string.
// We can use the find function to find the position of the character.
// We can use the substr function to get the substring.


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hash;
        for (auto path : paths) {
            stringstream ss(path);
            string dir;
            string file;
            getline(ss, dir, ' ');
            while (getline(ss, file, ' ')) {
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(') - 1);
                string name = dir + '/' + file.substr(0, file.find('('));
                hash[content].push_back(name);
            }
        }
        vector<vector<string>> res;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
        return res;
    }
};