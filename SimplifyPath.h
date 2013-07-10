class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string r = "/";
        string item = "";
        for (int i=1; i<path.size(); i++) {
            if (path[i] == '/') {
                r = this->dealwithPathItem(r, item);
                item = "";
            } else {
                item.append(1, path[i]);
            }
        }

        if (item == ".." || item == ".") {
            r = this->dealwithPathItem(r, item);
            item = "";
        }

        if (r == "/") {
            return r + item;
        }

        return item == ""? r: r + "/" + item;
    }

    string dealwithPathItem(string r, string item) {
        if (item == "..") {
            if (r == "/") {
                return r;
            }
            int pos = r.find_last_of("/");
            return pos > 0? r.substr(0, pos): "/";
        } else if (item == "." || item == "") {

        } else {
            if (r == "/") {
                r += item;
            } else {
                r += "/" + item;
            }
        }

        return r;
    }
};
